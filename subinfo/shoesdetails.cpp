#include "shoesdetails.h"

ShoesDetails::ShoesDetails()
{
    m_id.clear();
    m_shoesID.clear();
    m_size.clear();
    m_color.clear();
    m_price.clear();
//    m_photoCount.clear();
//    m_photoPath.clear();
    m_stock.clear();
}

ShoesDetails::ShoesDetails(const QString &id, const QString &shoesID, const QString &photoID, const QString &size, const QString &color,
             const QString &price, const QString &stock)
{
    m_id = id;
    m_shoesID = shoesID;
    m_photoID = photoID;
    m_size = size;
    m_color = color;
    m_price = price;
//    m_photoCount = photoCount;
//    m_photoPath = photoPath;
    m_stock = stock;
}
void ShoesDetails::setID(const QString &id)
{
    m_id = id;

}
void ShoesDetails::setShoesID(const QString &shoesID)
{
    m_shoesID = shoesID;

}
void ShoesDetails::setPhotoID(const QString &photoID)
{
    m_photoID = photoID;

}
void ShoesDetails::setSize(const QString &size)
{
    m_size = size;

}
void ShoesDetails::setColor(const QString &color)
{
    m_color = color;

}
void ShoesDetails::setPrice(const QString &price)
{
    m_price = price;

}
//void ShoesDetails::setPhotoCount(const QString &photoCount)
//{
//    m_photoCount = photoCount;

//}
//void ShoesDetails::setPhotoPath(const QString &photoPath)
//{
//    m_photoPath = photoPath;

//}
void ShoesDetails::setStock(const QString &stock)
{
    m_stock = stock;
}

const QString &ShoesDetails::getID(void) const
{
    return m_id;
}
const QString &ShoesDetails::getShoesID(void) const
{
    return m_shoesID;
}
const QString &ShoesDetails::getPhotoID(void) const
{
    return m_photoID;
}
const QString &ShoesDetails::getSize(void) const
{
    return m_size;
}
const QString &ShoesDetails::getColor(void) const
{
    return m_color;
}
const QString &ShoesDetails::getPrice(void) const
{
    return m_price;
}
//const QString &ShoesDetails::getPhotoCount(void) const
//{
//    return m_photoCount;
//}
//const QString &ShoesDetails::getPhotoPath(void) const
//{
//    return m_photoPath;
//}
const QString &ShoesDetails::getStock(void) const
{
    return m_stock;
}
