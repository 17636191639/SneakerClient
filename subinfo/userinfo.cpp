#include "userinfo.h"
#include <QDebug>
UserInfo::UserInfo()
{
    m_id.clear();
    m_pswd.clear();
    m_role.clear();
    m_date.clear();
}
UserInfo::UserInfo(const QString &id, const QString &pswd, const QString &role, const QString &date)
{
    m_id = id;
    m_pswd = pswd;
    m_role = role;
    m_date = date;
}
void UserInfo::display(void) const
{
    qDebug() << "ID: " << m_id << " Pswd: " << m_pswd << " Role: " << m_role << " Date: " << m_date;
}


void UserInfo::setID(const QString &id)
{
    m_id = id;
}
void UserInfo::setPswd(const QString &pswd)
{
    m_pswd = pswd;
}
void UserInfo::setRole(const QString &role)
{
    m_role = role;
}
void UserInfo::setDate(const QString &date)
{
    m_date = date;
}
const QString &UserInfo::getID(void) const
{
    return m_id;
}
const QString &UserInfo::getPswd(void) const
{
    return m_pswd;
}
const QString &UserInfo::getRole(void) const
{
    return m_role;
}
const QString &UserInfo::getDate(void) const
{
    return m_date;
}
