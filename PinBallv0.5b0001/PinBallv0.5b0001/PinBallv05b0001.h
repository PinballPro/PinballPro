#ifndef PINBALLV05B0001_H
#define PINBALLV05B0001_H

#include <QtWidgets/QMainWindow>
class QGraphicsScene;
class QGraphicsView;
class LogicController;
class QGridLayout;

class PinBallv05b0001 : public QMainWindow
{
	Q_OBJECT

public:
	PinBallv05b0001(QWidget *parent = Q_NULLPTR);
	~PinBallv05b0001();

private slots:
	void returnMenu();
	//void initEndlessGame();//�޾�ģʽ
	void about();//�汾��Ϣ
	void gallery();//���뻭��
	void setting();//��������
	void toggleDebugMode();//�л�����ģʽ����
	void initGameMenu();//���뿪ʼ��Ϸ�˵�
	void createMenu();//�����˵�
	void destroyMenuChildButtons();//����ÿ��menu�µİ�ť�ؼ��Ա��γ��°�ť�ؼ�

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

private:

	QGraphicsScene *scene;
	QGraphicsView *view;
	LogicController *baseController;

	//Actions
	QAction *pauseAction;
	QAction *resumeAction;
	QAction *exitAction;
	QAction *aboutAciton;

	//Flags
	bool isDebug;

	//location
	QPoint windowPos;
	QPoint dPos;

	//layout�Ű�
	QGridLayout *layout;
};
#endif // !PINBALLV05B0001_H
