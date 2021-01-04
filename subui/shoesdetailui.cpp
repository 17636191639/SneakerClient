#include "shoesdetailui.h"
#include "ui_shoesdetailui.h"
#include <QDebug>
ShoesDetailUI::ShoesDetailUI(const QString &shoesID, const QString &shoesName, QWidget *parent, QWidget *lastUI) :
    QWidget(parent),
    ui(new Ui::ShoesDetailUI)
{
    ui->setupUi(this);
    m_lastUI = lastUI;
    m_shoesDetails = new ShowDetails(shoesName, ui->listWidget);
    m_shoesID = shoesID;
}

ShoesDetailUI::~ShoesDetailUI()
{
    delete ui;
}

void ShoesDetailUI::on_pb_back_clicked()
{
    this->close();
    m_lastUI->show();
}
void ShoesDetailUI::setShoesDetails()
{
    m_shoesDetails->setBaseSize(ui->listWidget->frameSize());

    m_shoesDetails->setDetails();
}
