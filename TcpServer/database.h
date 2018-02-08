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
    QVector <Product> getAll();
    void createUser();
};

#endif // DATABASE_H
