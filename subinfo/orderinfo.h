#ifndef ORDERINFO_H
#define ORDERINFO_H
#include <QString>

class OrderInfo
{
public:
    OrderInfo();
    OrderInfo(const QString &id, const QString &buyID, const QString &detailID, const QString &count,
              const QString &state, const QString &createDate, const QString &deliveryDate, const QString &finishDate);

    void setID(const QString &id);
    void setBuyID(const QString &buyID);
    void setDetailID(const QString &detailID);
    void setCount(const QString &count);
    void setState(const QString &state);
    void setCreateDate(const QString &createDate);
    void setDeliveryDate(const QString &deliveryDate);
    void setFinishDate(const QString &finishDate);

    const QString &getID() const;
    const QString &getBuyID() const;
    const QString &getDetailID() const;
    const QString &getCount() const;
    const QString &getState() const;
    const QString &getCreateDate() const;
    const QString &getDeliveryDate() const;
    const QString &getFinishDate() const;
private:
    QString m_id;
    QString m_buyerID;
    QString m_detailID;
    QString m_count;

    QString m_state;
    QString m_createDate;
    QString m_deliveryDate;
    QString m_finishDate;
};

typedef QList<OrderInfo> OrderInfoList;
#endif // ORDERINFO_H
