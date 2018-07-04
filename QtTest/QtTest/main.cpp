#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "newspaper.h"
#include "reader.h"
using namespace std;

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	Newspaper newspaper("WuHan Newspaper");
	Reader reader;
	QObject::connect(&newspaper, &Newspaper::newPaper, &reader, &Reader::receiveNewsPaper);
	newspaper.send();
	return app.exec();
}
