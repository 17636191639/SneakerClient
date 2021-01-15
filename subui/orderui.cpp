#include "orderui.h"
#include "ui_orderui.h"
#include "orderitem.h"
#include "globalvalues.h"

OrderUI::OrderUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderUI)
{
    ui->setupUi(this);
    m_itemCount = 0;
}

OrderUI::~OrderUI()
{
    delete ui;
}
void OrderUI::slotAskOrderInfoToServer()
{
    ui->listWidget->clear();
    GlobalValues::g_orderInfoList->clear();
    GlobalValues::g_shoesDetailsList->clear();
    m_itemCount = 0;
    QString sendMsg = QString(CMD_GetOrder_O) +
            QString("#") + GlobalValues::g_localUser.getID();
    GlobalValues::g_mainWindow->slotSendMsgToServer(sendMsg);
}
void OrderUI::slotGetOrderInfoResult(bool res)
{
    if(res)
    {
        for(int i = 0; i < GlobalValues::g_orderInfoList->count(); i++)//通过订单里的详情编号获取商品信息
        {

            QString sendMsg = QString(CMD_GetShoesDetailByOrder_o) + QString("#") +
                                        GlobalValues::g_localUser.getID() + QString("|") +
                                        GlobalValues::g_orderInfoList->at(i).getID() + QString("|") +
                                        GlobalValues::g_orderInfoList->at(i).getDetailID();
            GlobalValues::g_mainWindow->slotSendMsgToServer(sendMsg); //o#buyerid|shoesDetailsID
        }
    }
}
void OrderUI::slotGetShoesDetailsByOrderResult(bool res, QString orderID)
{
    if(res)
    {
        for(int j = 0; j < GlobalValues::g_orderInfoList->count(); j++)//订单列表
        {

            if(GlobalValues::g_orderInfoList->at(j).getID() == orderID)
            {
                int totalMoney = GlobalValues::g_shoesDetailsList->at(0).getPrice().toInt() * GlobalValues::g_orderInfoList->at(j).getCount().toInt();
                OrderItem *item = new OrderItem(GlobalValues::g_orderInfoList->at(j).getID(),
                                                GlobalValues::g_orderInfoList->at(j).getCreateDate(),
                                                GlobalValues::g_orderInfoList->at(j).getDetailID(),
                                                QString::number(totalMoney),
                                                GlobalValues::g_orderInfoList->at(j).getState(),
                                                GlobalValues::g_shoesDetailsList->at(0).getPhotoID());
                ui->listWidget->addItem("");
                ui->listWidget->item(m_itemCount)->setSizeHint(QSize(800, 150));//指定推荐尺寸大小

                ui->listWidget->setItemWidget(ui->listWidget->item(m_itemCount++), item);

            }

        }




//        int totalMoney = GlobalValues::g_shoesDetailsList->at(0).getPrice().toInt() * GlobalValues::g_orderInfoList->at(m_itemCount).getCount().toInt();
//                            OrderItem *item = new OrderItem(GlobalValues::g_orderInfoList->at(m_itemCount).getID(),
//                                                            GlobalValues::g_orderInfoList->at(m_itemCount).getCreateDate(),
//                                                            GlobalValues::g_orderInfoList->at(m_itemCount).getDetailID(),
//                                                            QString::number(totalMoney),
//                                                            GlobalValues::g_orderInfoList->at(m_itemCount).getState(),
//                                                            GlobalValues::g_shoesDetailsList->at(0).getPhotoID());
//        ui->listWidget->addItem("");
//        ui->listWidget->item(m_itemCount)->setSizeHint(QSize(800, 150));//指定推荐尺寸大小

//        ui->listWidget->setItemWidget(ui->listWidget->item(m_itemCount++), item);
//        GlobalValues::g_shoesDetailsList->pop_front();
//        for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++) ////通过订单里的详情编号获取商品信息
//        {






    }
}
