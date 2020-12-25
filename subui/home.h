#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include "msgproc.h"
#include <QMap>
#include "shoesitem.h"

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT
signals:
    void signalGetShoesInfo(void);
    void signalGetShoesPhoto(QString buyerID, QString photoID);
public slots:
    void slotGetShoesResult(bool);
    void slotSavePhotoSucess(QString photoID);
public:
    explicit Home(QWidget *parent = 0);
    ~Home();
    void updateTalbeWidget(void);

private slots:
    void on_pb_refresh_clicked();

private:
    Ui::Home *ui;
    //MsgProc m_proc;
    QMap<QString, ShoesItem *> itemMap;
};

#endif // HOME_H
