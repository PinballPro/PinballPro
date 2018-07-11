#include "db_utils.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QSqlDatabase>
#include <QVariant>
#include <QDateTime>
#include <QMap>
#include "player.h"

DB_Utils::DB_Utils(QWidget *parent) : QMainWindow(parent) ,currentPlayer(new Player()){

}

DB_Utils::~DB_Utils() {

}

bool DB_Utils::connection() {
	if (QSqlDatabase::contains("qt_sql_default_connection")) {
		db = QSqlDatabase::database("qt_sql_default_connection");
	}
	else {
		db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("PinBallPro.db");
		db.setUserName("PinBall");
		db.setPassword("huster2017");
	}
	if (!db.open()) {
		qDebug() << db.lastError();
		return false;
	}
	else {//如果数据库打开 接着检查表是否都存在
		checkTable();//检查表，不存在则创建
		return true;
	}
}

void DB_Utils::checkTable() {
	QSqlQuery query(db);
	QString create_table_sql;
	if (!query.exec(QString("select count(*) from sqlite_master where type='table' and name = '%1'").arg("player_info"))) {
		create_table_sql = "create table player_info (player_name TEXT, password TEXT, register_time TEXT, last_sign_in_time TEXT)";
		query.exec(create_table_sql);
	}
	if (!query.exec(QString("select count(*) from sqlite_master where type='table' and name = '%1'").arg("player_repertoire"))) {
		create_table_sql = "create table player_repertoire (player_name TEXT, password TEXT, highest_score TEXT,  TEXT, )";
		query.exec(create_table_sql);
	}
}

bool DB_Utils::execSql(QString sql,QList<QString> params) {
	if (this->connection()) {
		QSqlQuery exec_sql(db);
		exec_sql.prepare(sql);
		for (int j = 0;j<params.length();j++) {
			exec_sql.bindValue(j, params.at(j));
		}
		if (!exec_sql.exec()) {
			exec_sql.finish();
			return false;
		}
		else {
			exec_sql.finish();
			return true;
		}
	}
	else {
		return false;
	}
}

QSqlQuery DB_Utils::query_player(QString sql, QList<QString> params) {
	if (this->connection()) {
		QSqlQuery query_sql(db);
		query_sql.prepare(sql);
		for (int j = 0;j < params.length();j++) {
			query_sql.bindValue(j, params.at(j));
		}
		if (query_sql.exec()) {
			return query_sql;
		}
		else {
			qDebug() << db.lastError();
			return query_sql;
		}
	}
	else {
		qDebug() << db.lastError();
		QSqlQuery failed_sql(db);
		return failed_sql;
	}
}

bool DB_Utils::sign_in(QString player_name,QString password) {
	QList<QString> params;
	params.append(player_name);
	params.append(password);
	QString sql = "Select * from player_info where player_name = ? and password = ?";
	QSqlQuery result = this->query_player(sql, params);
	if (result.first()) {
		//存在用户则更新上次登录的时间
		QString update_sign_in_time = "Update player_info set last_sign_in_time = ? where player_name = ? and password = ?";
		params.push_front(QString::QString(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
		this->execSql(update_sign_in_time, params);
		initCurrentPlayerInfo(result);//存储当前角色信息
		return true;
	}
	else {
		//不存在则注册
		QString register_player = "Insert into player_info(player_name, password, register_time,last_sign_in_time) values(?,?,?,?)";
		params.append(QString::QString(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
		params.append(QString::QString(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));
		if (this->execSql(register_player, params)) {
			//主表注册玩家成功后,在副表建立玩家信息
			QString register_repertoire = "Insert into player_repertoire values(?,?,?,?)";
			params.removeLast();
			params.removeLast();
			params.append("0");
			params.append("0");
			this->execSql(register_repertoire, params);
			params.removeLast();
			params.removeLast();
			initCurrentPlayerInfo(this->query_player(sql, params));//存储当前玩家信息
			return true;
		}
		else return false;
	}
}

void DB_Utils::initCurrentPlayerInfo(QSqlQuery result) {
	QString player_name = result.value(0).toString();
	QString password = result.value(1).toString();
	QString highest_score = result.value(2).toString();
	QString total_rounds = result.value(3).toString();
	this->currentPlayer = new Player(player_name, password, highest_score, total_rounds);
}