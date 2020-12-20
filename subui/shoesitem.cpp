#include "shoesitem.h"
#include "ui_shoesitem.h"
#include <QImage>

ShoesItem::ShoesItem(QString shoesName,QString shoesPrice,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShoesItem)
{
    ui->setupUi(this);

    ui->lb_name->setText(shoesName);
    ui->lb_price->setText(shoesPrice);
//    QImage img(photoPath);
//    ui->lb_image->setPixmap(QPixmap::fromImage(img));

}
void ShoesItem::setItemPhoto(const QString &photoPath)
{
    QImage img(photoPath);
    ui->lb_image->setPixmap(QPixmap::fromImage(img));
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
