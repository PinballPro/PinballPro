#include"LogicController.h"
#include<QGraphicsScene>
#include<QKeyEvent>
#include<QMouseEvent>
#include<QMainWindow>
#include<QStatusBar>
#include"PinBallv05b0001.h"

LogicController::LogicController(QGraphicsScene &scene, QObject *parent)	:
	QObject(parent),
	scene(scene),
	isPause(false)
{
	scene.installEventFilter(this);//��װ�¼�������
}

LogicController::~LogicController(){}

void LogicController::pause(){}

void LogicController::resume(){}

void LogicController::returnMenu(){}



bool LogicController::eventFilter(QObject *object, QEvent *event) {
	if (event->type() == QEvent::KeyPress) {
		handleKeyEvent((QKeyEvent *)event);
		return true;
	}
	else if (event->type() == QEvent::GrabMouse) {
		handleMouseEvent((QMouseEvent *)event);
		return true;
	}
	else {
		//�����¼��ַ�������QObject��ȫ���¼�������
		return QObject::eventFilter(object, event);
	}

}

void LogicController::handleKeyEvent(QKeyEvent *event) {

}

void LogicController::handleMouseEvent(QMouseEvent *event) {

}
