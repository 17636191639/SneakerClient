#include "createorder.h"
#include "ui_createorder.h"

CreateOrder::CreateOrder(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateOrder)
{
    ui->setupUi(this);
}

CreateOrder::~CreateOrder()
{
    delete ui;
}
