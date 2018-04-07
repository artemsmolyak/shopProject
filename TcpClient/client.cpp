#include "client.h"
#include <QDataStream>
#include <QHostAddress>
#include <QDebug>
#include <algorithm>
#include <../CommonFiles/catalog.h>


QMap<QString, QByteArray> Client::getImageProductMap() const
{
    return imageProductMap;
}

QMap<QString, QByteArray> Client::getImageCatalogMap() const
{
    return imageCatalogMap;
}

Client::Client(QObject *parent): QObject(parent), blockSize(0)
{
    clientSocket =new QTcpSocket();
    clientSocket->setReadBufferSize(0);

     connect(clientSocket, SIGNAL(readyRead()), this, SLOT(readAnswerFromServer()));
     connect(clientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));
     clientSocket->connectToHost(QHostAddress::LocalHost, 55555);
     connect(clientSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));



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
    qDebug() << "fillMainList";

      connect(this, SIGNAL(getAnswer(QVector <Product>)),  this,  SLOT(setMainProductModel(QVector <Product>)));
      sendRequest(getGoods);
}

void Client::fillCatalogList()
{
    qDebug() << "fillCatalogList";

     connect(this, SIGNAL(getAnswer(QVector <Catalog>)),  this, SLOT(setCatalogsModel(QVector <Catalog>)));
     sendRequest(getCatalogs);
}

bool Client::connectToServer()
{
    qDebug() << "wait for connect....";
    if (clientSocket->waitForConnected(10000))
    {
          qDebug() << "connected";
          return true;
    }
    else{
        qDebug() << "no connect";
        return false;
    }

}

void Client::setMainProductModel(QVector<Product> products)
{
     qDebug() << "setMainProductModel";


    for(QVector <Product>::iterator it = products.begin(); it != products.end(); ++it){

        Product prod = *it;

        if (prod.isMain()){

            productsModel.append(new Product(prod));

            int key = prod.id();
            QByteArray img = prod.pic();
            imageProductMap.insert(QString::number(key), img);
        }
    }

     if (qml_root_context){
            qml_root_context->setContextProperty("myModel1", QVariant::fromValue(productsModel));
     }

//     QObject * obj = qml_root->findChild<QObject*>("mainPage");
//     if (obj)
//     {
//          QMetaObject::invokeMethod(obj, "update");
//     }
//     else
//     {
//         qDebug() << "there is no object";
//     }
}

void Client::setCatalogsModel(QVector<Catalog> catalogs)
{
        qDebug() << "setCatalogsModel";

    for(QVector <Catalog>::iterator  it  = catalogs.begin(); it != catalogs.end(); ++it){

        Catalog catalog = *it;

        catalogsModel.append(new Catalog(catalog));

        int key = catalog.id();
        QByteArray img = catalog.pic();
        imageCatalogMap.insert(QString::number(key), img);
    }

     if (qml_root_context){
            qml_root_context->setContextProperty("catalogsModel", QVariant::fromValue(catalogsModel));
     }

    // disconnect(this, &Client::getAnswer, this, SLOT(setCheckedall(bool)));

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
            QVector <Product>  products;
            in >> products;

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

         case getCatalogs:
        {
            QVector<Catalog> catalogs;
            in >> catalogs;

            qDebug() << "catalogs size " <<catalogs.size();

            emit getAnswer(catalogs);
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
