#ifndef ORDERUI_H
#define ORDERUI_H

#include <QWidget>


namespace Ui {
class OrderUI;
}

class OrderUI : public QWidget
{
    Q_OBJECT

public:
    explicit OrderUI(QWidget *parent = 0);
    ~OrderUI();
public slots:
    void slotAskOrderInfoToServer();
    void slotGetOrderInfoResult(bool);
    void slotGetShoesDetailsByOrderResult(bool, QString orderID);
private:
    Ui::OrderUI *ui;
    int m_itemCount;
};

#endif // ORDERUI_H
