#include "shopcartui.h"
#include "ui_shopcartui.h"

ShopCartUI::ShopCartUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShopCartUI)
{
    ui->setupUi(this);
}

ShopCartUI::~ShopCartUI()
{
    delete ui;
}
