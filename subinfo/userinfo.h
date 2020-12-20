#ifndef USERINFO_H
#define USERINFO_H

#include <QString>
#include <QList>


class UserInfo
{
public:
    UserInfo();
    UserInfo(const QString &id, const QString &pswd, const QString &role, const QString &date);
    void display(void) const;

    void setID(const QString &id);
    void setPswd(const QString &pswd);
    void setRole(const QString &role);
    void setDate(const QString &date);

    const QString &getID(void) const;
    const QString &getPswd(void) const;
    const QString &getRole(void) const;
    const QString &getDate(void) const;

private:
    QString m_id;
    QString m_pswd;
    QString m_role;
    QString m_date;
};

typedef QList<UserInfo> UserInfoList;
#endif // USERINFO_H
