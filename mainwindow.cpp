#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalvalues.h"
#include <QMessageBox>
#include <QDesktopWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->menuBar->hide();
    ui->statusBar->hide();
    ui->mainToolBar->hide();


    m_login = new Login();
    m_login->show();
    this->hide();

    connect(m_login, SIGNAL(signalUserLogin(QString, QString)), this, SLOT(slotUserLogin(QString, QString)));

    m_msgProc = new MsgProc;
    connect(m_msgProc, SIGNAL(signalLoginResult(bool)), this, SLOT(slotLoginResult(bool)));

    m_msgProc->start();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::slotUserLogin(QString id, QString pswd)
{
    QString msg = QString("L#") + id +QString("|") + pswd;
    m_msgProc->slotSendMsg(msg);
}
void MainWindow::slotLoginResult(bool result)
{
    if(result)
    {
        m_login->close();
        this->show();
        if(GlobalValues::g_localUser.getRole() == "卖家")
        {
            initSellerUI();
            setFixedSize(800, 600);

            qDebug() << "Seller UI Init";
        }else if(GlobalValues::g_localUser.getRole() == "买家")
        {
            this->setWindowTitle("买家端");
            //this->setWindowIcon(QIcon(":/new/prefix1/2.jpg"));//设置窗口图标
            initBuyerUI();
            setFixedSize(m_home->frameSize() + QSize(20, 80));
            QDesktopWidget* desktop = QApplication::desktop();
            move((desktop->width() - this->width())/2, (desktop->height() - this->height())/2);
            ui->mainToolBar->show();
            qDebug() << "Buyer UI Init";
        }
    }else
    {
       m_login->userLoginFail();
    }
}

void MainWindow::initSellerUI(void)
{

}
void MainWindow::initBuyerUI(void)
{

    m_home = new Home(ui->widget);
    connect(m_home, SIGNAL(signalGetShoesInfo()), this, SLOT(slotGetShoesInfo()));
    connect(m_msgProc, SIGNAL(signalGetShoesResult(bool)), m_home, SLOT(slotGetShoesResult(bool)));
    connect(m_home, SIGNAL(signalGetShoesPhoto(QString, QString, bool)), this, SLOT(slotGetPhotoForPhotoID(QString, QString, bool)));

    //connect(m_msgProc, SIGNAL(signalSaveAllPhotoForIDSuccess(QString)), m_home, SLOT(slotSavePhotoSucess(QString)));
    connect(m_home, SIGNAL(signalGetShoesDetails(QString, QString)), this, SLOT(slotGetShoesDetails(QString, QString)));
    connect(m_msgProc, SIGNAL(signalGetShoesDetailsResult(bool)), m_home, SLOT(slotGetShoesDetailsResult(bool)));
    emit m_home->signalGetShoesInfo();
    connect(m_msgProc, SIGNAL(signalAddShopCartResult(bool)), m_home, SLOT(slotAddShopCartResult(bool)));

    m_messageUI = new MessageUI(ui->widget);

    m_shopCartUI = new ShopCartUI(ui->widget);
    connect(this, SIGNAL(signalRefreshShopCart()), m_shopCartUI, SLOT(slotAskShopCartInfoFromServer()));
    connect(m_msgProc, SIGNAL(signalGetShopCartInfo(bool)), m_shopCartUI, SLOT(slotGetShopCartInfoResult(bool)));
    connect(m_msgProc, SIGNAL(signalGetShoesDetailsFromDetailsIDResult(bool)), m_shopCartUI, SLOT(slotGetShoesDetailsFromDetailsIDResult(bool)));

    m_orderUI = new OrderUI(ui->widget);
    connect(this, SIGNAL(singalRefreshOrderUI()), m_orderUI, SLOT(slotAskOrderInfoToServer()));
    connect(m_msgProc, SIGNAL(signalGetOrderInfoResult(bool)), m_orderUI, SLOT(slotGetOrderInfoResult(bool)));
    connect(m_msgProc, SIGNAL(signalGetShoesDetailsByOrderResult(bool, QString)), m_orderUI, SLOT(slotGetShoesDetailsByOrderResult(bool, QString)));

    m_personalUI = new PersonalUI(ui->widget);
    connect(m_msgProc, SIGNAL(signalGetBuyerInfoResult(bool)), m_personalUI, SLOT(slotGetBuyerInfoResult(bool)) );
    m_home->show();
    m_messageUI->hide();
    m_orderUI->hide();
    m_shopCartUI->hide();
    m_personalUI->hide();

    ui->home->setEnabled(false);
    ui->message->setEnabled(true);
    ui->shopcart->setEnabled(true);
    ui->order->setEnabled(true);
    ui->personalcenter->setEnabled(true);
}
void MainWindow::slotGetShoesInfo(void)
{
    QString msg = QString(CMD_GetShoes_T) + QString("#") + GlobalValues::g_localUser.getID();
    m_msgProc->slotSendMsg(msg);
}
void MainWindow::slotGetPhotoForPhotoID(QString buyerID, QString photoID, bool isAll)
{
    QString msg = QString(CMD_GetShoesPhoto_A) + QString("#") +buyerID + QString("|") + photoID + QString("|");
    if(isAll)
    {
        msg += QString("true");
    }else
    {
        msg += QString("false");
    }

    m_msgProc->slotSendMsg(msg);
}
void MainWindow::slotGetShoesDetails(QString buyerID, QString shoesID)
{
    QString msg = QString(CMD_GetShoesDetail_F) + QString("#") + buyerID
                    + QString("|") + shoesID;
    m_msgProc->slotSendMsg(msg);
}
void MainWindow::slotSendMsgToServer(QString msg)
{
    m_msgProc->slotSendMsg(msg);
}

