#include<QString>

class Player {
public:
	Player(QString player_name, QString password, QString highest_score, QString total_rounds);
	Player();

	QString player_name;
	QString highest_score;
	QString total_rounds;
private:
	QString password;
};
