#include "mainwindow.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QTimer>
#include<QAction>
#include<QMenuBar>
#include<QApplication>
#include<QMessageBox>
#include<QIcon>
#include"constants.h"
#include "gamecontroller.h"
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	scene(new QGraphicsScene(this)),
	view(new QGraphicsView(scene,this)),
	game(new GameController(*scene,this))
{
	setCentralWidget(view);
	//resize(600, 600);
	setFixedSize(600, 600);
	setWindowIcon(QIcon(":/Resources/blackjava.ico"));

	createActions();//创建功能选项
	createMenus();//创建菜单选项

	initScene();
	initSceneBackGround();
	//在下次事件循环开始后立即调用槽函数
	QTimer::singleShot(0, this, SLOT(adjustViewSize()));
}

MainWindow::~MainWindow() {

}

void MainWindow::adjustViewSize() {
	view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}

void MainWindow::createActions() {
	newGameAction = new QAction(tr("&NEW GAME"), this);
	newGameAction->setShortcuts(QKeySequence::New);
	newGameAction->setStatusTip(tr("Start a new game now..."));
	connect(newGameAction, &QAction::triggered, this, &MainWindow::newGame);

	exitAction = new QAction(tr("&Exit"), this);
	exitAction->setShortcuts(QKeySequence::Close);
	exitAction->setStatusTip(tr("Exit Game"));
	connect(exitAction, &QAction::triggered, this, &MainWindow::close);

	pauseAction = new QAction(tr("&Pause"), this);
	pauseAction->setStatusTip(tr("Pause..."));
	connect(pauseAction, &QAction::triggered, game, &GameController::pause);

	resumeAction = new QAction(tr("&Resume"), this);
	resumeAction->setStatusTip(tr("Resume the Game"));
	connect(resumeAction, &QAction::triggered, game, &GameController::resume);

	gameHelpAction = new QAction(tr("Game &Help"), this);
	gameHelpAction->setShortcuts(QKeySequence::HelpContents);
	gameHelpAction->setStatusTip(tr("Find Help About This Game..."));
	connect(gameHelpAction, &QAction::triggered, this, &MainWindow::gameHelp);

	aboutAction = new QAction(tr("&About"), this);
	aboutAction->setStatusTip("About the Game");
	connect(aboutAction, &QAction::triggered, this, &MainWindow::about);

	aboutQtAction = new QAction(tr("&AboutQt"), this);
	aboutQtAction->setStatusTip(tr("About the Qt"));
	connect(aboutAction, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::createMenus() {
	QMenu *options = menuBar()->addMenu(tr("&options"));
	options->addAction(newGameAction);
	options->addSeparator();
	options->addAction(pauseAction);
	options->addAction(resumeAction);
	options->addSeparator();
	options->addAction(exitAction);

	QMenu *help = menuBar()->addMenu(tr("&Help"));
	help->addAction(gameHelpAction);
	help->addAction(aboutAction);
	help->addAction(aboutQtAction);
}


void MainWindow::initScene() {
	//左上角在(-100,-100),边长为200px的正方形场景区域
	scene->setSceneRect(-100, -100, 200, 200);
}

void MainWindow::initSceneBackGround() {
	QPixmap bg(TILE_SIZE, TILE_SIZE);
	QPainter p(&bg);
	p.setBrush(QBrush(Qt::gray));
	p.drawRect(0, 0, TILE_SIZE, TILE_SIZE);
	
	view->setBackgroundBrush(QBrush(bg));
}

void MainWindow::newGame() {
	QTimer::singleShot(0, game, SLOT(gameOver()));
}

void MainWindow::about() {
	QMessageBox::about(this, tr("About This Game"), tr("<h2>Snake Game</h2>"
		"<p>CopyRight &copy;QtSnakeTest."
		"<p>This Game is designed to test Qt functions based on the Github by DevBean."));
}

void MainWindow::gameHelp() {
	QMessageBox::about(this, tr("Game Help"), tr("using direction keys to control the snake's action"
		"<p>Space - pause & resume"));
}
