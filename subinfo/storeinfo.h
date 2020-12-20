#ifndef STOREINFO_H
#define STOREINFO_H
#include <QString>

class StoreInfo
{
public:
    StoreInfo();
    StoreInfo(const QString &id, const QString &sellerID, const QString &name,
              const QString &brand, const QString &date, const QString &reputation);

    void setID(const QString &id);
    void setSellerID(const QString &sellerID);
    void setStoreName(const QString &name);
    void setBrand(const QString &brand);
    void setDate(const QString &date);
    void setReputation(const QString &reputation);

    const QString &getID(void) const;
    const QString &getSellerID(void) const;
    const QString &getStoreName(void) const;
    const QString &getBrand(void) const;
    const QString &getDate(void) const;
    const QString &getReputation(void) const;
private:
    QString m_id;
    QString m_sellerID;
    QString m_name;
    QString m_brand;
    QString m_date;
    QString m_reputation;
};

typedef QList<StoreInfo> StoreInfoList;
#endif // STOREINFO_H
