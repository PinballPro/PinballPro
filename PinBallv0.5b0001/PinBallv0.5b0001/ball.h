#ifndef  BALL_H
#define  BALL_H
#include<QGraphicsItem>
#include<QRectF>
#include<QObject>
#include<QWidget>

class LogicController;

class Ball : public QObject, public QGraphicsItem {
	Q_OBJECT
public:
	Ball(LogicController &controller);
	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
	void slotround();
	double addx, addy, zMouse, xMouse, yMouse;
protected:
	void advance(int step);
signals:
	void roundover();
private:
	double bally, ballx;
	bool iscatch = true;
	bool isout = false;
	bool isover = false;
	const int R = 10;
	LogicController &controller;

	void handleCollisions();
};

#endif // ! BALL_H

