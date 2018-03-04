#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include "QString"
#include <QImage>

class Product : public QObject
{
    Q_OBJECT

    int m_id;
    QString m_name;
    int m_price;
    QByteArray m_pic;


     Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
     Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
     Q_PROPERTY(int price READ price WRITE setPrice NOTIFY priceChanged)


public:

    Product();
    Product(int id, QString name, QByteArray pic, int price);
    Product(const Product &data);
    Product operator=(Product prod);

    ~Product();

    int id() const;
    void setId(int value);

    QString name() const;
    void setName(const QString &value);

    int price() const;
    void setPrice(int value);

    QByteArray pic()const {return m_pic;};
    void setPic(QByteArray pic){m_pic = pic;};


public slots:


signals:
    void idChanged();
    void nameChanged();
    void priceChanged();
};


QDataStream& operator <<(QDataStream& stream, const Product& data);

QDataStream& operator >>(QDataStream& stream, Product& data);

Q_DECLARE_METATYPE(Product)

#endif // PRODUCT_H
