#include"LogicController.h"
#include<QGraphicsScene>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QMainWindow>
#include<QStatusBar>
#include<QTime>
#include<QRandomGenerator>
#include"PinBallv05b0001.h"
#include"constants.h"
#include"ball.h"
#include"brick.h"

LogicController::LogicController(QGraphicsScene &scene, QObject *parent)	:
	QObject(parent),
	scene(scene),
	isPause(false),
	isInGame(false)
{
}

LogicController::~LogicController(){}

void LogicController::startFastMode() {
	isInGame = true;
	isWait = true;
	//生成初始砖块第一行随机1-10个
	qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 1000);
	int a[10] = {0};
	int counter = 0;
	for (int i = 0;i < 10;i++) {
		a[i] = qrand() % 2;
		if (a[i] == 1) {
			Brick *brick = new Brick(-250 + 50 * i, -380, GO_Normal, QColor(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256)));
			scene.addItem(brick);
			counter++;
		}
	}
	brickNumber = counter;
	
	scene.installEventFilter(this);//安装事件过滤器
	timer.start(1000 / 50);
}

void LogicController::removeBrick(Brick *brick) {
	scene.removeItem(brick);
}

void LogicController::startItemMode() {

}

void LogicController::startKunMode() {

}

void LogicController::pause(){
	disconnect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	isPause = true;
	isWait = true;
}

void LogicController::resume(){
	connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
	isPause = false;
	isWait = false;
}

void LogicController::roundOver() {
	ballCountPerRound = 0;
	round++;
	ballNumber++;
	QList<QGraphicsItem *> items = scene.items();
	QList<Brick *> bricks;
	//保存以前的未打碎砖块
	foreach(QGraphicsItem *item, items) {
		if (!item->data(GD_Type).isNull()) {
			bricks.append(new Brick((Brick *)item));
		}
	}
	scene.clear();
	//每三回合新增砖块
	//生成初始砖块第一行随机1-10个
	if (ballNumber % 3 == 0) {
		qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 1000);
		int a[10] = { 0 };
		int counter = 0;
		for (int i = 0;i < 10;i++) {
			a[i] = qrand() % 2;
			if (a[i] == 1) {
				Brick *brick = new Brick(-250 + 50 * i, -380, GO_Normal, QColor(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256)));
				bricks.append(brick);
				counter++;
			}
		}
	}

	foreach(Brick *brick, bricks) {
		int newy = brick->y() + 60;
		if (newy >= 360) {
			((PinBallv05b0001 *)this->parent())->GameOver();
			return;
		}

		int newx = brick->x();
		brick->setPos(newx, newy);
		scene.addItem(brick);
	}

	this->pause();
}

void LogicController::changeDxDy() {
	for (int i = 0;i < ballNumber;++i) {
		Ball *ball = new Ball(*this);
		ball->setPos(0, 400+20*i);
		ball->addx = dx;
		ball->addy = dy;
		scene.addItem(ball);
	}
	resume();
}

void LogicController::roundover(Ball *ball) {
	QTimer::singleShot(0, this, SLOT(roundOver()));
}

void LogicController::returnMenu(){}



bool LogicController::eventFilter(QObject *object, QEvent *event) {
		//其他事件分发给基类QObject的全局事件过滤器
		return QObject::eventFilter(object, event);
}

void LogicController::handleKeyEvent(QKeyEvent *event) {

}

void LogicController::handleMouseEvent(QMouseEvent *event) {

}


