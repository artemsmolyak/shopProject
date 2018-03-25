#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QObject>
#include <QQmlContext>
#include <../CommonFiles/product.h>
#include <../CommonFiles/catalog.h>
#include <../CommonFiles/const.h>
#include <QMap>


class Client : public QObject
{
    Q_OBJECT

    QTcpSocket * clientSocket;
    QQmlContext *qml_root_context;
    QObject * qml_root;

    qint32 blockSize;

    QMap <QString, QByteArray>  imageProductMap;
    QMap <QString, QByteArray>  imageCatalogMap;



    QList<QObject*> productsModel;
    QList<QObject*> catalogsModel;



public:
    Client(QObject *parent = nullptr);
    ~Client();

    void setQmlRootContext(QQmlContext *root);
    void setQmlRoot(QObject *root);

    void sendRequest(Request request, QVector<QString> params = QVector<QString>());

    Q_INVOKABLE void fillMainList();
    Q_INVOKABLE void fillCatalogList();







    QMap<QString, QByteArray> getImageProductMap() const;

    QMap<QString, QByteArray> getImageCatalogMap() const;

public slots:
    void readAnswerFromServer();
    void slotError(QAbstractSocket::SocketError error);
    void serverDisconnected();

    void setMainProductModel(QVector <Product> products);
    void setCatalogsModel(QVector <Catalog> catalogs);


signals:
   void getAnswer(QVector <Product>  products);
   void getAnswer(QVector <Catalog>  products);

};

#endif // CLIENT_H
