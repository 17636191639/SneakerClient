#include "sellerinfo.h"

SellerInfo::SellerInfo()
{
    m_id.clear();
    m_name.clear();
    m_tel.clear();
    m_address.clear();
}
SellerInfo::SellerInfo(const QString &id, const QString &name, const QString &telephone, const QString &address)
{
    m_id = id;
    m_name = name;
    m_tel = telephone;
    m_address = address;
}

void SellerInfo::setID(const QString &id)
{
    m_id = id;
}
void SellerInfo::setName(const QString &name)
{
    m_name = name;
}
void SellerInfo::setTelephone(const QString &telephone)
{
    m_tel = telephone;
}
void SellerInfo::setAddress(const QString &address)
{
    m_address = address;
}

const QString &SellerInfo::getID(void) const
{
    return m_id;
}
const QString &SellerInfo::getName(void) const
{
    return m_name;
}
const QString &SellerInfo::getTel(void) const
{
    return m_tel;
}
const QString &SellerInfo::getAddress(void) const
{
    return m_address;
}
