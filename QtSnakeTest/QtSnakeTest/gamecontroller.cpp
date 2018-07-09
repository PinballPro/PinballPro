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
	//30帧
	timer.start(1000 / 33);

	Food *a1 = new Food(0, -50);
	scene.addItem(a1);

	scene.addItem(snake);

	//安装事件过滤器
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
	//断开定时器信号,形成暂停效果(定时器停止，槽函数advance停止调用)
	disconnect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	isPause = true;
}

void GameController::resume() {
	//连接定时器信号
	connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	isPause = false;
}

void GameController::gameOver() {
	//断开与定时器的连接
	disconnect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	if (QMessageBox::Yes == QMessageBox::information(NULL,
		tr("Game Over"), tr("Again?"),
		QMessageBox::Yes | QMessageBox::No,
		QMessageBox::Yes)) {
		//选择继续重新连接定时器
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
		//过滤键盘事件交由以下函数判断
		handleKeyPressed((QKeyEvent *)event);
		return true;
	}
	else {
		//其他事件分发给基类QObject的全局事件过滤器
		return QObject::eventFilter(object, event);
	}
}