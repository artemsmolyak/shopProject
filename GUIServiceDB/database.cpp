#include "database.h"
#include <QDir>
#include <QtSql/QSqlQuery>
#include "QCryptographicHash"

#include "QImage"
#include <QBuffer>

DataBase::DataBase()
{
        connect();
        createMainTable();
        createUsersTable();
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



        //
//        QImage pic("/home/artem/Pictures/shop/2.png");
//        QByteArray bArray;
//        QBuffer buf(&bArray);
//        buf.open(QIODevice::WriteOnly);
//        pic.save(&buf, "png");


//        QSqlQuery query;
//        query.prepare(QLatin1String("UPDATE shop "
//                                "SET pics = ?,    price = 700 WHERE id = 14  OR id = 13 "));

//        query.addBindValue(bArray);

//        qDebug() << "----------> save " <<  query.exec() <<query.lastError().text();

 //pics = ? AND


        return QSqlError();
}




QSqlError DataBase::createMainTable()
{
        QSqlQuery q;

        if (!q.exec(QLatin1String("create table IF not EXISTS shop"
                                              "(id integer primary key,  "
                                               "name TEXT, "
                                               "pics BLOB,  "
                                                "price integer,"
                                                "category TEXT"
                                              ")")))
            return q.lastError();

        return q.lastError();
}

QSqlError DataBase::createUsersTable()
{
    QSqlQuery q;

    if (!q.exec(QLatin1String("create table IF not EXISTS users"
                                          "(id integer primary key,  "
                                           "login TEXT, "
                                           "hash TEXT  "
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
           QByteArray bArrayPic = q.value(2).toByteArray();

//           QImage  pic;
//           pic.loadFromData(bArrayPic);
//           qDebug() << "image server "<< pic.width() << pic.height();

           int  price = q.value(3).toInt();
           Product product(id, name, bArrayPic, price);
           products.push_back(product);
    }

    return products;
}

QSqlError  DataBase::createUser(QString login, QString password)
{
    QSqlQuery query;
    query.prepare(QLatin1String("insert into users "
                            "(login, hash) "
                            " values(?, ?) "));

    query.addBindValue(login);
    query.addBindValue(password);

    query.exec();

    return query.lastError();
}

bool DataBase::isUserExist(QString login, QString password)
{
    qDebug() << "isUserExist";
    QSqlQuery query;

    query.prepare("SELECT hash FROM users WHERE login=?;");
    query.addBindValue(login);
    query.exec();


     while (query.next()) {

         QString hash = getHash(login + password);
         QString hash_bd = query.value(0).toString();

         qDebug() << "HASH: " << hash;
          qDebug() << "HASH DB: "<< hash_bd;

         if (hash == hash_bd)
                         return true;

          return false;
     }

     return false;
}

QString DataBase::getHash(QString str)
{
     return QString(QCryptographicHash::hash(str.toLocal8Bit(), QCryptographicHash::Md5));
}
