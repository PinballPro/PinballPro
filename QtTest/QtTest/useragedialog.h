#include<QDialog>

class UserAgeDialog :public QDialog {
	Q_OBJECT
public:
	UserAgeDialog(QWidget *parent = 0) {};
	void accept();
signals:
	void userAgeChanged(int newAge);//定义一个信号
private:
	int newAge;
};
