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
	void startFastMode();//��ʼ����ģʽ��Ϸѭ��
	void startItemMode();//��������ģʽ��Ϸѭ��
	void startKunMode();//������ģʽ��Ϸѭ��
	void changeDxDy();//�ı䷽�򲢼���ˢ��

	void removeBrick(Brick *);//ɾ��ש��
	bool isInGame;
public slots:
	void pause();
	void resume();
	void roundOver();
	void returnMenu();
protected:
	bool eventFilter(QObject *object, QEvent *event);//�¼����������������������¼�
private:
	void handleKeyEvent(QKeyEvent *keyEvent);
	void handleMouseEvent(QMouseEvent *mouseEvent);

	QTimer timer;

	bool isPause;
};

#endif // !LOGICCONTROLLER_H
