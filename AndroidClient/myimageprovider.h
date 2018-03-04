#ifndef MYIMAGEPROVIDER_H
#define MYIMAGEPROVIDER_H

#include <qquickimageprovider.h>
#include <../TcpClient/client.h>
#include <QPixmap>


class MyImageProvider : public QQuickImageProvider
{
    Client * client;

public:

    MyImageProvider(Client * client);

      ~MyImageProvider();
      QPixmap  requestPixmap(const QString & id, QSize * size, const QSize & requestedSize);



};

#endif // MYIMAGEPROVIDER_H
