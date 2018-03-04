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
     //clientSocket->deleteLater();
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
    streamAnswer << (quint32)0;

    qint32 command;


    stream >> command;

    qDebug() << "command " << command;

        switch(command)
        {
                case getGoods:
                {
                        streamAnswer << (qint32)getGoods;
                        qDebug() << "getGoods " <<  (qint32)getGoods;;
                        QVector <Product> products = db->getAll();

                        qDebug() << "products size " << products.size();

                        if (products.size() > INT32_MAX){
                            qDebug() << "the data is too big. can't be sending";
                            break;
                        }

                        streamAnswer << products;

                        break;
                }
                case newUser:
                {

                        qDebug() << "new user";

                        QString login;
                        stream >> login;

                        QString password;
                        stream >> password;


                        if (login.isEmpty() || password.isEmpty()){
                                streamAnswer << error;
                                streamAnswer<<QString("wrong parameters");
                                break;
                        }

                        if (db->isUserExist(login, password)){
                                streamAnswer << error;
                                streamAnswer<<QString("user is exist");
                                break;
                        }


                        qDebug() <<"db";
                        password = db->getHash(login+password);
                        db->createUser(login, password);
                        streamAnswer << newUser;


                        break;
                }
                case auth:
                {
                        qDebug() << "auth";
                        QString login;
                        stream >> login;

                        QString password;
                        stream >> password;


                        if (login.isEmpty() || password.isEmpty()){
                                streamAnswer << error;
                                streamAnswer<<QString("wrong parameters");
                                break;
                        }


                        streamAnswer << auth;
                       if (db->isUserExist(login, password))
                                 streamAnswer << true;
                       else
                                 streamAnswer << false;


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
                        streamAnswer <<QString("dont know such request");
                        break;

        }

        streamAnswer.device()->seek(0);
        streamAnswer << (qint32)(barrayOut.size() - sizeof(qint32));

        qDebug() << "send block size " << (qint32)(barrayOut.size() - sizeof(qint32)) << barrayOut.size() ;


    clientSocket->write(barrayOut);
    clientSocket->flush();

    //clientSocket->disconnectFromHost();
    //clientSocket->waitForDisconnected();
}


void Worker::disconnected()
{
        qDebug() << "client disconnected()";
        //clientSocket->close();
        clientSocket->deleteLater();
        exit(0);
}
