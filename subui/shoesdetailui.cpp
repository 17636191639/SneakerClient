#include "shoesdetailui.h"
#include "ui_shoesdetailui.h"
#include <QDebug>
ShoesDetailUI::ShoesDetailUI(const QString &shoesID, const QString &shoesName, QWidget *parent, QWidget *lastUI) :
    QWidget(parent),
    ui(new Ui::ShoesDetailUI)
{
    ui->setupUi(this);
    m_lastUI = lastUI;
    ui->listWidget->addItem("");

    m_shoesDetails = new ShowDetails(shoesName, ui->listWidget);

    ui->listWidget->item(0)->setSizeHint(QSize(890, 600));//指定推荐尺寸大小

    ui->listWidget->setItemWidget(ui->listWidget->item(0), m_shoesDetails);
    //ui->listWidget->item(0)->setFlags(Qt::ItemIsSelectable);
    ui->listWidget->setFocusPolicy(Qt::NoFocus);
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
    qDebug() << "m_shoesDetails->setDetails();";
    m_shoesDetails->setBaseSize(ui->listWidget->frameSize());
    m_shoesDetails->setDetails();

}
