#ifndef SHOPCARTITEM_H
#define SHOPCARTITEM_H

#include <QWidget>
#include "showimg.h"

namespace Ui {
class ShopCartItem;
}

class ShopCartItem : public QWidget
{
    Q_OBJECT

public:
    explicit ShopCartItem(const QString &photoID, const QString &shoesID, const QString &size, const QString &color,
                          const QString &shoesCount, const QString &price, QWidget *parent = 0);
    ~ShopCartItem();

private:
    Ui::ShopCartItem *ui;
    ShowImg *m_showImg;
};

#endif // SHOPCARTITEM_H

