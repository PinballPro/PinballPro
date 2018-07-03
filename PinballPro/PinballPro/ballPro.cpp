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
	int ball_status;
public:
	void setCordinate(Cordinate ball_location) {
		this->ball_location = ball_location;
	}
	Cordinate getCordinate(void) {
		return this->ball_location;
	}
	void setBallName(string ball_name) {
		this->ball_name = ball_name;
	}
	string getBallName(void) {
		return this->ball_name;
	}
	void setBallStatus(int ball_status) {
		this->ball_status = ball_status;
	}
	int getBallStatus(void) {
		return this->ball_status;
	}
};



