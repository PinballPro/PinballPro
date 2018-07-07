#include <iostream>
#include <windows.h>
#include <conio.h>
#include <graphics.h>
using namespace std;

int map[400][600];
int gameround = 0;
int RandNumber[100][3][3];
int renewround = 50;

void brickupdate(int b, int c, int d, int e);

class Brick {
public:
	int posx;
	int posy;
	int number[3][3];
	const int length = 30;
	const int height = 20;

	virtual void shapebirth() {
		setfillcolor(BLUE);
		solidrectangle(posx, posy, posx + length, posy + height);
	}
	virtual void shapeupdate1(int i, int j) {
		solidrectangle(i, j, i + length, j + length);
	}
	virtual void shapeupdate2(int i, int j) {
		setfillcolor(BLUE);
		solidrectangle(i, j + height + 10, i + 1, j + height + 10 + height);
	}

	void brickbirth(Brick &brick, int a) {//a,b表示生成的形状,暂且定为1 圆，2 矩形,3 正方形
		for (int k = 0; k < 1; k++) {
			posx = rand() % (375 - 25 + 1) + 25;
			posy = 1;
			if (map[posx][posy] == 0) {
				shapebirth();
				int gr;
				gr = gameround;
				RandNumber[gr][a - 1][k] = rand() % (10 - 1 + 1) + 1;
				TCHAR s[6];
				setbkmode(TRANSPARENT);
				_stprintf_s(s, _T("%d"), RandNumber[gr][a - 1][k]);
				outtextxy(posx - 4, posy + height / 10, s);
				for (int i = posx - length / 2 - 10; i <= posx + length / 2 + 10; i++) {
					map[i][posy] = a + 10;//标记生成砖块的位置
				}
				map[posx][posy] = a;//标记中心点的位置
			}
			else
				k = k - 1;
		}
	}

};

class Rectbrick :public Brick {
public:
	void shapebirth() {
		setfillcolor(BLUE);
		fillrectangle(posx - length / 2, posy, posx + length / 2, posy + height);
	}
	void shapeupdate1(int i, int j) {
		solidrectangle(i - length / 2, j, i + length / 2, j + height);
	}
	void shapeupdate2(int i, int j) {
		setfillcolor(BLUE);
		fillrectangle(i - length / 2, j + height + 10, i + length / 2, j + height + 10 + height);
	}
};

class Squarebrick :public Brick {
public:
	void shapebirth() {
		setfillcolor(BLUE);
		fillrectangle(posx - height / 2, posy, posx + height / 2, posy + height);
	}
	void shapeupdate1(int i, int j) {
		solidrectangle(i - height / 2, j, i + height / 2, j + height);
	}
	void shapeupdate2(int i, int j) {
		setfillcolor(BLUE);
		fillrectangle(i - height / 2, j + height + 10, i + height / 2, j + height + 10 + height);
	}
};

class Circlebrick :public Brick {
public:
	void shapebirth() {
		setfillcolor(BLUE);
		fillcircle(posx + 2, posy + 10, 10);
	}
	void shapeupdate1(int i, int j) {
		solidcircle(i + 2, j + 10, 10);
	}
	void shapeupdate2(int i, int j) {
		setfillcolor(BLUE);
		fillcircle(i + 2, j + 10 + height + 10, 10);
	}
};

class Renewbrick : public Brick {
public:
	void shapebirth() {
		setfillcolor(RGB(160, 32, 240));
		fillrectangle(posx - length / 2, posy, posx + length / 2, posy + height);
	}
	void shapeupdate1(int i, int j) {
		solidrectangle(i - length / 2, j, i + length / 2, j + height);
	}
	void shapeupdate2(int i, int j) {
		setfillcolor(RGB(160, 32, 240));
		fillrectangle(i - length / 2, j + height + 10, i + length / 2, j + height + 10 + height);
	}
	void function(Renewbrick &renew) {
		for (int i = 0; i <= gameround; i++) {
			if (RandNumber[gameround][3][0] == 1)
				brickbirth(renew, 4);
		}
	}
};

