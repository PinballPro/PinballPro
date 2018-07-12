#include<QGraphicsItem>
#include<QPainter>
#include<QStyleOption>
#include<math.h>
#include<QList>
#include"constants.h"
#include"ball.h"
#include"logicController.h"
#include"brick.h"

Ball::Ball(LogicController &controller) : controller(controller) {
	addx = 10;
	addy = -10;
}

void Ball::advance(int step) {
	if (!step)
		return;
	QPointF ballO(ballx, bally);
	ballO = mapToParent(0, 0);
	ballx = ballO.x();
	bally = ballO.y();
	if (iscatch) {
		if (!isout) {
			if (bally > 400) {
				addx = 0;
				addy = controller.dy;
			}
			else {
				addx = controller.dx;
				addy = controller.dy;
			
				isout = true;
			}
		}
		if (isout) {
			if (ballx < -250 + R) {
				addx = -1 * addx;
			}
			if (ballx > 250 - R) {
				addx = -1 * addx;
			}
			if (bally < -400 + R) {
				addy = -1 * addy;
			}
			if (bally > 400 && bally < 400+2*addy  && addy > 0) {
				controller.ballCountPerRound++;
			}if(controller.ballCountPerRound == controller.ballNumber){

				isover = 1;
				controller.roundover(this);
			}
		}
		moveBy(addx, addy);
		handleCollisions();
	}
}

QRectF Ball::boundingRect() const {
	return QRectF(-2 * R, -2 * R, 4 * R, 4 * R);
}

QPainterPath Ball::shape() const{
	QPainterPath path;
	path.addEllipse(0, 0, 2 * R, 2 * R);
	return path;
}

void Ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
	QPixmap pixmap(":/Resources/images/ball/defaultBall.png");
	painter->drawPixmap(0, 0, 2 * R, 2 * R, pixmap);
	//painter->setBrush(Qt::red);
	//painter->drawEllipse(0, 0, 2 * R, 2 * R);
}

//疑似废案
void Ball::slotround() {
	emit roundover();
}

void Ball::handleCollisions() {
	QList<QGraphicsItem *> collisions = collidingItems();
	//检查碰撞物(砖块)类型
	foreach(QGraphicsItem *collidingItem, collisions) {
		//判断类型从枚举值判断
		if (collidingItem->data(GD_Type) == GO_Normal) {
			Brick *collidingBrick = (Brick *)collidingItem;
			if (--(collidingBrick->life) == 0) {
				controller.removeBrick(collidingBrick);
				controller.score += 50;
			}
			if ((this->x()>collidingItem->x()) && (this->y()<collidingItem->y())) {//上表面 
				addy *= -1;
			}
			if ((this->x()<collidingItem->x()) && (this->y() <= collidingItem->y())) {//左表面 
				addy *= -1;
			}
			if ((this->x()<collidingItem->x()) && (this->y()>collidingItem->y())) {//左上角 
				addx *= -1;
				addy *= -1;
			}
			if ((this->x()>collidingItem->x()) && (this->y()>collidingItem->y())) {
				int flag;
				flag = (this->x() - collidingItem->x()) / (this->x() - collidingItem->x());
				if (flag>1) {//右表面 
					addx *= -1;
				}
				if (flag <= 1) {//下表面 
					addy *= -1;
				}
			}

		}
		else if (collidingItem->data(GD_Type) == GO_Reprocess) {

		}
		else if (collidingItem->data(GD_Type) == GO_Increment) {

		}
		else if (collidingItem->data(GD_Type) == GO_Explosion) {

		}
	}
}