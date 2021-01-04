#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "msgproc.h"
#include "login.h"
#include "home.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void slotUserLogin(QString id, QString pswd);
    void slotLoginResult(bool result);
    void slotGetShoesInfo(void);
    void slotGetPhotoForPhotoID(QString buyerID, QString photoID);
    void slotGetShoesDetails(QString buyerID, QString shoesID);
    void slotSendMsgToServer(QString msg);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initSellerUI(void);
    void initBuyerUI(void);
private:
    Ui::MainWindow *ui;

    MsgProc *m_msgProc;
    Login *m_login;
    Home *m_home;

};

#endif // MAINWINDOW_H
