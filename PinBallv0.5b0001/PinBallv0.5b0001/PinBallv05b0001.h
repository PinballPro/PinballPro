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

private slots:
	void loginPage();//��¼����
	void signIn();//ǩ��
	void createMenu();//�����˵�
	void returnMenu();
	//void initEndlessGame();//�޾�ģʽ
	void about();//�汾��Ϣ
	void toggleDebugMode();//�л�����ģʽ����
	void initGameMenu();//���뿪ʼ��Ϸ�˵�
	void initFastMode();//����ģʽ��ʼ
	void initItemMode();//����ģʽ��ʼ
	void initCthulhuMode();//��ģʽ/����³ģʽ
	void setting();//��������
	void settingBackMenu();//�����÷��ز˵�
	void gallery();//���뻭��
	void Wardrobe();//menu-gallery-skinmenu
	void AchivementPage();//�ɾ� menu-gallery-achivementPage

	void destroyMenuChildButtons();//����ÿ��menu�µİ�ť�ؼ��Ա��γ��°�ť�ؼ�
	void destroyMenuChildLabels();//����ÿ��menu�µı�ǩ�ؼ��Ա㲼�ֹ������ڳ��ռ�
	void destroyMenuChildEdit();//ɾ���ı����ӿؼ�
	void setBGMVolume(int volume = 0);//����BGM������Ĭ��0
	void toggleBGM();//�л�BGM����״̬
	void playReturnButtonSE();//�˻ذ�ť��Ч����
	void playStepButtonSE();//������ť��Ч����

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

	//��Ƶ������
	QMediaPlayer *bgmController;
	QMediaPlayer *soundController;
	bool isBGMmute;
	int volume;

	//���ݿ�����
	DB_Utils *db_utils;

	//�����Ϣ
	Player *currentPlayer;
	
};
#endif // !PINBALLV05B0001_H
