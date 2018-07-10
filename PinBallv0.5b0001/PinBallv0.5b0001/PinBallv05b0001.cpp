#include<QGraphicsView>
#include<QGraphicsScene>
#include<QLabel>
#include<QMainWindow>
#include<QStatusBar>
#include<QGridLayout>
#include<QToolButton>
#include<QMessageBox>
#include<QMouseEvent>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include"logicController.h"
#include "PinBallv05b0001.h"
PinBallv05b0001::PinBallv05b0001(QWidget *parent)
	: QMainWindow(parent),
	scene(new QGraphicsScene(this)),
	view(new QGraphicsView(scene, this)),
	baseController(new LogicController(*scene, this)),
	isDebug(false),
	layout(new QGridLayout(view)),
	bgmController(new QMediaPlayer(this)),
	soundController(new QMediaPlayer(this)),
	isBGMmute(false)
{	
	this->setObjectName("mainWindow");
	setCentralWidget(view);
	setFixedSize(540, 960);
	setWindowTitle(tr("PinBall v0.5b0001"));
	setWindowIcon(QIcon(":/Resources/images/icon/blackjava.ico"));
	setWindowFlags(Qt::FramelessWindowHint);
	setAutoFillBackground(true);
    setMouseTracking(true);
	this->grabKeyboard();
	//this->grabMouse();该条开启后会有不可回避后果

	createMenu();
}

PinBallv05b0001::~PinBallv05b0001() {};

void PinBallv05b0001::createMenu() {
	//this->setStyleSheet("PinBallv05b0001#mainWindow{border-image:url(Resources/images/menu/menu.jpg)}");
	destroyMenuChildButtons();
	destroyMenuChildLabels();

	layout->setMargin(0);

	//加载BGM
	auto list = new QMediaPlaylist(this);
	list->addMedia(QUrl("qrc:/Resources/bgm/menuBGM.mp3"));
	list->setPlaybackMode(QMediaPlaylist::Loop);
	if (bgmController->playlist() == NULL) {
		bgmController->setPlaylist(list);
		bgmController->setVolume(20);
		bgmController->play();
	}

	//设置鼠标光标
	QCursor cursor;
	QPixmap pixmap1(":/Resources/images/icon/cursor.png");
	QPixmap fitpixmap = pixmap1.scaled(64, 64, Qt::KeepAspectRatio);
	cursor = QCursor(fitpixmap, -1, -1);
	this->setCursor(cursor);
	//设置背景图片
	//QFrame *frame = new QFrame(this, Qt::FramelessWindowHint);
	this->setStyleSheet("background-image:url(Resources/images/menu/menu.jpg)");
	
	//标题
	QLabel *titleLabel = new QLabel(this);
	QPixmap pixmap(":/Resources/images/menu/title.png");
	titleLabel->setFixedSize(460, 115);
	titleLabel->setPixmap(pixmap);
	titleLabel->setScaledContents(true);
	titleLabel->setStyleSheet("background:transparent");
	layout->addWidget(titleLabel, 0, 0, 3, 8,Qt::AlignCenter);

	//新游戏按钮
	QToolButton *startButton = new QToolButton(this);
	startButton->setObjectName("startButton");
	startButton->setText("New Game");
	startButton->setFont(QFont("Algerian", 20));
	startButton->setStyleSheet("QToolButton#startButton{background:transparent;color:#66ccff;}QToolButton#startButton:hover{color:red;font-size:36px;}");
	layout->addWidget(startButton, 3, 2, 2, 4, Qt::AlignCenter);
	connect(startButton, &QToolButton::clicked, this, &PinBallv05b0001::initGameMenu);
	connect(startButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);

	//调试模式按钮
	QToolButton *debugButton = new QToolButton(this);
	debugButton->setObjectName("debugButton");
	debugButton->setText("DEBUG-off");
	debugButton->setFont(QFont("Algerian", 20));
	debugButton->setStyleSheet("QToolButton#debugButton{background:transparent;color:gray;}QToolButton#debugButton:hover{color:red;}");
	layout->addWidget(debugButton, 4, 2, 2, 4, Qt::AlignCenter);
	connect(debugButton, &QToolButton::clicked, this, &PinBallv05b0001::toggleDebugMode);
	connect(debugButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);

	//退出游戏按钮
	QToolButton *exitButton = new QToolButton(this);
	exitButton->setObjectName("exitButton");
	exitButton->setText("Exit Game");
	exitButton->setFont(QFont("Algerian", 20));
	exitButton->setStyleSheet("QToolButton#exitButton{background:transparent;color:#fffbf0;}QToolButton#exitButton:hover{color:red;font-size:36px}");
	layout->addWidget(exitButton, 5, 2, 2, 4, Qt::AlignCenter);
	connect(exitButton, &QToolButton::clicked, this, &PinBallv05b0001::close);
	connect(exitButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);

	//about按钮
	QToolButton *aboutButton = new QToolButton(this);
	aboutButton->setIcon(QIcon(":/Resources/images/icon/about.png"));
	aboutButton->setIconSize(QSize(32, 32));
	aboutButton->setObjectName("aboutButton");
	aboutButton->setStyleSheet("QToolButton#aboutButton{background:transparent;}");
	layout->addWidget(aboutButton, 7, 6, 1, 1, Qt::AlignCenter);
	connect(aboutButton, &QToolButton::clicked, this, &PinBallv05b0001::about);
	connect(aboutButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);

	//setting按钮
	QToolButton *settingButton = new QToolButton(this);
	settingButton->setIcon(QIcon(":/Resources/images/icon/setting.png"));
	settingButton->setIconSize(QSize(34, 34));
	settingButton->setObjectName("settingButton");
	settingButton->setStyleSheet("QToolButton#settingButton{background:transparent;}");
	layout->addWidget(settingButton, 7, 7, 1, 1,Qt::AlignCenter);
	connect(settingButton, &QToolButton::clicked, this, &PinBallv05b0001::setting);
	connect(settingButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);

	//gallery按钮
	QToolButton *galleryButton = new QToolButton(this);
	galleryButton->setIcon(QIcon(":/Resources/images/icon/gallery.png"));
	galleryButton->setIconSize(QSize(90, 90));
	galleryButton->setObjectName("galleryButton");
	galleryButton->setStyleSheet("QToolButton#galleryButton{background:transparent;}");
	layout->addWidget(galleryButton, 6, 0, 2, 2, Qt::AlignBottom);
	connect(galleryButton, &QToolButton::clicked, this, &PinBallv05b0001::gallery);
	connect(galleryButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);

	//切换BGM静音状态
	QToolButton *toggleBGMbutton = new QToolButton(this);
	toggleBGMbutton->setIcon(QIcon(":/Resources/images/icon/bgmOn.png"));
	toggleBGMbutton->setIconSize(QSize(34,34));
	toggleBGMbutton->setObjectName("toggleBGMbutton");
	toggleBGMbutton->setStyleSheet("QToolButton#toggleBGMbutton{background:transparent;}");
	layout->addWidget(toggleBGMbutton, 7, 5, 1, 1, Qt::AlignCenter);
	connect(toggleBGMbutton, &QToolButton::clicked, this, &PinBallv05b0001::toggleBGM);
}

