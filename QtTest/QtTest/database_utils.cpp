#include "database_utils.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QMap>
#include <QMapIterator>
//连接至数据库pinballpro_db@localhost:3306 db_version:mysql
bool DataBaseUtils::db_connect(const QString &dbName) {
	QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER_NAME);
	db.setDatabaseName(DATABASE_ALIAS);
	db.setHostName(HOSTNAME);
	db.setPort(PORT);
	db.setUserName(USERNAME);
	db.setPassword(PASSWORD);
	if (!db.open()) {
		qDebug << db.lastError();
		return false;
	}
}

bool DataBaseUtils::add(const QString &sql, QMap<QString, QString> params) {
	if (this->db_connect(DATABASE_ALIAS)) {
		QSqlQuery query;
		query.prepare(sql);
		QMapIterator<QString, QString> i(params);
		for (int j = 0;i.hasNext();j++) {
			query.bindValue(j, i.value);
		}
		if (!query.exec()) {
			query.finish();
			return false;
		}
		else {
			query.finish();
			return true;
		}
	}
}