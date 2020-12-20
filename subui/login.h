#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void userLoginFail(void);
signals:
    signalUserLogin(QString id, QString pswd);
private slots:
    void on_pb_login_clicked();

    void on_pb_signin_clicked();

private:
    Ui::Login *ui;
    QString m_account;
    QString m_pswd;
};

#endif // LOGIN_H
