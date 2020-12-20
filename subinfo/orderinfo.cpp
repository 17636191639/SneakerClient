#include "orderinfo.h"

OrderInfo::OrderInfo()
{
    m_id.clear();
    m_buyerID.clear();
    m_detailID.clear();
    m_count.clear();

    m_state.clear();
    m_createDate.clear();
    m_deliveryDate.clear();
    m_finishDate.clear();
}

OrderInfo::OrderInfo(const QString &id, const QString &buyID, const QString &detailID, const QString &count,
          const QString &state, const QString &createDate, const QString &deliveryDate, const QString &finishDate)
{
    m_id = id;
    m_buyerID = buyID;
    m_detailID = detailID;
    m_count = count;

    m_state = state;
    m_createDate = createDate;
    m_deliveryDate = deliveryDate;
    m_finishDate = finishDate;
}

void OrderInfo::setID(const QString &id)
{
    m_id = id;

}
void OrderInfo::setBuyID(const QString &buyID)
{
    m_buyerID = buyID;

}
void OrderInfo::setDetailID(const QString &detailID)
{
    m_detailID = detailID;

}
void OrderInfo::setCount(const QString &count)
{
    m_count = count;


}
void OrderInfo::setState(const QString &state)
{
    m_state = state;

}
void OrderInfo::setCreateDate(const QString &createDate)
{
    m_createDate = createDate;

}
void OrderInfo::setDeliveryDate(const QString &deliveryDate)
{
    m_deliveryDate = deliveryDate;


}
void OrderInfo::setFinishDate(const QString &finishDate)
{
    m_finishDate = finishDate;
}

const QString &OrderInfo::getID() const
{
    return m_id;
}
const QString &OrderInfo::getBuyID() const
{
    return m_buyerID;
}
const QString &OrderInfo::getDetailID() const
{
    return m_detailID;
}
const QString &OrderInfo::getCount() const
{
    return m_count;
}
const QString &OrderInfo::getState() const
{
    return m_state;
}
const QString &OrderInfo::getCreateDate() const
{
    return m_createDate;
}
const QString &OrderInfo::getDeliveryDate() const
{
    return m_deliveryDate;
}
const QString &OrderInfo::getFinishDate() const
{
    return m_finishDate;
}
