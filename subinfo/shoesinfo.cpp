#include "shoesinfo.h"

ShoesInfo::ShoesInfo()
{
    m_id.clear();
    m_storeID.clear();
    m_shoesName.clear();
    m_bottomPrice.clear();
    m_freight.clear();
}
ShoesInfo::ShoesInfo(const QString &id, const QString &storeID,
                     const QString &shoesName,const QString &bottomPrice, const QString &freight)
{
    m_id = id;
    m_storeID = storeID;
    m_shoesName = shoesName;
    m_bottomPrice = bottomPrice;
    m_freight = freight;
}

void ShoesInfo::setID(const QString &id)
{
    m_id = id;

}
void ShoesInfo::setStoreID(const QString &storeID)
{
    m_storeID = storeID;

}
void ShoesInfo::setShoesName(const QString &shoesName)
{
    m_shoesName = shoesName;

}
void ShoesInfo::setBottomPrice(const QString &bottomPrice)
{
    m_bottomPrice = bottomPrice;
}

void ShoesInfo::setFreight(const QString &freight)
{
    m_freight = freight;
}

const QString &ShoesInfo::getID(void) const
{
    return m_id;
}
const QString &ShoesInfo::getStoreID(void) const
{
    return m_storeID;
}
const QString &ShoesInfo::getShoesName(void) const
{
    return m_shoesName;
}
const QString &ShoesInfo::getBottomPrice(void) const
{
    return m_bottomPrice;
}

const QString &ShoesInfo::getFreight(void) const
{
    return m_freight;
}
