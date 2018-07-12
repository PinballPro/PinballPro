#include<QGraphicsView>
#include<QGraphicsScene>
#include<QLabel>
#include<QMainWindow>
#include<QStatusBar>
#include<QGridLayout>
#include<QToolButton>
#include<QPushButton>
#include<QMessageBox>
#include<QMouseEvent>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QLineEdit>
#include<QSlider>
#include"logicController.h"
#include"PinBallv05b0001.h"
#include"db_utils.h"
#include"player.h"
#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif

PinBallv05b0001::PinBallv05b0001(QWidget *parent)
	: QMainWindow(parent),
	scene(new QGraphicsScene(this)),
	view(new QGraphicsView(scene, this)),
	baseController(new LogicController(*scene, this)),
	isDebug(false),
	isBGMmute(false),
	volume(20),
	layout(new QGridLayout(view)),
	bgmController(new QMediaPlayer(this)),
	soundController(new QMediaPlayer(this)),
	db_utils(new DB_Utils(this))
{	
	this->setObjectName("mainWindow");
	setCentralWidget(view);
	setFixedSize(540, 960);
	setWindowTitle(tr("PinBall v0.5b0001"));
	setWindowIcon(QIcon(":/Resources/images/icon/blackjava.ico"));
	setWindowFlags(Qt::FramelessWindowHint);
	setAutoFillBackground(true);
    setMouseTracking(true);
	//this->grabKeyboard();
	//this->grabMouse();该条开启后会有不可回避后果
	view->setMouseTracking(true);
	//设置全局光标
	//设置鼠标光标
	QCursor cursor;
	QPixmap pixmap1(":/Resources/images/icon/cursor.png");
	QPixmap fitpixmap = pixmap1.scaled(64, 64, Qt::KeepAspectRatio);
	cursor = QCursor(fitpixmap, -1, -1);
	this->setCursor(cursor);

	loginPage();
	//createMenu();
}

PinBallv05b0001::~PinBallv05b0001() {};

void PinBallv05b0001::loginPage() {
	//构建控件
	QLabel *playerLabel = new QLabel(this);
	QLineEdit *playerNameEdit = new QLineEdit(this);
	playerNameEdit->setObjectName("player_name");
	QLineEdit *passwordEdit = new QLineEdit(this);
	passwordEdit->setObjectName("password");
	QToolButton *loginButton = new QToolButton(this);
	loginButton->setFixedHeight(40);
	playerNameEdit->setFixedWidth(200);
	playerNameEdit->setFixedHeight(60);
	passwordEdit->setFixedHeight(60);

	//设置头像
	QPixmap pixmap(":/Resources/images/icon/defaultPortrait.png");
	playerLabel->setFixedSize(100, 100);
	playerLabel->setPixmap(pixmap);
	playerLabel->setScaledContents(true);

	//设置登录框文本
	playerNameEdit->setPlaceholderText(tr("name"));
	playerNameEdit->setFont(QFont("Algerian", 18));
	passwordEdit->setPlaceholderText(tr("password"));
	passwordEdit->setFont(QFont("calibri",15));
	passwordEdit->setEchoMode(QLineEdit::Password);
	loginButton->setText(tr("Sign In"));
	loginButton->setFont(QFont("Algerian", 20));
	loginButton->setStyleSheet("background-color:#3299cc;color:white;border:2px,groove,gray;border-radius:10px;padding:2px 4px;");

	//绑定信号槽事件
	connect(loginButton, &QToolButton::clicked, this, &PinBallv05b0001::signIn);

	//设置占位空白控件
	QSpacerItem *topSpacer = new QSpacerItem(500, 200, QSizePolicy::Maximum);
	QSpacerItem *bottomSpacer = new QSpacerItem(500, 200, QSizePolicy::Maximum);
	//添加至布局
	layout->addWidget(playerLabel, 1, 3, 2, 2, Qt::AlignCenter);
	layout->addWidget(playerNameEdit, 4, 2, 1, 4, Qt::AlignCenter);
	layout->addWidget(passwordEdit, 5, 2, 1, 4, Qt::AlignCenter);
	layout->addWidget(loginButton, 6, 2, 1, 4, Qt::AlignCenter);
}

void PinBallv05b0001::signIn() {
	QString player_name = this->findChild<QLineEdit *>("player_name")->text();
	QString password = this->findChild<QLineEdit *>("password")->text();
	//如果用户和密码不存在于数据库,sign_in将会自动注册用户
	if (db_utils->sign_in(player_name, password)) {
		createMenu();
	}
	else {//用户存在但是密码输入错误
		QMessageBox::warning(this, "Error:Can not sign in!", "Welcome back!But Your Name or Password may be wrong, Please input them again", QMessageBox::Yes, QMessageBox::Escape);
	}
}

