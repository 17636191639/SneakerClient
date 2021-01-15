#ifndef SHOPCARTUI_H
#define SHOPCARTUI_H

#include <QWidget>
#include "shopcartitem.h"

namespace Ui {
class ShopCartUI;
}

class ShopCartUI : public QWidget
{
    Q_OBJECT

public:
    explicit ShopCartUI(QWidget *parent = 0);
    ~ShopCartUI();
public slots:
    void slotAskShopCartInfoFromServer(void);
    void slotGetShopCartInfoResult(bool);
    void slotGetShoesDetailsFromDetailsIDResult(bool);
private:
    Ui::ShopCartUI *ui;
    int m_itemCount;
};

#endif // SHOPCARTUI_H
