#ifndef PERSONALUI_H
#define PERSONALUI_H

#include <QWidget>

namespace Ui {
class PersonalUI;
}

class PersonalUI : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalUI(QWidget *parent = 0);
    ~PersonalUI();
    void askForBuyerInfo();
public slots:
    void slotGetBuyerInfoResult(bool);
private:
    Ui::PersonalUI *ui;
};

#endif // PERSONALUI_H
