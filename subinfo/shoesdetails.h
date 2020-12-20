#ifndef SHOESDETAILS_H
#define SHOESDETAILS_H
#include <QString>

class ShoesDetails
{
public:
    ShoesDetails();
    ShoesDetails(const QString &id, const QString &shoesID, const QString &photoID, const QString &size, const QString &color,
                 const QString &price, const QString &stock);
    void setID(const QString &id);
    void setShoesID(const QString &shoesID);
    void setPhotoID(const QString &photoID);
    void setSize(const QString &size);
    void setColor(const QString &color);
    void setPrice(const QString &price);
//    void setPhotoCount(const QString &photoCount);
//    void setPhotoPath(const QString &photoPath);
    void setStock(const QString &stock);

    const QString &getID(void) const;
    const QString &getShoesID(void) const;
    const QString &getPhotoID(void) const;
    const QString &getSize(void) const;
    const QString &getColor(void) const;
    const QString &getPrice(void) const;
//    const QString &getPhotoCount(void) const;
//    const QString &getPhotoPath(void) const;
    const QString &getStock(void) const;
private:
    QString m_id;
    QString m_shoesID;
    QString m_photoID;
    QString m_size;
    QString m_color;
    QString m_price;
//    QString m_photoCount;
//    QString m_photoPath;
    QString m_stock;
};
typedef QList<ShoesDetails> ShoesDetailsList;
#endif // SHOESDETAILS_H
