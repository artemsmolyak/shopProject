#include "product.h"

Product::Product()
{

}

//Product::Product(QObject *parent):QObject(parent)
//{
//    m_id = 1;
//    m_name = "sdfsdfds";
//}

Product::Product(int id, QString name, QByteArray pic,  int price):
    m_id(id), m_name(name), m_pic(pic), m_price(price)
{

}


Product::Product(const Product &data)
{
     m_id = data.m_id;
     m_name = data.m_name;
     m_pic = data.m_pic;
     m_price = data.m_price;
}



int Product::id() const
{
    return m_id;
}

void Product::setId(int value)
{
    m_id = value;
}

QString Product::name() const
{
    return m_name;
}

void Product::setName(const QString &value)
{
    m_name = value;
}


int Product::price() const
{
    return m_price;
}

void Product::setPrice(int value)
{
    m_price = value;
}



Product Product::operator =(Product data)
{
       this->m_id = data.m_id;
       this->m_name = data.m_name;
       this->m_pic = data.m_pic;
       this->m_price = data.m_price;

    return *this;
}

Product::~Product()
{

}

QDataStream& operator <<(QDataStream& stream, const Product& data)
{
     stream << data.id();
     stream << data.name();
     stream << data.pic();
     stream << data.price();
}

QDataStream& operator >>(QDataStream& stream, Product & data)
{
    int id;
    stream >> id;
    data.setId(id);

    QString name;
    stream >> name;
    data.setName(name);

    QByteArray image;
    stream >> image;
    data.setPic(image);

    int price;
    stream >> price;
    data.setPrice(price);

    return stream;
}
