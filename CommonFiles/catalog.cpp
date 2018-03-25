#include "catalog.h"

int Catalog::id() const
{
    return m_id;
}

void Catalog::setId(int id)
{
    m_id = id;
}

QString Catalog::name() const
{
    return m_name;
}

void Catalog::setName(const QString &name)
{
    m_name = name;
}

QByteArray Catalog::pic() const
{
    return m_pic;
}

void Catalog::setPic(const QByteArray &pic)
{
    m_pic = pic;
}

Catalog::Catalog(QObject * parent): QObject(parent)
{

}

Catalog::Catalog(int id, QString name, QByteArray pic): m_id(id), m_name(name), m_pic(pic)
{

}

Catalog::Catalog(const Catalog &data)
{
    m_id = data.m_id;
    m_name = data.m_name;
    m_pic = data.m_pic;
}


Catalog Catalog::operator=(Catalog data)
{
    this->m_id = data.m_id;
    this->m_name = data.m_name;
    this->m_pic = data.m_pic;

    return *this;
}

Catalog::~Catalog()
{

}

QDataStream &operator >>(QDataStream &stream, Catalog &data)
{
   int iid;
   stream >> iid;
   data.setId(iid);

    QString name;
    stream >> name;
    data.setName(name);

    QByteArray image;
    stream >> image;
    data.setPic(image);

    return stream;
}

QDataStream &operator <<(QDataStream &stream, const Catalog &data)
{
    stream << data.id();
    stream << data.name();
    stream << data.pic();

    return stream;
}
