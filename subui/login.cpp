#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pb_login_clicked()//登录
{
    if(ui->le_account->text().isEmpty())
    {
        QMessageBox::warning(this, "警告", "用户名不能为空!",
                             QMessageBox::Retry|QMessageBox::Close);
    }else if(ui->le_pswd->text().isEmpty())
    {
        QMessageBox::warning(this, "警告", "密码不能为空!",
                             QMessageBox::Retry|QMessageBox::Close);
    }else
    {
        emit signalUserLogin(ui->le_account->text(), ui->le_pswd->text());
    }
}

void Login::on_pb_signin_clicked()//注册
{

}
void Login::userLoginFail(void)
{
    QMessageBox::warning(this, "警告", "账号或密码错误!",
                         QMessageBox::Retry|QMessageBox::Close);
}

void Login::on_pushButton_clicked()
{
    this->close();
}
