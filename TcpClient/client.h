#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QObject>
#include <QQmlContext>
#include <../CommonFiles/product.h>
#include <../CommonFiles/const.h>
#include <QMap>

class Client : public QObject
{
    Q_OBJECT

    QTcpSocket * clientSocket;
    QQmlContext *qml_root_context;
    QObject * qml_root;

    qint32 blockSize;

    QMap <QString, QByteArray>  imageMap;

public:
    Client(QObject *parent = nullptr);
    ~Client();

    void setQmlRootContext(QQmlContext *root);
    void setQmlRoot(QObject *root);

    void sendRequest(Request request, QVector<QString> params = QVector<QString>());

    Q_INVOKABLE void fillMainList();

    void setMainProductModel(QVector <Product> products);


    QMap<QString, QByteArray> getImageMap() const;

public slots:
    void readAnswerFromServer();
    void slotError(QAbstractSocket::SocketError error);
    void serverDisconnected();


signals:
   void getAnswer(QVector <Product> products);

};

#endif // CLIENT_H
