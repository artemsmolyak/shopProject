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
    //client->sendRequest(getGoods);
    //QImage img("/home/artem/Pictures/shop/1.png");
    //

    QByteArray imgByteArray = client->getImageMap().value(id);

    QImage img;
    img.loadFromData(imgByteArray);

    QPixmap pixmap =QPixmap::fromImage(img);
    return pixmap;
}
