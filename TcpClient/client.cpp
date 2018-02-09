#include "client.h"
#include <QDataStream>
#include <QHostAddress>
#include <../CommonFiles/product.h>
#include <../CommonFiles/const.h>




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

     qDebug() << "send newUser";
     stream<< auth;

     stream<< QString("login");
     stream<< QString("pass");


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

         qDebug() << "user is created";

         break;

   case auth:
         {
           bool answer;
           in >> answer;

           if (answer)
               qDebug() << "user is exist";
           else
               qDebug() << "user is not exist";

           break;
         }
   case testPing:

       break;

    case error:
            {
                 QString errorStr;
                 in >> errorStr;
                 qDebug() << "error" << errorStr;
                 break;
            }

   default:
       break;
   }


     //qDebug() << "answer: "<<answer;
}
