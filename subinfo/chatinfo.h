#ifndef CHATINFO_H
#define CHATINFO_H
#include <QString>

class ChatInfo
{
public:
    ChatInfo();
    ChatInfo(const QString &id, const QString &buyerID, const QString &sellerID,
             const QString &photoID, const QString &content, const QString &date);
    void setID(const QString &id);
    void setBuyerID(const QString &buyerID);
    void setSellerID(const QString &sellerID);
    void setPhotoID(const QString &photoID);
    void setContent(const QString &content);
    void setDate(const QString &date);

    const QString &getID(void) const;
    const QString &getBuyerID(void) const;
    const QString &getSellerID(void) const;
    const QString &getPhotoID(void) const;
    const QString &getContent(void) const;
    const QString &getDate(void) const;
private:
    QString m_id;
    QString m_buyerID;
    QString m_sellerID;
    QString m_photoID;
    QString m_content;

    QString m_date;
};
 typedef QList<ChatInfo> ChatInfoList;
#endif // CHATINFO_H
