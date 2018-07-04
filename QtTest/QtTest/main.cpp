#include <QApplication>
#include <QDebug>
#include <iostream>
#include "newspaper.h"
#include "reader.h"
#include "mainwindow.h"
#include "sswindow.h"
using namespace std;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow win;
	win.show();

	SSwindow sswin;
	sswin.show();

	return app.exec();
}
