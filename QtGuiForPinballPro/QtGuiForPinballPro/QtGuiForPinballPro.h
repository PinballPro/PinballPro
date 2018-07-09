#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtGuiForPinballPro.h"

class QtGuiForPinballPro : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiForPinballPro(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiForPinballProClass ui;
};