void PinBallv05b0001::createMenu() {
	this->grabKeyboard();
	//this->setStyleSheet("PinBallv05b0001#mainWindow{border-image:url(Resources/images/menu/menu.jpg)}");
	destroyMenuChildButtons();
	destroyMenuChildLabels();
	destroyMenuChildEdit();

	layout->setMargin(0);

	//加载BGM
	auto list = new QMediaPlaylist(this);
	list->addMedia(QUrl("qrc:/Resources/bgm/menuBGM.mp3"));
	list->setPlaybackMode(QMediaPlaylist::Loop);
	if (bgmController->playlist() == NULL) {
		bgmController->setPlaylist(list);
		bgmController->setVolume(this->volume);
		bgmController->play();
	}

	
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
	debugButton->setFont(QFont("Algerian", 20));
	if (isDebug) {
		debugButton->setText("DEBUG -on");
		debugButton->setStyleSheet("QToolButton#debugButton{background:transparent;color:#ffff00;}QToolButton#debugButton:hover{color:#00ff7f;}");
	}
	else {
		debugButton->setText("DEBUG-off");
		debugButton->setStyleSheet("QToolButton#debugButton{background:transparent;color:gray;}QToolButton#debugButton:hover{color:red;}");
	}
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
	if(isBGMmute){
		toggleBGMbutton->setIcon(QIcon(":/Resources/images/icon/bgmOff.png"));
		toggleBGMbutton->setIconSize(QSize(40, 40));
	}
	else {
		toggleBGMbutton->setIcon(QIcon(":/Resources/images/icon/bgmOn.png"));
		toggleBGMbutton->setIconSize(QSize(34,34));
	}
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
	aboutLabel->setStyleSheet("background:transparent;color:white;");
	layout->addWidget(aboutLabel, 2, 1, 3, 6, Qt::AlignCenter);

	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left170.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent}");
	layout->addWidget(returnButton, 6, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::playReturnButtonSE);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::createMenu);
}

void PinBallv05b0001::gallery() {
	destroyMenuChildButtons();
	destroyMenuChildLabels();

	this->setStyleSheet("background-image:url(Resources/images/menu/gallery.jpg)");

	QToolButton *wardrobeButton = new QToolButton(this);
	wardrobeButton->setIcon(QIcon(":/Resources/images/icon/wardrobe.png"));
	wardrobeButton->setIconSize(QSize(100, 100));
	//wardrobeButton->setText(tr("Wardrobe"));
	//wardrobeButton->setFont(QFont("Algerian", 20));
	wardrobeButton->setObjectName("wardrobeButton");
	wardrobeButton->setStyleSheet("QToolButton#wardrobeButton{background:transparent;}");
	layout->addWidget(wardrobeButton, 1, 2, 2, 4, Qt::AlignCenter);
	connect(wardrobeButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);
	connect(wardrobeButton, &QToolButton::clicked, this, &PinBallv05b0001::Wardrobe);

	QToolButton *rankListButton = new QToolButton(this);
	rankListButton->setIcon(QIcon(":/Resources/images/icon/rankList.png"));
	rankListButton->setIconSize(QSize(100, 100));
	rankListButton->setText(tr("测试"));
	rankListButton->setObjectName("rankListButton");
	rankListButton->setStyleSheet("QToolButton#rankListButton{background:transparent;}");
	layout->addWidget(rankListButton, 3, 3, 2, 2, Qt::AlignCenter);
	connect(rankListButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);
	connect(rankListButton, &QToolButton::clicked, this, &PinBallv05b0001::AchivementPage);


	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left42.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent;}");
	layout->addWidget(returnButton, 6, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::playReturnButtonSE);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::createMenu);
}

void PinBallv05b0001::setting() {
	destroyMenuChildButtons();
	QLabel *volumeLabel = new QLabel(this);
	QPixmap pixmap(":/Resources/images/icon/volume.png");
	volumeLabel->setFixedSize(100, 100);
	volumeLabel->setPixmap(pixmap);
	volumeLabel->setScaledContents(true);
	volumeLabel->setStyleSheet("background:transparent;");
	layout->addWidget(volumeLabel, 3, 1, 2, 2, Qt::AlignCenter);

	QSlider *volumeSlider = new QSlider(Qt::Horizontal,this);
	volumeSlider->setRange(0, 100);
	volumeSlider->setValue(volume);
	volumeSlider->setFixedWidth(300);
	volumeSlider->setFixedHeight(60);
	volumeSlider->setStyleSheet("background:transparent");
	connect(volumeSlider, &QSlider::valueChanged, this, &PinBallv05b0001::setBGMVolume);
	layout->addWidget(volumeSlider, 3, 3, 2, 5, Qt::AlignCenter);

	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left42.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent}");
	layout->addWidget(returnButton, 6, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::settingBackMenu);
}

