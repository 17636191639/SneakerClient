#include "personalui.h"
#include "ui_personalui.h"

PersonalUI::PersonalUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalUI)
{
    ui->setupUi(this);
}

PersonalUI::~PersonalUI()
{
    delete ui;
}
