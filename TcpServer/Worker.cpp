#include "socketthread.h"
#include "QDataStream"
#include "QDebug"
#include "QByteArray"
#include "../CommonFiles/const.h"

Worker::Worker(DataBase *db, int socketDescriptor,  QObject *parent) :  db(db), socketDescriptor(socketDescriptor) , QThread(parent)
{
      qDebug() << "SocketThread::SocketThread";
 }

Worker::~Worker()
{
     qDebug() << "thread is ended";
     clientSocket->deleteLater();
}

void Worker::run()
{
       qDebug() << "new thread";
       clientSocket = new QTcpSocket();


      if (!clientSocket->setSocketDescriptor(socketDescriptor)) {
              qDebug() << "error connection";
             return;
         }


      connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
      connect(clientSocket, SIGNAL(disconnected()), this, SLOT(disconnected()));


     exec();
}


void Worker::readyRead(){

    qDebug() << "ready read";

    QByteArray barrayIn = clientSocket->readAll();

    qDebug() << "barray " << barrayIn;

    QDataStream stream(&barrayIn, QIODevice::ReadWrite);

    QByteArray barrayOut;
    QDataStream streamAnswer(&barrayOut, QIODevice::ReadWrite);

    int command;

    stream >> command;

    qDebug() << "command " << command;

        switch(command)
        {
                case getGoods:
                {
                        streamAnswer << getGoods;
                        qDebug() << "getGoods";
                        QVector <Product> products = db->getAll();

                        qDebug() << "products size " << products.size();

                        streamAnswer << products;

                        break;
                }
                case newUser:
                {
                        streamAnswer << newUser;
                        qDebug() << "new user";

                        break;
                }
                case auth:
                {
                        streamAnswer << auth;
                        qDebug() << "auth";

                        break;
                }
                case testPing:
                {
                        streamAnswer <<testPing;
                        qDebug() <<"  testPing ";
                        break;
                }

                default:
                        streamAnswer << error;

                        break;

        }


    clientSocket->write(barrayOut);
    clientSocket->flush();

    clientSocket->disconnectFromHost();
    clientSocket->waitForDisconnected();
}


void Worker::disconnected()
{
        qDebug() << "disconnected()";
        clientSocket->deleteLater();
        exit(0);
}
