#include "createorder.h"
#include "ui_createorder.h"
#include <QDateTime>
#include "globalvalues.h"

CreateOrder::CreateOrder(const QString&shoesName, const QString &price, const QString &size,
                         const QString &color, const QString &count, const QImage &shoesPhoto,
                         const QString &detailsID, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateOrder)
{
    this->setWindowTitle("提交订单");
    ui->setupUi(this);
    ui->lb_shoesname->setText(shoesName);
    ui->lb_price->setText(price);
    ui->lb_size->setText(size);
    ui->lb_color->setText(color);
    ui->lb_count->setText(count);
    ui->lb_photo->setPixmap(QPixmap::fromImage(shoesPhoto).scaledToWidth(400, Qt::SmoothTransformation));;
    m_detailsID = detailsID;
    ui->lb_totalprice->setText(QString::number(ui->lb_count->text().toInt() * ui->lb_price->text().toInt()));
}

CreateOrder::~CreateOrder()
{
    delete ui;
}

void CreateOrder::on_pushButton_clicked()
{
        QDateTime date;

        QString orderID = QString("O-") + date.currentDateTime().toString("yyyyMMddhhmmss") ;
        QString buyerID = GlobalValues::g_localUser.getID();
        //m_currentShoesDetailsID//当前商品详情ID
        QString count = ui->lb_count->text();
        QString orderState("已付款");
        QString createDate = date.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");

        //发送订单信息到服务端添加
        QString sendMsg = QString(CMD_CommitOrderInfo_c) +
                QString("#") + buyerID +
                QString("|") + orderID +
                QString("&") + buyerID +
                QString("&") + m_detailsID +
                QString("&") + count +
                QString("&") + orderState +
                QString("&") + createDate +
                QString("&") + QString("null") +
                QString("&") + QString("null");

        GlobalValues::g_mainWindow->slotSendMsgToServer(sendMsg);

}
