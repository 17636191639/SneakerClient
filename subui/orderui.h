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

private:
    Ui::OrderUI *ui;
};

#endif // ORDERUI_H
