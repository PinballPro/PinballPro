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
	bool connection();//�������ݿⲢ��鱾�ر�����
	void checkTable();//����Ĵ�����
protected:
	//CRUD base functions
	bool execSql(QString sql, QList<QString> params);
	QSqlQuery query_player(QString sql, QList<QString> params);
};
