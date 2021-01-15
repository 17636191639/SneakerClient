#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <QWidget>

namespace Ui {
class OrderItem;
}

class OrderItem : public QWidget
{
    Q_OBJECT

public:
    explicit OrderItem(QWidget *parent = 0);
    ~OrderItem();

private:
    Ui::OrderItem *ui;
};

#endif // ORDERITEM_H