void PinBallv05b0001::about() {
	//QMessageBox::about(this, tr("About This Game"), tr("<h2>Snake Game</h2>"
		//"<p>CopyRight &copy;QtSnakeTest."
		//"<p>This Game is designed to test Qt functions based on the Github by DevBean."));
	destroyMenuChildButtons();
	this->setStyleSheet("background-image:url(Resources/images/about/about.jpg)");//about暂缺
	
	QLabel *aboutLabel = new QLabel(this);
	aboutLabel->setText(tr("<p>CopyRight &copy;PinBallPro. "
		"<p>This Game is designed to "
		"<p>develop the abiity of software programming."
		"<p>based on the Github by our team PinBallPro."
		));
	aboutLabel->setFont(QFont("Algerian", 12));
	aboutLabel->setFixedSize(500, 200);
	aboutLabel->setStyleSheet("background:transparent;");
	layout->addWidget(aboutLabel, 2, 1, 3, 6, Qt::AlignCenter);

	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left170.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent}");
	layout->addWidget(returnButton, 6, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::createMenu);
}

void PinBallv05b0001::gallery() {
	destroyMenuChildButtons();
	destroyMenuChildLabels();

	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left42.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent}");
	layout->addWidget(returnButton, 6, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::createMenu);
}

void PinBallv05b0001::setting() {
	destroyMenuChildButtons();

	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left42.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent}");
	layout->addWidget(returnButton, 6, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::createMenu);
}

void PinBallv05b0001::initGameMenu() {
	destroyMenuChildButtons();
	//destroyMenuChildLabels();祛除标题
	this->setStyleSheet("background-image:url(Resources/images/menu/gameMenu.jpg)");

	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left170.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent}");
	layout->addWidget(returnButton, 6, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::playReturnButtonSE);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::createMenu);
}

void PinBallv05b0001::returnMenu(){
	destroyMenuChildButtons();
}

