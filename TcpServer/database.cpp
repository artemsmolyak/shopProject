#include "database.h"
#include <QDir>
#include <QtSql/QSqlQuery>

DataBase::DataBase()
{
        connect();
        createMainTable();
}


QSqlError DataBase::connect()
{

        if (!QSqlDatabase::drivers().contains("QSQLITE"))
        {
             qDebug() <<  "Unable to load database. Needs the SQLITE driver";
        }
        else
        {
            db = QSqlDatabase::addDatabase("QSQLITE");
            qDebug() << "connecting to database " << QDir::homePath()+"/shop.sqlite";
        }

         db.setDatabaseName(QDir::homePath()+"/shop.sqlite");



        if (!db.open())
           {
               qDebug() << "Error: connection with database fail" << db.lastError();
           }
           else
           {
               qDebug() << "Database: connection ok";
           }



        return QSqlError();
}




QSqlError DataBase::createMainTable()
{
        QSqlQuery q;

        if (!q.exec(QLatin1String("create table IF not EXISTS shop"
                                              "(id integer primary key,  "
                                               "name TEXT, "
                                               "pics BLOB,  "
                                                "price integer "
                                              ")")))
            return q.lastError();

        return q.lastError();
}

QVector<Product> DataBase::getAll()
{
    QVector <Product> products;
    QSqlQuery q;
    q.prepare("select * from shop");
    q.exec();

    while (q.next()) {
           int id = q.value(0).toInt();
           QString name = q.value(1).toString();
           int  price = q.value(3).toInt();

           Product product(id, name, price);
           products.push_back(product);
    }

    return products;
}

void DataBase::createUser()
{

}
