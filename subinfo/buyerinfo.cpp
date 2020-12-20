#include "buyerinfo.h"

BuyerInfo::BuyerInfo()
{
    m_id.clear();
    m_name.clear();
    m_tel.clear();
    m_address.clear();
}
BuyerInfo::BuyerInfo(const QString &id, const QString &name, const QString &telephone, const QString &address)
{
    m_id = id;
    m_name = name;
    m_tel = telephone;
    m_address = address;
}

void BuyerInfo::setID(const QString &id)
{
    m_id = id;
}
void BuyerInfo::setName(const QString &name)
{
    m_name = name;
}
void BuyerInfo::setTelephone(const QString &telephone)
{
    m_tel = telephone;
}
void BuyerInfo::setAddress(const QString &address)
{
    m_address = address;
}

const QString &BuyerInfo::getID(void) const
{
    return m_id;
}
const QString &BuyerInfo::getName(void) const
{
    return m_name;
}
const QString &BuyerInfo::getTel(void) const
{
    return m_tel;
}
const QString &BuyerInfo::getAddress(void) const
{
    return m_address;
}
