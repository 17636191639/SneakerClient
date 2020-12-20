#ifndef SHOPCART_H
#define SHOPCART_H
#include <QString>

class ShopCart
{
public:
    ShopCart();
    ShopCart(const QString &id, const QString &detailID, const QString &count);

    void setID(const QString &id);
    void setDetailID(const QString &detailID);
    void setCount(const QString &count);

    const QString &getID() const;
    const QString &getDetailID() const;
    const QString &getCount() const;
private:
    QString m_id;
    QString m_detailID;
    QString m_count;
};

typedef QList<ShopCart> ShopCartList;
#endif // SHOPCART_H
