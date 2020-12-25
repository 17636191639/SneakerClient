#ifndef PHOTOINFO_H
#define PHOTOINFO_H
#include <QString>

class PhotoInfo
{
public:
    PhotoInfo();
    PhotoInfo(const QString &id, const QString &photoCount, const QString &photoPath);

    void setPhotoCount(const QString &photoCount);
    void setPhotoPath(const QString &photoPath);

    const QString &getID() const;
    const QString &getPhotoCount() const;
    const QString &getPhotoPath() const;
private:
    QString m_id;
    QString m_photoCount;
    QString m_photoPath;
};

typedef QList<PhotoInfo> PhotoInfoList;
#endif // PHOTOINFO_H
