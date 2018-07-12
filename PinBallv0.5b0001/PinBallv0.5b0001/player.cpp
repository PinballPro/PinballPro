#include "player.h"
#include <QString>

Player::Player() {
	//Ä¬ÈÏ¹¹Ôì
}

Player::Player(QString player_name, QString password, QString highest_score, QString total_rounds) {
	this->player_name = player_name;
	this->password = password;
	this->highest_score = highest_score;
	this->total_rounds = total_rounds;
}

QString Player::getPassword() {
	return this->password;
}