#ifndef PINBALLV05B0001_H
#define PINBALLV05B0001_H

#include <QtWidgets/QMainWindow>
class QGraphicsScene;
class QGraphicsView;
class LogicController;
class QGridLayout;
class QMediaPlayer;
class DB_Utils;
class Player;

class PinBallv05b0001 : public QMainWindow
{
	Q_OBJECT

public:
	PinBallv05b0001(QWidget *parent = Q_NULLPTR);
	~PinBallv05b0001();

	double xMouse, yMouse, zMouse;
	void GameOver();//一局游戏结束保存游戏信息及显示结果

private slots:
	void loginPage();//登录界面
	void signIn();//签入
	void createMenu();//创建菜单
	void returnMenu();
	//void initEndlessGame();//无尽模式
	void about();//版本信息
	void toggleDebugMode();//切换调试模式开关
	void initGameMenu();//进入开始游戏菜单
	void initFastMode();//极简模式开始
	void initItemMode();//道具模式开始
	void initCthulhuMode();//鲲模式/克苏鲁模式
	void setting();//进入设置
	void settingBackMenu();//由设置返回菜单
	void gallery();//进入画廊
	void Wardrobe();//menu-gallery-skinmenu
	void AchivementPage();//成就 menu-gallery-achivementPage

	void destroyMenuChildButtons();//销毁每个menu下的按钮控件以便形成新按钮控件
	void destroyMenuChildLabels();//销毁每个menu下的标签控件以便布局管理器腾出空间
	void destroyMenuChildEdit();//删除文本框子控件
	void setBGMVolume(int volume = 0);//设置BGM音量，默认0
	void toggleBGM();//切换BGM静音状态
	void playReturnButtonSE();//退回按钮音效播放
	void playStepButtonSE();//步进按钮音效播放

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void keyReleaseEvent(QKeyEvent *event);

private:

	//开始游戏初始化scene
	void initScene();

	QGraphicsScene *scene;
	QGraphicsView *view;
	LogicController *baseController;

	//Flags
	bool isDebug;

	//location
	QPoint windowPos;
	QPoint dPos;

	//layout排版
	QGridLayout *layout;

	//音频播放器
	QMediaPlayer *bgmController;
	QMediaPlayer *soundController;
	bool isBGMmute;
	int volume;

	//数据库连接
	DB_Utils *db_utils;

	//玩家信息
	Player *currentPlayer;
	
};
#endif // !PINBALLV05B0001_H
