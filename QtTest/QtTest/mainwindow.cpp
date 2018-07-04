#include<QAction>
#include<QMenuBar>
#include<QMessageBox>
#include<QStatusBar>
#include<QToolBar>
#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif
#include"mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	this->resize(QSize(800, 600));
	setWindowTitle(tr("弹球Pro"));

	openAction = new QAction(QIcon(":/Resources/images/ico/dictionary.ico"), tr("&加载.."), this);
	openAction->setShortcuts(QKeySequence::Open);//设置该功能的快捷键
	openAction->setStatusTip(tr("Open an Asynchorous Example"));
	connect(openAction, &QAction::triggered, this, &MainWindow::open);

	QMenu *file = menuBar()->addMenu(tr("&choose a file"));
	file->addAction(openAction);

	QToolBar * toolBar = addToolBar(tr("&choose a file"));
	toolBar->addAction(openAction);

	statusBar();
}

MainWindow::~MainWindow() {};

void MainWindow::open() {
	QMessageBox::information(this, tr("Information"), tr("Open"));
}