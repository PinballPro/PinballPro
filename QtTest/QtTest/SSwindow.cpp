#include "sswindow.h"
#include<QSpinbox>
#include<QSlider>
#include<QHBoxLayout>

#if _MSC_VER >= 1600

#pragma execution_character_set("utf-8")

#endif
SSwindow::SSwindow() {
	this->resize(QSize(800, 600));
	setWindowTitle(tr("滑动与数字格联动"));
	QSpinBox *spinBox = new QSpinBox(this);
	QSlider *slider = new QSlider(Qt::Horizontal, this);
	spinBox->setRange(0, 100);
	slider->setRange(0, 100);

	QObject::connect(slider, &QSlider::valueChanged, spinBox, &QSpinBox::setValue);
	void(QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
	QObject::connect(spinBox, spinBoxSignal, slider, &QSlider::setValue);
	spinBox->setValue(25);

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(spinBox);
	layout->addWidget(slider);
	this->setLayout(layout);
}