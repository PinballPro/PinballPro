#include<QObject>
#include<QDebug>

class Reader : public QObject {
	Q_OBJECT
public:
	Reader(){}

	void receiveNewsPaper(const QString & name) {
		qDebug() << "Receives NewPaper: " << name;
	}
};

