#ifndef BRICK_H
#define BRICK_H
#include<QGraphicsItem>
#include"constants.h"
class Brick : public QGraphicsItem {
public:
	Brick(qreal x, qreal y, GameObjectsType type,QColor color);
	Brick();
	Brick(Brick *);//�������캯��
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

	QPainterPath shape() const;
	QPainterPath lifeOut() const;
	int life;

private:
	QColor color;
};
#endif// !BRICK_H
