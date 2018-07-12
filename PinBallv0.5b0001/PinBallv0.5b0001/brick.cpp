#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QTime>
#include<QPainter>
#include"brick.h"
#include"constants.h"

Brick::Brick() {};
Brick::Brick(qreal x, qreal y, GameObjectsType type,QColor color) {
	setPos(x, y);
	setData(GD_Type, type);//构造时传入坐标与砖块类型与砖块颜色
	this->color = color;

	//随机生成生命
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
	//实际上四倍于实际区域
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
	//四倍于实际区域的boundingRect位于这个小坐标系的中心
	p.addRoundRect(0, 0, BRICK_SIZE, BRICK_SIZE, 10);
	return p;
}

QPainterPath Brick::lifeOut() const {
	QPainterPath p;
	p.addText(BRICK_SIZE / 2, BRICK_SIZE / 2, QFont("Calibri", 10), QString::number(life));
	return p;
}
