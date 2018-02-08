#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include "QThread"
#include <QTcpSocket>
#include <QObject>
#include <database.h>
#include <../CommonFiles/product.h>

class Worker : public QThread
{
     Q_OBJECT
    DataBase *db;

public:
    Worker(DataBase *db,  int socketDescriptor,  QObject *parent = 0);

    ~Worker();


    void run()  override;


public slots:
    void readyRead();
    void disconnected();


private:
    int socketDescriptor;
    QTcpSocket *clientSocket;

};

#endif // SOCKETTHREAD_H
