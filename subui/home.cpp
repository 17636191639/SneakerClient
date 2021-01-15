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
    ui->tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);//设置滚动条平滑滚动

    m_parentWidget = parent;
    m_shoesDetailsUI = NULL;
}

Home::~Home()
{
    delete ui;
}
void Home::updateTalbeWidget(void)
{
    ui->tableWidget->clear();

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



            if(!item->setPhoto())   //如果本地无图片则向服务器申请图片
            {
                emit signalGetShoesPhoto(GlobalValues::g_localUser.getID(),
                                         GlobalValues::g_shoesInfoList->at(i).getPhotoID(), false);
                GlobalValues::setPhotoMap.insert(GlobalValues::g_shoesInfoList->at(i).getPhotoID(), item);
            }
            ui->tableWidget->setCellWidget(i / 2, flag, item);

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



void Home::on_tableWidget_clicked(const QModelIndex &index)
{
    //this->hide();
    m_shoesDetailsUI = new ShoesDetailUI(GlobalValues::g_shoesInfoList->at(index.row() * 2 + index.column()).getID(),
                                       GlobalValues::g_shoesInfoList->at(index.row() * 2 + index.column()).getShoesName(),
                                       m_parentWidget, this);
    //connect(m_,SIGNAL(signalGetShoesDetailsResult(bool)))

    m_shoesDetailsUI->show();


    emit signalGetShoesDetails(GlobalValues::g_localUser.getID(),
                               GlobalValues::g_shoesInfoList->at(index.row() * 2 + index.column()).getID());



}
void Home::slotGetShoesDetailsResult(bool res)
{
    if(res)
    {
        qDebug() << "m_shoesDetailsUI->setShoesDetails();";
        m_shoesDetailsUI->setShoesDetails();
    }

}
void Home::slotAddShopCartResult(bool res)
{
    m_shoesDetailsUI->slotAddShopCartResult(res);
}
void Home::hideEvent(QHideEvent *event)
{
    qDebug() << "Home::hideEvent(QHideEvent *event)";
    if(!m_shoesDetailsUI == NULL)
    {
        m_shoesDetailsUI->hide();
        qDebug() << "子窗口隐藏";
    }
    event->accept();//接受隐藏事件请求
}
