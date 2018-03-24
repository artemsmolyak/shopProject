#include "product.h"

QString Product::detail() const
{
    return m_detail;
}

void Product::setDetail(const QString &detail)
{
    m_detail = detail;
}

bool Product::isMain() const
{
    return m_isMain;
}

void Product::setIsMain(bool isMain)
{
    m_isMain = isMain;
}

Product::Product()
{

}

//Product::Product(QObject *parent):QObject(parent)
//{
//    m_id = 1;
//    m_name = "sdfsdfds";
//}

Product::Product(int id, QString name,  int price, QString detail, QByteArray pic, bool isMain):
    m_id(id), m_name(name), m_price(price), m_detail(detail), m_pic(pic), m_isMain(isMain)
{

}


Product::Product(const Product &data)
{
     m_id = data.m_id;
     m_name = data.m_name;
     m_pic = data.m_pic;
     m_price = data.m_price;
     m_detail = data.m_detail;
     m_isMain = data.m_isMain;
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
       this->detail() = data.detail();
       this->m_price = data.m_price;
       this->m_isMain = data.m_isMain;

    return *this;
}

Product::~Product()
{

}


QDataStream& operator <<(QDataStream& stream, const Product& data)
{
     stream << data.id();
     stream << data.name();
     stream << data.price();
     stream << data.detail();
     stream << data.pic();
     stream << data.isMain();

     return stream;
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

    QString detail;
    stream >> detail;
    data.setDetail(detail);

    QByteArray image;
    stream >> image;
    data.setPic(image);

    bool isMain;
    stream >> isMain;
    data.setIsMain(isMain);

    return stream;
}
