#include "client.h"
#include <QDataStream>
#include <QHostAddress>
#include <../CommonFiles/product.h>





Client::Client()
{
    clientSocket =new QTcpSocket();
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readAnswerFromServer()));
     clientSocket->connectToHost(QHostAddress::LocalHost, 55555);



     qDebug() << "wait for connect....";
     clientSocket->waitForConnected();

     qDebug() << "connected";

     QByteArray ba;

     QDataStream stream(&ba, QIODevice::ReadWrite);

     qDebug() << "send goods" <<  getGoods;
     stream<< getGoods;

     clientSocket->write(ba);
     clientSocket->flush();



}

void Client::readAnswerFromServer()
{
    qDebug() << "we ahve answer";
    QByteArray ba =  clientSocket->readAll();



    QDataStream in(&ba, QIODevice::ReadOnly);

   int answerCommand;
   in >> answerCommand;

   qDebug()<<"answer command" << answerCommand;

   switch (answerCommand) {
   case getGoods:
   {
       QVector <Product> products;
       in >> products;

       qDebug() << "products size " <<products.size();

     }
       break;

   case newUser:

       break;

   case auth:

       break;

   case testPing:

       break;



   default:
       break;
   }


     //qDebug() << "answer: "<<answer;
}
