#include "photoinfo.h"

PhotoInfo::PhotoInfo()
{
    m_id.clear();
    m_photoCount.clear();
    m_photoPath.clear();
}
PhotoInfo::PhotoInfo(const QString &id, const QString &photoCount, const QString &photoPath)
{
    m_id = id;
    m_photoCount = photoCount;
    m_photoPath = photoPath;
}

void PhotoInfo::setPhotoCount(const QString &photoCount)
{
    m_photoCount = photoCount;
}
void PhotoInfo::setPhotoPath(const QString &photoPath)
{
    m_photoPath = photoPath;
}
const QString &PhotoInfo::getID() const
{
    return m_id;
}
const QString &PhotoInfo::getPhotoCount() const
{
    return m_photoCount;
}
const QString &PhotoInfo::getPhotoPath() const
{
    return m_photoPath;
}
