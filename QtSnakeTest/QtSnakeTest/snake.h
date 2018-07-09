#ifndef SNAKE_H
#define SNAKE_H
#include <QGraphicsItem>
#include <QRectF>

class GameController;

class Snake : public QGraphicsItem {
public:
	enum Direction {
		NoMove,
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown
	};
	Snake(GameController &controller);

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
	void setMoveDirection(Direction direction);
	Direction currentDirection();

protected:
	void advance(int step);

private:
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	//处理碰撞
	void handleCollisions();

	QPointF			head;//头节点
	int				growing;
	int				speed;
	QList<QPointF>	tail;//list储存蛇身
	int				tickCounter;
	Direction		moveDirection;
	GameController  &controller;
};

#endif // !SNAKE_H

