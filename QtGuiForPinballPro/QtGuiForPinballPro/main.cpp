#include "QtGuiForPinballPro.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QtGuiForPinballPro w;
	w.show();
	return a.exec();
}
