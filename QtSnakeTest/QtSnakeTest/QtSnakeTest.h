#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtSnakeTest.h"

class QtSnakeTest : public QMainWindow
{
	Q_OBJECT

public:
	QtSnakeTest(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtSnakeTestClass ui;
};
