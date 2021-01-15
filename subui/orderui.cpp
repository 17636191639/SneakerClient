#include "orderui.h"
#include "ui_orderui.h"

OrderUI::OrderUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderUI)
{
    ui->setupUi(this);
}

OrderUI::~OrderUI()
{
    delete ui;
}
