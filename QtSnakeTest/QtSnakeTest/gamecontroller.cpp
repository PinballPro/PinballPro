#include <QEvent>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>

#include"gamecontroller.h"
#include"food.h"
#include"snake.h"


GameController::GameController(QGraphicsScene &scene, QObject *parent) :
	QObject(parent),
	scene(scene),
	snake(new Snake(*this)),
	isPause(false)
{	
	//30֡
	timer.start(1000 / 33);

	Food *a1 = new Food(0, -50);
	scene.addItem(a1);

	scene.addItem(snake);

	//��װ�¼�������
	scene.installEventFilter(this);

	resume();
}

GameController::~GameController() {

}

void GameController::snakeAteFood(Food *food) {
	scene.removeItem(food);

	addNewFood();
}

void GameController::snakeAteItself() {
	QTimer::singleShot(0, this, SLOT(gameOver()));
}

void GameController::handleKeyPressed(QKeyEvent *event) {
	if (!isPause)
		switch (event->key()) {
		case Qt::Key_Left:
			snake->setMoveDirection(Snake::MoveLeft);
			break;
		case Qt::Key_Right:
			snake->setMoveDirection(Snake::MoveRight);
			break;
		case Qt::Key_Up:
			snake->setMoveDirection(Snake::MoveUp);
			break;
		case Qt::Key_Down:
			snake->setMoveDirection(Snake::MoveDown);
			break;
		case Qt::Key_Space:
			pause();
			break;
		}
	else resume();
}

void GameController::addNewFood() {
	int x, y;
	do {
		x = (int)(qrand() % 200) / 10 - 10;
		y = (int)(qrand() % 200) / 10 - 10;
		x *= 10;
		y *= 10;
	} while (snake->shape().contains(snake->mapFromScene(QPointF(x + 5, y + 5))));
	Food *food = new Food(x, y);
	scene.addItem(food);
}

void GameController::pause() {
	//�Ͽ���ʱ���ź�,�γ���ͣЧ��(��ʱ��ֹͣ���ۺ���advanceֹͣ����)
	disconnect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	isPause = true;
}

void GameController::resume() {
	//���Ӷ�ʱ���ź�
	connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	isPause = false;
}

void GameController::gameOver() {
	//�Ͽ��붨ʱ��������
	disconnect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	if (QMessageBox::Yes == QMessageBox::information(NULL,
		tr("Game Over"), tr("Again?"),
		QMessageBox::Yes | QMessageBox::No,
		QMessageBox::Yes)) {
		//ѡ������������Ӷ�ʱ��
		connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
		scene.clear();

		snake = new Snake(*this);
		scene.addItem(snake);
		addNewFood();
	}
	else {
		exit(0);
	}
}

bool GameController::eventFilter(QObject *object, QEvent *event) {
	if (event->type() == QEvent::KeyPress) {
		//���˼����¼��������º����ж�
		handleKeyPressed((QKeyEvent *)event);
		return true;
	}
	else {
		//�����¼��ַ�������QObject��ȫ���¼�������
		return QObject::eventFilter(object, event);
	}
}