#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
enum Request
{
    getGoods,
    newUser,
    auth,
    testPing
};


class Client : public QObject
{
    Q_OBJECT

    QTcpSocket * clientSocket;

public:
    Client();

 public slots:
    void readAnswerFromServer();

};

#endif // CLIENT_H
