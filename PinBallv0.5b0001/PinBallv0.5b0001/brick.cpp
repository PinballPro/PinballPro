#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QTime>
#include<QPainter>
#include"brick.h"
#include"constants.h"

Brick::Brick() {};
Brick::Brick(qreal x, qreal y, GameObjectsType type,QColor color) {
	setPos(x, y);
	setData(GD_Type, type);//����ʱ����������ש��������ש����ɫ
	this->color = color;

	//�����������
	qsrand(QTime::currentTime().msec() + QTime::currentTime().second() * 1000);
	this->life = qrand() % 9 + 1;
}
Brick::Brick(Brick *brick) {
	this->setPos(brick->x(), brick->y());
	this->setData(GD_Type, brick->data(GD_Type));
	this->color = brick->color;
	this->life = brick->life;
}

QRectF Brick::boundingRect() const {
	//ʵ�����ı���ʵ������
	return QRectF(-BRICK_SIZE, -BRICK_SIZE, BRICK_SIZE * 2, BRICK_SIZE * 2);
}

void Brick::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
	painter->save();
	painter->setRenderHint(QPainter::Antialiasing);
	painter->fillPath(shape(), this->color);
	painter->fillPath(lifeOut(),Qt::black);
	painter->restore();
}

QPainterPath Brick::shape() const {
	QPainterPath p;
	//�ı���ʵ�������boundingRectλ�����С����ϵ������
	p.addRoundRect(0, 0, BRICK_SIZE, BRICK_SIZE, 10);
	return p;
}

QPainterPath Brick::lifeOut() const {
	QPainterPath p;
	p.addText(BRICK_SIZE / 2, BRICK_SIZE / 2, QFont("Calibri", 10), QString::number(life));
	return p;
}
