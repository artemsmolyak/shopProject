#ifndef DATABASE_H
#define DATABASE_H


#include <QObject>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <../CommonFiles/product.h>

class DataBase : public QObject
{
     QSqlDatabase db;


public:
    DataBase();

    QSqlError connect();
    QSqlError createMainTable();
    QSqlError createUsersTable();
    QVector <Product> getAll();
    QSqlError createUser(QString login, QString password);
    bool isUserExist(QString login, QString password);

    QString getHash(QString str);
};

#endif // DATABASE_H
