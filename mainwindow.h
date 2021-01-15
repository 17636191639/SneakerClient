#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "msgproc.h"
#include "login.h"
#include "home.h"
#include "messageui.h"
#include "orderui.h"
#include "personalui.h"
#include "shopcartui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void signalRefreshShopCart();
    void singalRefreshOrderUI();
public slots:
    void slotUserLogin(QString id, QString pswd);
    void slotLoginResult(bool result);
    void slotGetShoesInfo(void);
    void slotGetPhotoForPhotoID(QString buyerID, QString photoID, bool isALL);
    void slotGetShoesDetails(QString buyerID, QString shoesID);
    void slotSendMsgToServer(QString msg);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initSellerUI(void);
    void initBuyerUI(void);
private slots:
    void on_home_triggered();

    void on_message_triggered();

    void on_shopcart_triggered();

    void on_order_triggered();

    void on_personalcenter_triggered();

private:
    Ui::MainWindow *ui;

    MsgProc *m_msgProc;
    Login *m_login;
    Home *m_home;
    MessageUI *m_messageUI;
    OrderUI *m_orderUI;
    ShopCartUI *m_shopCartUI;
    PersonalUI *m_personalUI;

};

#endif // MAINWINDOW_H
