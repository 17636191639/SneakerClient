#ifndef SHOWDETAILS_H
#define SHOWDETAILS_H

#include <QWidget>
#include "photo.h"
#include "photoinfo.h"
#include "showimg.h"
#include "createorder.h"
#include <QMap>
#define NOITEM -1
namespace Ui {
class ShowDetails;
}

class ShowDetails : public Photo
{
    Q_OBJECT

public:
    explicit ShowDetails(const QString &shoesName, QWidget *parent = 0);
    ~ShowDetails();
    void setDetails();
    void createOrder();
    void addToShopCart();
signals:
    void signalAddDetailsPhoto(QString);
private slots:
    void on_cb_size_currentTextChanged(const QString &arg1);

    void on_cb_color_currentTextChanged(const QString &arg1);
    bool setPhoto();
    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::ShowDetails *ui;
    bool m_isLock;
    PhotoInfo m_currentPhotoInfo;
    QMap<int, ShowImg *> ListWidgetItemToMap;
    QString m_currentShoesDetailsID;
    CreateOrder *m_orderUI;
};

#endif // SHOWDETAILS_H
