#include "shopcart.h"

ShopCart::ShopCart()
{
    m_id.clear();
    m_detailID.clear();
    m_count.clear();

}
ShopCart::ShopCart(const QString &id, const QString &detailID, const QString &count)
{
    m_id = id;
    m_detailID = detailID;
    m_count = count;
}

void ShopCart::setID(const QString &id)
{
    m_id = id;
}
void ShopCart::setDetailID(const QString &detailID)
{
    m_detailID = detailID;
}
void ShopCart::setCount(const QString &count)
{
    m_count = count;
}

const QString &ShopCart::getID() const
{
    return m_id;
}
const QString &ShopCart::getDetailID() const
{
    return m_detailID;
}
const QString &ShopCart::getCount() const
{
    return m_count;
}
