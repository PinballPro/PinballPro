#include<QDialog>

class UserAgeDialog :public QDialog {
	Q_OBJECT
public:
	UserAgeDialog(QWidget *parent = 0) {};
	void accept();
signals:
	void userAgeChanged(int newAge);//����һ���ź�
private:
	int newAge;
};
