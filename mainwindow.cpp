#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globalvalues.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->menuBar->hide();
    ui->statusBar->hide();
    ui->mainToolBar->hide();
    setFixedSize(600,430);
    m_login = new Login(ui->widget);
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
        if(GlobalValues::g_localUser.getRole() == "卖家")
        {
            initSellerUI();
            setFixedSize(800, 600);

            qDebug() << "Seller UI Init";
        }else if(GlobalValues::g_localUser.getRole() == "买家")
        {
            initBuyerUI();
            setFixedSize(600, 800);
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
    connect(m_home, SIGNAL(signalGetShoesPhoto(QString, QString)), this, SLOT(slotGetPhotoForPhotoID(QString, QString)));
    connect(m_msgProc, SIGNAL(signalSavePhotoSuccess(QString)), m_home, SLOT(slotSavePhotoSucess(QString)));
    emit m_home->signalGetShoesInfo();

    m_home->show();
}
void MainWindow::slotGetShoesInfo(void)
{
    QString msg = QString(CMD_GetShoes_T) + QString("#") + GlobalValues::g_localUser.getID();
    m_msgProc->slotSendMsg(msg);
}
void MainWindow::slotGetPhotoForPhotoID(QString buyerID, QString photoID)
{
    QString msg = QString(CMD_GetShoesPhoto_A) + QString("#") +buyerID + QString("|") + photoID;
    m_msgProc->slotSendMsg(msg);
}
