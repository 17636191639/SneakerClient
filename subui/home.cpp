#include "home.h"
#include "ui_home.h"
#include "globalvalues.h"
#include "shoesitem.h"
#include <QMessageBox>
#include <QDebug>
Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    ///获取信息

    ///刷新页面
    updateTalbeWidget();
}

Home::~Home()
{
    delete ui;
}
void Home::updateTalbeWidget(void)
{
    ui->tableWidget->clear();
//    ui->tableWidget->setColumnCount(2);  //设置列数
    int count = GlobalValues::g_shoesInfoList->count();
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            ShoesItem *item = new ShoesItem(GlobalValues::g_shoesInfoList->at(i).getShoesName(),
                                            GlobalValues::g_shoesInfoList->at(i).getBottomPrice());
            ui->tableWidget->setCellWidget(i, j, item);
        }
    }
//    for(int i = 0; i < GlobalValues::g_shoesInfoList->count(); i++)
//    {
//        //ui->tableWidget->addItem("");
//        qDebug() << GlobalValues::g_shoesInfoList->at(i).getShoesName();
//        ShoesItem *item = new ShoesItem(GlobalValues::g_shoesInfoList->at(i).getShoesName(),
//                                        GlobalValues::g_shoesInfoList->at(i).getBottomPrice());
//        //ui->tableWidget->item(i)->setSizeHint(QSize(224, 268));
//        ui->tableWidget->setCellWidget(i, 0, item);
////        item = new ShoesItem(GlobalValues::g_shoesInfoList->at(i).getShoesName());
////        ui->tableWidget->setCellWidget(i, 0, item);
//    }
}



void Home::on_pb_refresh_clicked()
{
    emit signalGetShoesInfo();
}
void Home::slotGetShoesResult(bool result)
{
    if(result)
    {
        updateTalbeWidget();
    }else
    {
        QMessageBox::warning(this, "警告", "账号或密码错误!",
                             QMessageBox::Retry|QMessageBox::Close);
    }

}
