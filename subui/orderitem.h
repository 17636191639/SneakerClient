#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <QWidget>
#include "showimg.h"

namespace Ui {
class OrderItem;
}

class OrderItem : public QWidget
{
    Q_OBJECT

public:
    explicit OrderItem(const QString&orderID, const QString&orderDate, const QString&shoesName,
                       const QString&totalMoney, const QString&orderState, const QString&photoID, QWidget *parent = 0);
    ~OrderItem();

private:
    Ui::OrderItem *ui;

    ShowImg *m_showImg;
};

#endif // ORDERITEM_H
