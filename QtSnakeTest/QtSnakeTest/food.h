#ifndef FOOD_H
#define FO0D_H

#include<QGraphicsItem>

class Food : public QGraphicsItem {
public:
	Food(qreal x, qreal y);
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
		
	QPainterPath shape() const;
};

#endif // !FOOD_H

