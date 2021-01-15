#ifndef SHOPCARTITEM_H
#define SHOPCARTITEM_H

#include <QWidget>

namespace Ui {
class ShopCartItem;
}

class ShopCartItem : public QWidget
{
    Q_OBJECT

public:
    explicit ShopCartItem(QWidget *parent = 0);
    ~ShopCartItem();

private:
    Ui::ShopCartItem *ui;
};

#endif // SHOPCARTITEM_H
