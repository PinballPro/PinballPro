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
	//void initEndlessGame();//无尽模式
	void about();//版本信息
	void gallery();//进入画廊
	void setting();//进入设置
	void toggleDebugMode();//切换调试模式开关
	void initGameMenu();//进入开始游戏菜单
	void createMenu();//创建菜单
	void destroyMenuChildButtons();//销毁每个menu下的按钮控件以便形成新按钮控件

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

	//layout排版
	QGridLayout *layout;
};
#endif // !PINBALLV05B0001_H
