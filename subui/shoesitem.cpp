#include "shoesitem.h"
#include "ui_shoesitem.h"
#include <QDebug>

ShoesItem::ShoesItem(QString shoesName,QString shoesPrice, QString photoID, QWidget *parent) :
    Photo(parent),
    ui(new Ui::ShoesItem)
{
    ui->setupUi(this);

    ui->lb_name->setText(shoesName);
    ui->lb_price->setText(shoesPrice);
    m_photoID = photoID;
    m_imgPath = QString("./shoes_photo/") + photoID + QString(" (1).jpg");
}

bool ShoesItem::setPhoto()
{
    QImage img;
    //QImage img(photo);
    //photo.scaled(200,200);
    //QSize size = ui->lb_image->rect().size();
    if(img.load(m_imgPath))
    {
        //安给定大小显示  Qt::SmoothTransformation平滑变换  清晰度
        //ui->lb_image->setPixmap(QPixmap::fromImage(img).scaled(300, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        //适应宽显示
        ui->lb_image->setPixmap(QPixmap::fromImage(img).scaledToWidth(300, Qt::SmoothTransformation));
        return true;
    }
    return false;
}
void ShoesItem::setShoesName(const QString &shoesName)
{
    ui->lb_name->setText(shoesName);
}
void ShoesItem::setShoesPrice(const QString &shoesPrice)
{
    ui->lb_price->setText(shoesPrice);
}
ShoesItem::~ShoesItem()
{
    delete ui;
}