void MainWindow::on_home_triggered()
{
    m_home->show();
    m_messageUI->hide();
    m_orderUI->hide();
    m_shopCartUI->hide();
    m_personalUI->hide();

    ui->home->setEnabled(false);
    ui->message->setEnabled(true);
    ui->shopcart->setEnabled(true);
    ui->order->setEnabled(true);
    ui->personalcenter->setEnabled(true);
}

void MainWindow::on_message_triggered()
{
    m_home->hide();
    m_messageUI->show();
    m_orderUI->hide();
    m_shopCartUI->hide();
    m_personalUI->hide();

    ui->home->setEnabled(true);
    ui->message->setEnabled(false);
    ui->shopcart->setEnabled(true);
    ui->order->setEnabled(true);
    ui->personalcenter->setEnabled(true);
}

void MainWindow::on_shopcart_triggered()
{
    m_home->hide();
    m_messageUI->hide();
    m_orderUI->hide();
    m_shopCartUI->show();
    m_personalUI->hide();

    ui->home->setEnabled(true);
    ui->message->setEnabled(true);
    ui->shopcart->setEnabled(false);
    ui->order->setEnabled(true);
    ui->personalcenter->setEnabled(true);
    emit signalRefreshShopCart();
}

void MainWindow::on_order_triggered()
{
    m_home->hide();
    m_messageUI->hide();
    m_orderUI->show();
    emit singalRefreshOrderUI();
    m_shopCartUI->hide();
    m_personalUI->hide();

    ui->home->setEnabled(true);
    ui->message->setEnabled(true);
    ui->shopcart->setEnabled(true);
    ui->order->setEnabled(false);
    ui->personalcenter->setEnabled(true);
}

void MainWindow::on_personalcenter_triggered()
{
    m_home->hide();
    m_messageUI->hide();
    m_orderUI->hide();
    m_shopCartUI->hide();
    m_personalUI->show();

    ui->home->setEnabled(true);
    ui->message->setEnabled(true);
    ui->shopcart->setEnabled(true);
    ui->order->setEnabled(true);
    ui->personalcenter->setEnabled(false);
}