void PinBallv05b0001::settingBackMenu() {
	playReturnButtonSE();
	QSlider *childSlider = this->findChild<QSlider *>();
	disconnect(childSlider);
	childSlider->deleteLater();
	createMenu();
}

void PinBallv05b0001::initGameMenu() {
	destroyMenuChildButtons();
	//destroyMenuChildLabels();祛除标题
	this->setStyleSheet("background-image:url(Resources/images/menu/gameMenu.jpg)");

	QToolButton *fastModeButton = new QToolButton(this);
	fastModeButton->setObjectName("fastModeButton");
	fastModeButton->setText(tr("Minimalism Mode"));
	fastModeButton->setFont(QFont("Algerian", 20));
	fastModeButton->setStyleSheet("QToolButton#fastModeButton{background:transparent;color:#fffbf0}QToolButton#fastModeButton:hover{font-size:36px;color:red}");
	layout->addWidget(fastModeButton, 3, 2, 2, 4, Qt::AlignCenter);
	connect(fastModeButton, &QToolButton::clicked, this, &PinBallv05b0001::initFastMode);
	connect(fastModeButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);

	QToolButton *itemModeButton = new QToolButton(this);
	itemModeButton->setObjectName("itemModeButton");
	itemModeButton->setText(tr("MultiItem Mode"));
	itemModeButton->setFont(QFont("Algerian", 20));
	itemModeButton->setStyleSheet("QToolButton#itemModeButton{background:transparent;color:#ffff00}QToolButton#itemModeButton:hover{font-size:36px;color:red}");
	layout->addWidget(itemModeButton, 5, 2, 2, 4, Qt::AlignCenter);
	connect(itemModeButton, &QToolButton::clicked, this, &PinBallv05b0001::initItemMode);
	connect(itemModeButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);

	QToolButton *kunModeButton = new QToolButton(this);
	kunModeButton->setObjectName("kunModeButton");
	kunModeButton->setText(tr("Cthulhu Mode"));
	kunModeButton->setFont(QFont("Algerian", 20));
	kunModeButton->setStyleSheet("QToolButton#kunModeButton{background:transparent;color:#BC1717}QToolButton#kunModeButton:hover{font-szie:36px;color:#6B4226}");
	layout->addWidget(kunModeButton, 7, 2, 2, 4, Qt::AlignCenter);
	connect(kunModeButton, &QToolButton::clicked, this, &PinBallv05b0001::playStepButtonSE);
	connect(kunModeButton, &QToolButton::clicked, this, &PinBallv05b0001::initCthulhuMode);


	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left170.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent}");
	layout->addWidget(returnButton, 9, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::playReturnButtonSE);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::createMenu);
}

void PinBallv05b0001::initFastMode() {
	destroyMenuChildButtons();
	destroyMenuChildLabels();
	view->setRenderHint(QPainter::Antialiasing);
	view->setCacheMode(QGraphicsView::CacheBackground);
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	view->setDragMode(QGraphicsView::ScrollHandDrag);
	baseController->startFastMode();
	initScene();
}

void PinBallv05b0001::initItemMode() {
	destroyMenuChildButtons();
	destroyMenuChildLabels();
	view->setRenderHint(QPainter::Antialiasing);
	view->setCacheMode(QGraphicsView::CacheBackground);
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	view->setDragMode(QGraphicsView::ScrollHandDrag);
	baseController->startItemMode();
	initScene();
}

