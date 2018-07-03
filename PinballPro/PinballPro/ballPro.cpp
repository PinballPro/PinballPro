#include <iostream>
#include <string>
using namespace std;

typedef struct location {
	double x, y, z;
}Cordinate;

class BallPro {
private:
	Cordinate ball_location;
	string ball_name;
};