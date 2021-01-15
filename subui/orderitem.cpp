#include "orderitem.h"
#include "ui_orderitem.h"
#include "globalvalues.h"

OrderItem::OrderItem(const QString &orderID, const QString &orderDate, const QString &shoesName,
                     const QString &totalMoney, const QString &orderState, const QString &photoID, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderItem)
{
    ui->setupUi(this);
    ui->lb_orderid->setText(orderID);
    ui->lb_orderdate->setText(orderDate);
    ui->lb_shoesname->setText(shoesName);
    ui->lb_totalmoney->setText(totalMoney);
    ui->lb_orderstate->setText(orderState);
    m_showImg = new ShowImg(photoID, shoesPhotoDir, ui->photowidget);
    m_showImg->setGeometry(0, 0, 120, 120);//将图片移到相应位置
    if(!m_showImg->setPhoto())//如果没有图片就申请图片
    {
        m_showImg->getImageFromServerByPhotoID();
    }
    m_showImg->setImgScaledToWidth(120);
}

OrderItem::~OrderItem()
{
    delete ui;
}
