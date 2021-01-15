#ifndef CREATEORDER_H
#define CREATEORDER_H

#include <QWidget>

namespace Ui {
class CreateOrder;
}

class CreateOrder : public QWidget
{
    Q_OBJECT

public:
    explicit CreateOrder(QWidget *parent = 0);
    ~CreateOrder();

private:
    Ui::CreateOrder *ui;
};

#endif // CREATEORDER_H
