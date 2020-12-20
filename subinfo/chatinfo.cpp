#include "chatinfo.h"

ChatInfo::ChatInfo()
{
    m_id.clear();
    m_buyerID.clear();
    m_sellerID.clear();
    m_photoID.clear();
    m_content.clear();
//    m_photoCount.clear();
//    m_photoPath.clear();
    m_date.clear();
}

ChatInfo::ChatInfo(const QString &id, const QString &buyerID, const QString &sellerID,
                   const QString &photoID, const QString &content, const QString &date)
{
    m_id = id;
    m_buyerID = buyerID;
    m_sellerID = sellerID;
    m_photoID = photoID;
    m_content = content;
//    m_photoCount = photoCount;
//    m_photoPath = photoPath;
    m_date = date;
}
void ChatInfo::setID(const QString &id)
{
    m_id = id;

}
void ChatInfo::setBuyerID(const QString &buyerID)
{
    m_buyerID = buyerID;

}
void ChatInfo::setSellerID(const QString &sellerID)
{
    m_sellerID = sellerID;

}
void ChatInfo::setPhotoID(const QString &photoID)
{
    m_photoID = photoID;

}
//void ChatInfo::setContent(const QString &content)
//{
//    m_content = content;

//}
//void ChatInfo::setPhotoCount(const QString &photoCount)
//{
//    m_photoCount = photoCount;

//}
//void ChatInfo::setPhotoPath(const QString &photoPath)
//{
//    m_photoPath = photoPath;


//}
void ChatInfo::setDate(const QString &date)
{
    m_date = date;
}

const QString &ChatInfo::getID(void) const
{
    return m_id;

}
const QString &ChatInfo::getBuyerID(void) const
{
    return m_buyerID;
}
const QString &ChatInfo::getSellerID(void) const
{
    return m_sellerID;
}
const QString &ChatInfo::getPhotoID(void) const
{
    return m_photoID;
}
const QString &ChatInfo::getContent(void) const
{
    return m_content;
}
//const QString &ChatInfo::getPhotoCount(void) const
//{
//    return m_photoCount;
//}
//const QString &ChatInfo::getPhotoPath(void) const
//{
//    return m_photoPath;
//}
const QString &ChatInfo::getDate(void) const
{
    return m_date;
}
