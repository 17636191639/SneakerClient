#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "msgproc.h"
#include <QMap>
#include "shoesitem.h"
#include "shoesdetailui.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT
signals:
    void signalGetShoesInfo(void);
    void signalGetShoesPhoto(QString buyerID, QString photoID);
    void signalGetShoesDetails(QString buyerID, QString shoesID);
public slots:
    void slotGetShoesResult(bool);
    void slotSavePhotoSucess(QString photoID);

    void slotGetShoesDetailsResult(bool);
public:
    explicit Home(QWidget *parent = 0);
    ~Home();
    void updateTalbeWidget(void);

private slots:
    void on_pb_refresh_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::Home *ui;
    ShoesDetailUI *m_shoesDetailsUI;
    QWidget *m_parentWidget;
    QMap<QString, ShoesItem *> itemMap;
};

#endif // HOME_H
