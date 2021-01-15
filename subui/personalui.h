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

private:
    Ui::PersonalUI *ui;
};

#endif // PERSONALUI_H
