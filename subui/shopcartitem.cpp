#include "shopcartitem.h"
#include "ui_shopcartitem.h"
#include "globalvalues.h"

ShopCartItem::ShopCartItem(const QString &photoID, const QString &shoesName, const QString &size, const QString &color,
                           const QString &shoesCount, const QString &price, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopCartItem)
{
    ui->setupUi(this);

    ui->lb_color->setText(color);
    ui->lb_shoesname->setText(shoesName);
    ui->lb_shoesprice->setText(price);
    ui->lb_shoessize->setText(size);
    ui->le_count->setText(shoesCount);

    m_showImg = new ShowImg(photoID, shoesPhotoDir, ui->photowidget);
    m_showImg->setGeometry(0, 0, 120, 120);//将图片移到相应位置
    if(!m_showImg->setPhoto())//如果没有图片就申请图片
    {
        m_showImg->getImageFromServerByPhotoID();
    }
    m_showImg->setImgScaledToWidth(120);

}

ShopCartItem::~ShopCartItem()
{
    delete ui;
}

