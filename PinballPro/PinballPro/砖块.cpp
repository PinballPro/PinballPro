#include"class.h"

int main() {
	initgraph(400, 600);
	Rectbrick rect;
	Circlebrick circle;
	Squarebrick square;
	Renewbrick renew;
	for (int i = 0; i < 10; i++) {
		rect.brickbirth(rect, 2);
		circle.brickbirth(circle, 1);
		square.brickbirth(square, 3);
		_getch();
		int a;
		a = rand() % 10;
		if (a > 5) {
			renew.brickbirth(renew, 4);
		}
		renew.function(renew);
		gameround++;
		_getch();
		brickupdate(1, 2, 3, 4);
	}
	_getch();
	return 0;
}

void brickupdate(int b, int c, int d, int e) {
	for (int j = gameround * (20 + 10); j > 0; j--) {
		int countnumber = 0;
		for (int i = 0; i < 400; i++) {
			if (map[i][j] == c || map[i][j] == b || map[i][j] == d || map[i][j] == e) {
				if (map[i][j] == c) {
					setfillcolor(BLACK);
					solidrectangle(i - 30 / 2, j, i + 30 / 2, j + 20);
					setfillcolor(BLUE);
					fillrectangle(i - 30 / 2, j + 20 + 10, i + 30 / 2, j + 20 + 10 + 20);
					map[i][j + 20 + 10] = c;
				}
				else if (map[i][j] == b) {
					setfillcolor(BLACK);
					solidcircle(i + 2, j + 10, 11);
					setfillcolor(BLUE);
					fillcircle(i + 2, j + 10 + 20 + 10, 10);
					map[i][j + 20 + 10] = b;
				}
				else if (map[i][j] == d) {
					setfillcolor(BLACK);
					solidrectangle(i - 20 / 2, j, i + 20 / 2, j + 20);
					setfillcolor(BLUE);
					fillrectangle(i - 20 / 2, j + 20 + 10, i + 20 / 2, j + 20 + 10 + 20);
					map[i][j + 20 + 10] = d;
				}
				else if (map[i][j] == e) {
					setfillcolor(BLACK);
					solidrectangle(i - 30 / 2, j, i + 30 / 2, j + 20);
					setfillcolor(RGB(160, 32, 240));
					fillrectangle(i - 30 / 2, j + 20 + 10, i + 30 / 2, j + 20 + 10 + 20);
					map[i][j + 20 + 10] = e;
				}
				TCHAR f[6];
				setbkmode(TRANSPARENT);
				int a;
				a = gameround - (j + 29) / 30;
				if (map[i][j] != 4) {
					_stprintf_s(f, _T("%d"), RandNumber[a][map[i][j] - 1][0]);
					outtextxy(i - 6, j + 10 + 20 + 20 / 10, f);
				}
				else if (map[i][j] == 4) {
					_stprintf_s(f, _T("%d"), RandNumber[a][map[i][j] - 1][0] - 1);
					outtextxy(i - 6, j + 10 + 20 + 20 / 10, f);
				}
				map[i][j] = 0;
			}
			else if (map[i][j] == b + 10 || map[i][j] == c + 10 || map[i][j] == d + 10) {
				map[i][j] = 0;
			}
		}
	}
}