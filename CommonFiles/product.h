#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include "QString"
#include <QImage>
#include <QDataStream>

class Product : public QObject
{
    Q_OBJECT

    int m_id;
    QString m_name;
    int m_price;
    QString m_detail;
    bool m_isMain;

    QByteArray m_pic;


     Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
     Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
     Q_PROPERTY(int price READ price WRITE setPrice NOTIFY priceChanged)
     Q_PROPERTY(QString detail READ detail WRITE setDetail NOTIFY detailChanged)
     Q_PROPERTY(bool isMain READ isMain WRITE setIsMain NOTIFY isMainChanged)


public:

    Product();
    Product(int id, QString description, int price, QString detail, QByteArray pic, bool isMain);

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


    QString detail() const;
    void setDetail(const QString &detail);

    bool isMain() const;
    void setIsMain(bool isMain);


signals:
    void idChanged();
    void nameChanged();
    void priceChanged();
    void detailChanged();
    void isMainChanged();
};


QDataStream& operator <<(QDataStream& stream, const Product& data);

QDataStream& operator >>(QDataStream& stream, Product& data);

Q_DECLARE_METATYPE(Product)

#endif // PRODUCT_H
