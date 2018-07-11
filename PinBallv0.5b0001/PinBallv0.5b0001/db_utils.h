#include<QMainWindow>
#include<QSqlDatabase>
#include<QSqlquery>
#include<QSqlError>

class Player;
class DB_Utils : public QMainWindow{
public:
	DB_Utils(QWidget *parent = Q_NULLPTR);
	~DB_Utils();

	bool sign_in(QString playerName, QString );
	void initCurrentPlayerInfo(QSqlQuery result);

	Player *currentPlayer;
private:
	QSqlDatabase db;
	bool connection();//连接数据库并检查本地表的情况
	void checkTable();//检查表的存在性
protected:
	//CRUD base functions
	bool execSql(QString sql, QList<QString> params);
	QSqlQuery query_player(QString sql, QList<QString> params);
};
