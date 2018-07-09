#ifndef LOGICCONTROLLER_H
#define LOGICCONTROLLER_H

#include<QObject>
#include<QTimer>
#include<QMainWindow>
class QGraphicsScene;
class QKeyEvent;
class QMouseEvent;
class PinBallv5b0001;

class LogicController : public QObject {
	Q_OBJECT
public:
	LogicController(QGraphicsScene &scene, QObject *parent = Q_NULLPTR);
	~LogicController();
public slots:
	void pause();
	void resume();
	void returnMenu();
protected:
	bool eventFilter(QObject *object, QEvent *event);//事件过滤器，过滤鼠标与键盘事件
private:
	void handleKeyEvent(QKeyEvent *keyEvent);
	void handleMouseEvent(QMouseEvent *mouseEvent);

	QGraphicsScene &scene;
	QTimer timer;

	bool isPause;
};

#endif // !LOGICCONTROLLER_H
