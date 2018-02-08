#include "product.h"

int Product::getId() const
{
    return id;
}

void Product::setId(int value)
{
    id = value;
}

QString Product::getName() const
{
    return name;
}

void Product::setName(const QString &value)
{
    name = value;
}

QImage Product::getPic() const
{
    return pic;
}

void Product::setPic(const QImage &value)
{
    pic = value;
}

int Product::getPrice() const
{
    return price;
}

void Product::setPrice(int value)
{
    price = value;
}

Product::Product()
{

}

Product::Product(int id, QString name, QImage pic, int price):
    id(id), name(name), pic(pic), price(price)
{

}

Product::Product(int id, QString name, int price):
     id(id), name(name), price(price)
{

}

QDataStream& operator <<(QDataStream& stream, const Product& data)
{
     stream << data.getId() << data.getName() << data.getPrice();
}

QDataStream& operator >>(QDataStream& stream, Product & data)
{
    int id;
    stream >> id;
    data.setId(id);

    QString name;
    stream >> name;
    data.setName(name);

    int price;
    stream >> price;
    data.setPrice(price);

    return stream;
}
