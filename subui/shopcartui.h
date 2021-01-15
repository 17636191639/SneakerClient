#ifndef SHOPCARTUI_H
#define SHOPCARTUI_H

#include <QWidget>

namespace Ui {
class ShopCartUI;
}

class ShopCartUI : public QWidget
{
    Q_OBJECT

public:
    explicit ShopCartUI(QWidget *parent = 0);
    ~ShopCartUI();

private:
    Ui::ShopCartUI *ui;
};

#endif // SHOPCARTUI_H
