#include "shopcartitem.h"
#include "ui_shopcartitem.h"

ShopCartItem::ShopCartItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopCartItem)
{
    ui->setupUi(this);
}

ShopCartItem::~ShopCartItem()
{
    delete ui;
}
