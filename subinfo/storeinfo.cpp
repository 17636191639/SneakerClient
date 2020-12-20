#include "storeinfo.h"

StoreInfo::StoreInfo()
{
    m_id.clear();
    m_sellerID.clear();
    m_name.clear();
    m_brand.clear();
    m_date.clear();
    m_reputation.clear();
}

StoreInfo::StoreInfo(const QString &id, const QString &sellerID, const QString &name,
            const QString &brand, const QString &date, const QString &reputation)
{
    m_id = id;
    m_sellerID = sellerID;
    m_name = name;
    m_brand = brand;
    m_date = date;
    m_reputation = reputation;
}

void StoreInfo::setID(const QString &id)
{
    m_id = id;

}
void StoreInfo::setSellerID(const QString &sellerID)
{
    m_sellerID = sellerID;

}
void StoreInfo::setStoreName(const QString &name)
{
    m_name = name;

}
void StoreInfo::setBrand(const QString &brand)
{
    m_brand = brand;

}
void StoreInfo::setDate(const QString &date)
{
    m_date = date;

}
void StoreInfo::setReputation(const QString &reputation)
{
    m_reputation = reputation;
}

const QString &StoreInfo::getID(void) const
{
    return m_id;
}
const QString &StoreInfo::getSellerID(void) const
{
    return m_sellerID;
}
const QString &StoreInfo::getStoreName(void) const
{
    return m_name;

}
const QString &StoreInfo::getBrand(void) const
{
    return m_brand;
}
const QString &StoreInfo::getDate(void) const
{
    return m_date;
}
const QString &StoreInfo::getReputation(void) const
{
    return m_reputation;
}