void PinBallv05b0001::destroyMenuChildButtons() {
	//遍历子按钮控件,找到并删除
	QList<QToolButton *> childButtons = this->findChildren<QToolButton *>();
	foreach(QToolButton *childButton, childButtons) {
		disconnect(childButton);//断开此button的所有连接
		childButton->deleteLater();
	}
}

void PinBallv05b0001::destroyMenuChildLabels() {
	QList<QLabel *> childLabels = this->findChildren<QLabel *>();
	foreach(QLabel *childLabel, childLabels) {
		disconnect(childLabel);
		childLabel->deleteLater();
	}
}

void PinBallv05b0001::toggleDebugMode() {
	QToolButton * debugButton = this->findChild<QToolButton*>("debugButton");
	
	if (!isDebug) {
		debugButton->setText(tr("DEBUG-on"));
		debugButton->setStyleSheet("QToolButton#debugButton{background:transparent;color:#ffff00}QToolButton#debugButton:hover{color:black}");
		this->setWindowTitle(tr("PinBall-DEBUG"));
		//开启调试模式,创建状态栏并设置字体颜色为白色
		this->statusBar()->setStyleSheet("color:white;background:transparent;");
		//this->statusBar()->setAttribute(Qt::WA_TranslucentBackground, true);
		this->statusBar()->setSizeGripEnabled(false);//设置状态栏大小控制钮不显示
		isDebug = true;
	}
	else {
		debugButton->setText(tr("DEBUG-off"));
		debugButton->setStyleSheet("QToolButton#debugButton{background:transparent;color:gray;}QToolButton#debugButton:hover{color:red;}");
		this->setWindowTitle(tr("PinBall v0.5b0001"));
		//关闭调试模式,销毁状态栏
		this->statusBar()->deleteLater();
		isDebug = false;
	}
}

void PinBallv05b0001::mousePressEvent(QMouseEvent *event) {
	if (isDebug) {
		statusBar()->showMessage(QString("MousePress:(%1,%2)").arg(QString::number(event->x()), QString::number(event->y())));
	}
	this->windowPos = this->pos();
	QPoint mousePos = event->globalPos();
	this->dPos = mousePos - windowPos;
}

void PinBallv05b0001::mouseReleaseEvent(QMouseEvent *event) {
	if (isDebug) {
		statusBar()->showMessage(QString("MouseRelease:(%1,%2)").arg(QString::number(event->x()), QString::number(event->y())));
	}
}

void PinBallv05b0001::mouseMoveEvent(QMouseEvent *event) {
	if (isDebug) {
		statusBar()->showMessage(QString("MouseCordinate:(%1,%2)").arg(QString::number(event->globalX()), QString::number(event->globalY())));
	}
	this->move(event->globalPos() - this->dPos);
}

void PinBallv05b0001::keyPressEvent(QKeyEvent *event) {
	if (isDebug) {
		statusBar()->showMessage(QString::QString("Key[ %1 |value: %2 ]has been pressed").arg(QString(event->text().toUpper()),QString::number(event->key())));
	}
}

void PinBallv05b0001::keyReleaseEvent(QKeyEvent *event) {
	if (isDebug) {
		statusBar()->showMessage(QString("Key[ %1 |value: %2 ]has been released").arg(QString(event->text().toUpper()),QString::number(event->key())));
	}
}

void PinBallv05b0001::setBGMVolume(int volume) {
	bgmController->setVolume(volume);
}

void PinBallv05b0001::toggleBGM() {
	QToolButton *toggleBGMbutton = this->findChild<QToolButton *>("toggleBGMbutton");
	disconnect(toggleBGMbutton);
	if (isBGMmute) {
		this->setBGMVolume(20);
		toggleBGMbutton->setIcon(QIcon(":/Resources/images/icon/bgmOn.png"));
		toggleBGMbutton->setIconSize(QSize(34,34));
		isBGMmute = false;
	}
	else {
		this->setBGMVolume();//默认0
		toggleBGMbutton->setIcon(QIcon(":/Resources/images/icon/bgmOff.png"));
		toggleBGMbutton->setIconSize(QSize(40, 40));
		isBGMmute = true;
	}
}

void PinBallv05b0001::playReturnButtonSE() {
	auto list = new QMediaPlaylist(this);
	list->addMedia(QUrl("qrc:/Resources/sound/reButton.wav"));
	list->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
	soundController->setPlaylist(list);
	soundController->setVolume(80);
	soundController->play();
}

void PinBallv05b0001::playStepButtonSE() {
	auto list = new QMediaPlaylist(this);
	list->addMedia(QUrl("qrc:/Resources/sound/stepButton.wav"));
	list->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
	soundController->setPlaylist(list);
	soundController->setVolume(80);
	soundController->play();
}