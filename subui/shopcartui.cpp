#include "shopcartui.h"
#include "ui_shopcartui.h"
#include "globalvalues.h"
#include "shopcartitem.h"

ShopCartUI::ShopCartUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopCartUI)
{
    ui->setupUi(this);
    m_itemCount = 0;
    ui->listWidget->setSelectionMode(QAbstractItemView::MultiSelection);//点击多选
}

ShopCartUI::~ShopCartUI()
{
    delete ui;
}
void ShopCartUI::slotAskShopCartInfoFromServer()
{
    ui->listWidget->clear();
    m_itemCount = 0;

    QString sendMsg = QString(CMD_ViewShopCart_P) +
            QString("#") + GlobalValues::g_localUser.getID();//请求购物车信息命令
    GlobalValues::g_mainWindow->slotSendMsgToServer(sendMsg);
}
void ShopCartUI::slotGetShopCartInfoResult(bool res)
{
    if(res)//接受购物车信息成功
    {
        for(int i = 0; i < GlobalValues::g_shopCartList->count(); i++)//通过购物车里的商品详情ID获取商品详情信息
        {
            //emit signalGetShoesDetailsFromShopCart();
            QString sendMsg = QString(CMD_GetShoesDetailFromDetailsID_f) + QString("#") +
                                        GlobalValues::g_localUser.getID() + QString("|") +
                                        GlobalValues::g_shopCartList->at(i).getDetailID();
            GlobalValues::g_mainWindow->slotSendMsgToServer(sendMsg); //f#buyerid|shoesDetailsID
        }
    }
}
void ShopCartUI::slotGetShoesDetailsFromDetailsIDResult(bool res)
{
    if(res)
    {
        for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
        {
            for(int j = 0; j < GlobalValues::g_shopCartList->count(); j++) //找到添加listItem需要的数量信息
            {
                if(GlobalValues::g_shoesDetailsList->at(i).getID() == GlobalValues::g_shopCartList->at(j).getDetailID())
                {
                    ui->listWidget->addItem("");

                    ShopCartItem *item = new ShopCartItem(GlobalValues::g_shoesDetailsList->at(i).getPhotoID(),
                                                          GlobalValues::g_shoesDetailsList->at(i).getShoesID(),
                                                          GlobalValues::g_shoesDetailsList->at(i).getSize(),
                                                          GlobalValues::g_shoesDetailsList->at(i).getColor(),
                                                          GlobalValues::g_shopCartList->at(j).getCount(),
                                                          GlobalValues::g_shoesDetailsList->at(i).getPrice()
                                                          );

                    ui->listWidget->item(m_itemCount)->setSizeHint(QSize(800, 150));//指定推荐尺寸大小

                    ui->listWidget->setItemWidget(ui->listWidget->item(m_itemCount++), item);
                }
            }
        }
    }
}
