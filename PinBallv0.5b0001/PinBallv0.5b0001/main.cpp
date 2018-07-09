#include "PinBallv05b0001.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PinBallv05b0001 w;
	w.show();
	return a.exec();
}
