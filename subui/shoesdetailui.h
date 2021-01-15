#ifndef SHOESDETAILUI_H
#define SHOESDETAILUI_H

#include <QWidget>
#include "showdetails.h"

namespace Ui {
class ShoesDetailUI;
}

class ShoesDetailUI : public QWidget
{
    Q_OBJECT

public:
    explicit ShoesDetailUI(const QString &shoesID, const QString &shoesName, QWidget *parent = 0, QWidget *lastUI = 0);
    ~ShoesDetailUI();
    void setShoesDetails();
    void hideEvent(QHideEvent *event);


public slots:
    void slotAddShopCartResult(bool);
private slots:
    void on_pb_back_clicked();
    void slotAddDetailsPhoto(const QString &);
    void on_pushButton_clicked();


    void on_pb_addtoshopcart_clicked();

private:
    Ui::ShoesDetailUI *ui;
    ShowDetails *m_shoesDetails;
    QWidget *m_lastUI;
    QString m_shoesID;
    int m_itemCount;
};

#endif // SHOESDETAILUI_H
