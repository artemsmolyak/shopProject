#include "daemon.h"
#include "QTcpSocket"
#include "socketthread.h"

Daemon::Daemon(int port, QObject *parent): QTcpServer(parent)
{
        if (!listen(QHostAddress::Any, port)) {
               qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(errorString());
           } else {
               qDebug() << QString::fromUtf8("Сервер запущен!");
        }

        db = new DataBase;
}

void Daemon::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << "incoming connection";

    Worker *thread = new Worker(db, socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

Daemon::~Daemon()
{
           qDebug() << QString::fromUtf8("Сервер остановлен!");
}

