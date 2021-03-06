#ifndef DATABASE_H
#define DATABASE_H


#include <QObject>
#include <QtSql/QSqlError>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <../CommonFiles/product.h>
#include <../CommonFiles/catalog.h>.h>

class DataBase : public QObject
{
     QSqlDatabase db;


public:
    DataBase();

    QSqlError connect();

    //create
    QSqlError createMainTable();
    QSqlError createUsersTable();
    QSqlError createUser(QString login, QString password);


    //select
    QVector<Product> getAll();
    QVector <Catalog> getCategory();




    bool isUserExist(QString login, QString password);

    QString getHash(QString str);
};

#endif // DATABASE_H
