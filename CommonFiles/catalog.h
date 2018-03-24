#ifndef CATALOG_H
#define CATALOG_H

#include <QObject>

class Catalog : public QObject
{
    Q_OBJECT
    
    int m_id;
    QString m_name;
    QByteArray m_pic;
    
    
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    
    
public:
    Catalog();
    Catalog(int id, QString name, QByteArray pic);
    Catalog(const Catalog &data);
    Catalog operator=(Catalog data);


    
    int id() const;
    void setId(int id);
    QString name() const;
    void setName(const QString &name);
    QByteArray pic() const;
    void setPic(const QByteArray &pic);
    
    
signals:
    void idChanged();
    void nameChanged();
    
    
};


QDataStream& operator <<(QDataStream& stream, const Catalog& data);

QDataStream& operator >>(QDataStream& stream, Catalog& data);

Q_DECLARE_METATYPE(Catalog)

#endif // CATALOG_H
