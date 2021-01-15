#include "personalui.h"
#include "ui_personalui.h"
#include "globalvalues.h"

PersonalUI::PersonalUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonalUI)
{
    ui->setupUi(this);
    askForBuyerInfo();
}

PersonalUI::~PersonalUI()
{
    delete ui;
}
void PersonalUI::askForBuyerInfo()
{
    QString msg = QString(CMD_GetBuyerInfo_B) + QString("#") + GlobalValues::g_localUser.getID();
    GlobalValues::g_mainWindow->slotSendMsgToServer(msg);
}
void PersonalUI::slotGetBuyerInfoResult(bool res)
{
    if(res)
    {
        ui->le_account->setText(GlobalValues::g_buyerInfo->getID());
        ui->le_name->setText(GlobalValues::g_buyerInfo->getName());
        ui->le_telephone->setText(GlobalValues::g_buyerInfo->getTel());
        ui->le_address->setText(GlobalValues::g_buyerInfo->getAddress());

    }
}
