#include<QDialog>
#include"useragedialog.h"

void UserAgeDialog::accept() {
	emit userAgeChanged(newAge);//���źŷ����ȥ
	QDialog::accept();
}