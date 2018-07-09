#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
//MVC model/view/controller
class QGraphicsScene;
class QGraphicsView;
class GameController;

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots:
	void adjustViewSize();
	void newGame();
	void gameHelp();
	void about();

private:
	void createActions();
	void createMenus();

	void initScene();
	void initSceneBackGround();

	QGraphicsScene *scene;
	QGraphicsView *view;
	GameController *game;
	
	//Actions
	QAction *newGameAction;
	QAction *pauseAction;
	QAction *resumeAction;
	QAction *exitAction;
	QAction *gameHelpAction;
	QAction *aboutAction;
	QAction *aboutQtAction;
};

#endif // ! MAINWINDOW_H

