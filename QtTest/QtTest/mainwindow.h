#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QMainWindow>
#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif
class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	MainWindow(QWidget *parent = 0);
	~MainWindow();

private:
	void open();
	void showUserAgeDialog();
	void setUserAge(int);
	QAction *openAction;
	int userAge;
};


#endif // !MAINWINDOW_H