void PinBallv05b0001::initCthulhuMode() {
	destroyMenuChildButtons();
	destroyMenuChildLabels();
	view->setRenderHint(QPainter::Antialiasing);
	view->setCacheMode(QGraphicsView::CacheBackground);
	view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	view->setDragMode(QGraphicsView::ScrollHandDrag);
	baseController->startKunMode();
	initScene();
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

void PinBallv05b0001::destroyMenuChildEdit() {
	QList<QLineEdit *> childObjects = this->findChildren<QLineEdit *>();
	foreach(QLineEdit *childObject, childObjects) {
		disconnect(childObject);
		childObject->deleteLater();
	}
}

void PinBallv05b0001::toggleDebugMode() {
	QToolButton * debugButton = this->findChild<QToolButton*>("debugButton");
	
	if (!isDebug) {
		debugButton->setText(tr("DEBUG-on"));
		debugButton->setStyleSheet("QToolButton#debugButton{background:transparent;color:#ffff00}QToolButton#debugButton:hover{color:#00ff7f}");
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
	if (baseController->isInGame) {
		if (event->button() == Qt::LeftButton)
		{
			xMouse = event->pos().rx();
			yMouse = event->pos().ry();
			zMouse = sqrt((xMouse - 250)*(xMouse - 250) + (yMouse - 800)*(yMouse - 800));
			xMouse = 15 * (xMouse-250) / zMouse;
			yMouse = 15 * (yMouse-800) / zMouse;
			baseController->dx = xMouse;
			baseController->dy = yMouse;
			if (baseController->isWait) {
				baseController->changeDxDy();//改变发射方向然后继续
			}
		}
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
	this->volume = volume;
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

void PinBallv05b0001::Wardrobe() {
	destroyMenuChildButtons();
	destroyMenuChildLabels();

	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left170.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent}");
	layout->addWidget(returnButton, 6, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::playReturnButtonSE);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::gallery);
}


void PinBallv05b0001::AchivementPage() {
	destroyMenuChildButtons();
	destroyMenuChildLabels();

	QLabel *highScoreLabel = new QLabel(this);
	highScoreLabel->setText(QString("Highest Score: %1 bonus").arg(db_utils->currentPlayer->player_name));
	highScoreLabel->setFont(QFont("Algerian", 18));
	highScoreLabel->setStyleSheet("background:transparent;color:white;border:2px,groove,gray;border-radius:10px;padding:2px 4px;");
	layout->addWidget(highScoreLabel, 2, 1, 2, 6,Qt::AlignCenter);
	
	QLabel *totalRoundsLabel = new QLabel(this);
	totalRoundsLabel->setText(QString("Total Rounds: %1 bonus").arg(db_utils->currentPlayer->total_rounds));
	totalRoundsLabel->setFont(QFont("Algerian", 18));
	totalRoundsLabel->setStyleSheet("background:transparent;color:white;border:2px,groove,gray;border-radius:10px;padding:2px 4px;");
	layout->addWidget(totalRoundsLabel, 4, 1, 2, 6, Qt::AlignCenter);

	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left170.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent}");
	layout->addWidget(returnButton, 6, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::playReturnButtonSE);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::gallery);
}

void PinBallv05b0001::initScene() {
	scene->setItemIndexMethod(QGraphicsScene::NoIndex);
	scene->setSceneRect(-250, -400, 500, 800);
}

//游戏结束 重置controller中一切参数
void PinBallv05b0001::GameOver() {
	db_utils->saveGameInfo(baseController->score, baseController->round);
	scene->clear();
	scene->deleteLater();
	this->scene = new QGraphicsScene(this);
	this->view = new QGraphicsView(this);
	baseController = new LogicController(*scene, this);

	destroyMenuChildButtons();
	destroyMenuChildLabels();
	QLabel *scoreLabel = new QLabel(this);
	scoreLabel->setText(QString("Your score: %1").arg(QString::number(baseController->score)));
	scoreLabel->setFont(QFont("Algerian", 20));
	scoreLabel->setStyleSheet("background:transparent;color:red");
	layout->addWidget(scoreLabel, 1, 1, 3, 6, Qt::AlignCenter);
	
	QLabel *roundLabel = new QLabel(this);
	roundLabel->setText(QString("Total Rounds: %1").arg(QString::number(baseController->round)));
	roundLabel->setFont(QFont("Algerian", 20));
	roundLabel->setStyleSheet("background:transparent;color:red;");
	layout->addWidget(roundLabel, 4, 1, 3, 6, Qt::AlignCenter);

	QToolButton *returnButton = new QToolButton(this);
	returnButton->setIcon(QIcon(":/Resources/images/icon/left170.png"));
	returnButton->setIconSize(QSize(100, 100));
	returnButton->setObjectName("returnButton");
	returnButton->setStyleSheet("QToolButton#returnButton{background:transparent}");
	layout->addWidget(returnButton, 7, 3, 2, 2, Qt::AlignCenter);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::playReturnButtonSE);
	connect(returnButton, &QToolButton::clicked, this, &PinBallv05b0001::createMenu);

	baseController->score = 0;
	baseController->round = 1;
	baseController->ballNumber = 1;
	baseController->isInGame = false;
}