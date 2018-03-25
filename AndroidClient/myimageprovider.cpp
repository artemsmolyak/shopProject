#include "myimageprovider.h"


MyImageProvider::MyImageProvider(Client *client): QQuickImageProvider(QQuickImageProvider::Pixmap)
{
    this->client = client;
}

MyImageProvider::~MyImageProvider()
{

}


QPixmap MyImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{

    QStringList list = id.split("/");

    if   (list[0] == "product"){
        QByteArray imgByteArray = client->getImageProductMap().value(list[1]);

        QImage img;
        img.loadFromData(imgByteArray);

        QPixmap pixmap =QPixmap::fromImage(img);
        return pixmap;
    }
    else if   (list[0] == "catalog"){
        QByteArray imgByteArray = client->getImageCatalogMap().value(list[1]);

        QImage img;
        img.loadFromData(imgByteArray);

        QPixmap pixmap =QPixmap::fromImage(img);
        return pixmap;
    }

}
