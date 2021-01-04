#ifndef SHOWDETAILS_H
#define SHOWDETAILS_H

#include <QWidget>

namespace Ui {
class ShowDetails;
}

class ShowDetails : public QWidget
{
    Q_OBJECT

public:
    explicit ShowDetails(const QString &shoesName, QWidget *parent = 0);
    ~ShowDetails();
    void setDetails();
private slots:
    void on_cb_size_currentTextChanged(const QString &arg1);

    void on_cb_color_currentTextChanged(const QString &arg1);

private:
    Ui::ShowDetails *ui;
    bool m_isLock;
};

#endif // SHOWDETAILS_H
