#ifndef MESSAGEUI_H
#define MESSAGEUI_H

#include <QWidget>

namespace Ui {
class MessageUI;
}

class MessageUI : public QWidget
{
    Q_OBJECT

public:
    explicit MessageUI(QWidget *parent = 0);
    ~MessageUI();

private:
    Ui::MessageUI *ui;
};

#endif // MESSAGEUI_H
