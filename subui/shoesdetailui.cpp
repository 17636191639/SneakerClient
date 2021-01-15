#include "shoesdetailui.h"
#include "ui_shoesdetailui.h"
#include <QDebug>
#include "showimg.h"
#include <QMessageBox>
#include <QHideEvent>

ShoesDetailUI::ShoesDetailUI(const QString &shoesID, const QString &shoesName, QWidget *parent, QWidget *lastUI) :
    QWidget(parent),
    ui(new Ui::ShoesDetailUI)
{
    ui->setupUi(this);

    m_lastUI = lastUI;
    m_itemCount = 0;
    m_shoesID = shoesID;
    ui->listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);//设置滚动条平滑滚动
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->addItem("");

    m_shoesDetails = new ShowDetails(shoesName, ui->listWidget);

    ui->listWidget->item(m_itemCount)->setSizeHint(QSize(890, 600));//指定推荐尺寸大小

    ui->listWidget->setItemWidget(ui->listWidget->item(m_itemCount++), m_shoesDetails);


    connect(m_shoesDetails, SIGNAL(signalAddDetailsPhoto(QString)), this, SLOT(slotAddDetailsPhoto(QString)));


}

ShoesDetailUI::~ShoesDetailUI()
{
    delete ui;
}
void ShoesDetailUI::hideEvent(QHideEvent *event)
{
    qDebug() << "ShoesDetailUI::hideEvent(QHideEvent *event)";
    event->accept();

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
void ShoesDetailUI::slotAddDetailsPhoto(const QString &imgPath)
{
    qDebug() << "添加详情图片" << imgPath;
    ui->listWidget->addItem("");

    ShowImg *item = new ShowImg(imgPath);
    item->setPhoto();
    item->setImgScaledToWidth(880);
    ui->listWidget->item(m_itemCount)->setSizeHint(QSize(890, 600));//指定推荐尺寸大小

    ui->listWidget->setItemWidget(ui->listWidget->item(m_itemCount++), item);
}

void ShoesDetailUI::on_pushButton_clicked()
{
    m_shoesDetails->createOrder();
}


void ShoesDetailUI::on_pb_addtoshopcart_clicked()
{
    m_shoesDetails->addToShopCart();
}
void ShoesDetailUI::slotAddShopCartResult(bool res)
{
    if(res)
    {
        QMessageBox::information(this, "提示", "加入购物车成功",
                             QMessageBox::Close);
    }
}
