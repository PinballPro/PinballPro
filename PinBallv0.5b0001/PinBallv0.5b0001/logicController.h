#ifndef LOGICCONTROLLER_H
#define LOGICCONTROLLER_H

#include<QObject>
#include<QTimer>
#include<QMainWindow>
class QGraphicsScene;
class QKeyEvent;
class QMouseEvent;
class PinBallv5b0001;
class Ball;
class Brick;

class LogicController : public QObject {
	Q_OBJECT
public:
	QGraphicsScene &scene;

	LogicController(QGraphicsScene &scene, QObject *parent = Q_NULLPTR);
	~LogicController();
	int ballNumber = 1;
	int brickNumber;
	int round = 1;
	double dx = 0, dy = 0;
	int ballCountPerRound = 0;
	int score = 0;
	bool isWait;
	void roundover(Ball *ball);
	void startFastMode();//开始极简模式游戏循环
	void startItemMode();//开启道具模式游戏循环
	void startKunMode();//开启鲲模式游戏循环
	void changeDxDy();//改变方向并继续刷新

	void removeBrick(Brick *);//删除砖块
	bool isInGame;
public slots:
	void pause();
	void resume();
	void roundOver();
	void returnMenu();
protected:
	bool eventFilter(QObject *object, QEvent *event);//事件过滤器，过滤鼠标与键盘事件
private:
	void handleKeyEvent(QKeyEvent *keyEvent);
	void handleMouseEvent(QMouseEvent *mouseEvent);

	QTimer timer;

	bool isPause;
};

#endif // !LOGICCONTROLLER_H
