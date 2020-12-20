#ifndef BUYERINFO_H
#define BUYERINFO_H
#include <QString>
#include <QList>

class BuyerInfo
{
public:
    BuyerInfo();
    BuyerInfo(const QString &id, const QString &name, const QString &telephone, const QString &address);

    void setID(const QString &id);
    void setName(const QString &name);
    void setTelephone(const QString &telephone);
    void setAddress(const QString &address);

    const QString &getID(void) const;
    const QString &getName(void) const;
    const QString &getTel(void) const;
    const QString &getAddress(void) const;
private:
    QString m_id;
    QString m_name;
    QString m_tel;
    QString m_address;
};

typedef QList<BuyerInfo> BuyerInfoList;

#endif // BUYERINFO_H
