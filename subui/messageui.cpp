#include "messageui.h"
#include "ui_messageui.h"

MessageUI::MessageUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MessageUI)
{
    ui->setupUi(this);
}

MessageUI::~MessageUI()
{
    delete ui;
}
