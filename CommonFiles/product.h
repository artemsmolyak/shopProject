#ifndef PRODUCT_H
#define PRODUCT_H

#include "QString"
#include <QImage>

class Product
{
    int id;
    QString name;
    QImage pic;
    int price;



public:
    Product();
    Product(int id, QString name, QImage pic,  int price);
    Product(int id, QString name, int price);
    int getId() const;
    void setId(int value);
    QString getName() const;
    void setName(const QString &value);
    QImage getPic() const;
    void setPic(const QImage &value);
    int getPrice() const;
    void setPrice(int value);
};


QDataStream& operator <<(QDataStream& stream, const Product& data);

QDataStream& operator >>(QDataStream& stream, Product& data);

#endif // PRODUCT_H
