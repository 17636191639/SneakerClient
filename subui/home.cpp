#include "home.h"
#include "ui_home.h"
#include "globalvalues.h"

#include <QMessageBox>
#include <QDebug>
#include <QImage>

Home::Home(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Home)
{
    ui->setupUi(this);
    ui->tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    itemMap.clear();
    ///获取信息

    //on_pb_refresh_clicked();
    ///刷新页面
    //updateTalbeWidget();
}

Home::~Home()
{
    delete ui;
}
void Home::updateTalbeWidget(void)
{
    ui->tableWidget->clear();
    itemMap.clear();
    ui->tableWidget->setColumnCount(2);  //设置列数

    int count;
    if(GlobalValues::g_shoesInfoList->count() % 2)
    {
        count = GlobalValues::g_shoesInfoList->count() / 2 + 1;
    }else
    {
        count = GlobalValues::g_shoesInfoList->count() / 2;
    }
    ui->tableWidget->setRowCount(count);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    bool flag = 0;
    for(int i = 0; i < GlobalValues::g_shoesInfoList->count(); i++)
    {

            ShoesItem *item = new ShoesItem(GlobalValues::g_shoesInfoList->at(i).getShoesName(),
                                            GlobalValues::g_shoesInfoList->at(i).getBottomPrice(),
                                            GlobalValues::g_shoesInfoList->at(i).getPhotoID());



            if(!item->setItemPhoto())   //如果本地无图片则向服务器申请图片
            {
                emit signalGetShoesPhoto(GlobalValues::g_localUser.getID(),
                                         GlobalValues::g_shoesInfoList->at(i).getPhotoID());
                QSleep(50);
            }
            ui->tableWidget->setCellWidget(i / 2, flag, item);
            itemMap.insert(GlobalValues::g_shoesInfoList->at(i).getPhotoID(), item);
            flag = !flag;


//            QString msg = QString(CMD_GetShoesPhoto_A) + QString("#") + GlobalValues::g_shoesInfoList->at(i).getID();
//            m_proc->slotSendMsg(msg);

    }

/////////////////   用listWidget显示   //////////////////////
//    ui->listWidget->clear();
//    for(int i = 0; i < GlobalValues::g_shoesInfoList->count(); i++)
//    {
//        ui->listWidget->addItem("");
//        qDebug() << GlobalValues::g_shoesInfoList->at(i).getShoesName();
//        ShoesItem *item = new ShoesItem(GlobalValues::g_shoesInfoList->at(i).getShoesName(),
//                                        GlobalValues::g_shoesInfoList->at(i).getBottomPrice());
//        ui->listWidget->item(i)->setSizeHint(QSize(224, 268));

//        ui->listWidget->setItemWidget(ui->listWidget->item(i), item);
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

void Home::slotSavePhotoSucess(QString photoID)
{
    QString imgPath = QString("./shoes_photo/") + photoID + QString(" (1).jpg");

    QImage img;
    if(img.load(imgPath))
    {
        if(itemMap.contains(photoID))
        {
            itemMap[photoID]->setItemPhoto();
            qDebug() << "111111111111111111111111111111111111111111111";
        }
        //item->setItemPhoto(img);
    }
}

