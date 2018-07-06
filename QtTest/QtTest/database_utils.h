#include<QSQL>
#include<QMap>
#include<QList>
class DataBaseUtils {
private:
	const QString DRIVER_NAME = "QMYSQL";
	const QString DATABASE_ALIAS = "pinballpro_db";
	const QString HOSTNAME = "127.0.0.1";
	const int PORT = 3306;
	const QString USERNAME = "Penistrong";
	const QString PASSWORD = "chenliwei";

	bool db_connect(const QString &dbName);
public:
	DataBaseUtils() {};
	~DataBaseUtils() {};
protected:
	//CRUD baseFunctions
	bool add(const QString &sql, QMap<QString, QString> params);
	bool addBatch(const QString &sql, QList<QMap<QString,QString>> param_list);

	bool del(const QString &sql,QMap<QString,QString> params);
	bool delBatch(const QString &sql, QList<QMap<QString,QString>> param_list);

	bool update(const QString &sql, QMap<QString, QString> params);
	bool updateBatch(const QString &sql, QList<QMap<QString, QString>> param_list);

	bool selectOne(const QString &sql, QMap<QString, QString> params);
	bool selectList(const QString &sql, QMap<QString, QString> params);
};
