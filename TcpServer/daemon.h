#ifndef DAEMON_H
#define DAEMON_H

#include "QTcpServer"
#include <database.h>
#include <QtGlobal>

class Daemon : public QTcpServer
{
    Q_OBJECT

     DataBase * db;

public:
    Daemon(int port, QObject * parent = 0);
    ~Daemon();

protected:
    void incomingConnection(qintptr socketDescriptor) override;



};

#endif // DAEMON_H
