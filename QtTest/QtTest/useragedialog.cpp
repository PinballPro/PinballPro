#include<QDialog>
#include"useragedialog.h"

void UserAgeDialog::accept() {
	emit userAgeChanged(newAge);//将信号发射出去
	QDialog::accept();
}