#include "client.h"
#include <QDataStream>
#include <QHostAddress>
#include <QDebug>



QMap<QString, QByteArray> Client::getImageMap() const
{
    return imageMap;
}

Client::Client(QObject *parent): QObject(parent), blockSize(0)
{
    clientSocket =new QTcpSocket();
    clientSocket->setReadBufferSize(0);

     connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readAnswerFromServer()));
     connect(clientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));
     clientSocket->connectToHost(QHostAddress::LocalHost, 55555);
     connect(clientSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));

     qDebug() << "wait for connect....";
     clientSocket->waitForConnected();

     qDebug() << "connected";

}

Client::~Client(){
      qDebug() << "destractor";
}


void Client::sendRequest(Request request, QVector<QString> params){

    QByteArray ba;

    QDataStream stream(&ba, QIODevice::ReadWrite);

    qDebug() << "send " <<(Request)request;
    stream<< request;

    for(auto it = params.begin(); it != params.end(); ++it){
           stream<< *it;
    }


    clientSocket->write(ba);
    clientSocket->flush();

}

void Client::fillMainList()
{
    qDebug() << "fillllllllll";

    QStringList lst;
    lst << "first" << "second" << "sdfsdfsdfsd" <<"!@#&!#&";

    qDebug() <<"qml_root_context: " <<  qml_root_context;

    if (qml_root_context)
    {
        qDebug() << "set model";
              qml_root_context->setContextProperty("myModel", QVariant::fromValue(lst));
    }



      connect(this, &Client::getAnswer,  [this] (QVector <Product> products){ this->setMainProductModel(products); });
      sendRequest(getGoods);
}

void Client::setMainProductModel(QVector<Product> products)
{
    QList<QObject*> productsModel;

    for(QVector <Product>::iterator it = products.begin(); it != products.end(); ++it){
        productsModel.append(it);
        qDebug() << "append";
        Product prod = *it;
        int key = prod.id();
        QByteArray img = prod.pic();
        imageMap.insert(QString::number(key), img);
    }


    qDebug() << "setMainProductModel";

//    Product * pr = new Product();
//    pr->setId(2);
//    pr->setName("name'");
//    pr->setPrice(255);
//    productsModel.append(pr);


//   Product * pr2 = new Product();
//   pr2->setId(2);
//   pr2->setName("name'");
//   pr2->setPrice(255);

//   productsModel.append(pr2);
//   productsModel.append(pr);


//   productsModel.append(pr2);
//   productsModel.append(pr);
//   productsModel.append(pr2);
//   productsModel.append(pr);


//   Product * prrrr = (Product*)productsModel.at(1);
//   qDebug() << "price " << prrrr->price();



   QStringList lst;
   lst << "first" << "second" << "sdfsdfsdfsd" <<"!@#&!#&";
     if (qml_root_context){
            qml_root_context->setContextProperty("myModel1", QVariant::fromValue(productsModel));

             //qml_root_context->setContextProperty("myModel", QVariant::fromValue(lst));

              qDebug() << "SET!!!!!!!!!!! " << productsModel.size() << lst;
     }



     QObject * obj = qml_root->findChild<QObject*>("mainPage");
     if (obj)
     {
          QMetaObject::invokeMethod(obj, "update");
     }
     else
     {
         qDebug() << "there is no object";
     }

}


void Client::readAnswerFromServer()
{
    qDebug() << "we have answer";
    //QByteArray ba =  clientSocket->readAll();


    QDataStream in(clientSocket);


        if (!blockSize){

            if (clientSocket->bytesAvailable() < sizeof(quint32)){
                qDebug() << "/// bytesAvailable " << 0;
                return;
            }
            in >> blockSize;
        }


        qDebug() <<"clientSocket->bytesAvailable " << clientSocket->bytesAvailable();
        if (clientSocket->bytesAvailable() < blockSize)
            return;





        // if (clientSocket->bytesAvailable() < blockSize){
        qDebug() << "client bytes available " << clientSocket->bytesAvailable();
        //  return;
        // }


        qint32 answerCommand;
        in >> answerCommand;

        qDebug()<<"answer command" << answerCommand;

        blockSize = 0;

        switch (answerCommand) {
        case getGoods:
        {
            QVector <Product> products;
            in >> products;

            qDebug() << "products size " <<products.size();


            //Product pr = products.at(0);
            //QImage img = pr.pic();

            //qDebug() <<"image "<< img.width() << img.height();

            emit getAnswer(products);

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
            qDebug() << "there is no sudh command ";
            break;
        }


    qDebug() << "out from loop: ";
}

void Client::slotError(QAbstractSocket::SocketError err)
{
    QString strError=
            "Error:"+(err==QAbstractSocket::HostNotFoundError?
            "The host was not found." :
            err==QAbstractSocket::RemoteHostClosedError ?
            "The remote host is closed." :
            err==QAbstractSocket::ConnectionRefusedError ?
                "The connection was refused." :
            QString(clientSocket->errorString())
            );
            qDebug() << strError;

}

void Client::serverDisconnected()
{
    qDebug() << "server is disconnected";
    clientSocket->close();
}


void Client::setQmlRootContext(QQmlContext *root)
{
    if (qml_root_context == root)
        return;
    qml_root_context = root;


}


void Client::setQmlRoot(QObject *root)
{
    if (qml_root == root)
        return;

    qml_root = root;
}
