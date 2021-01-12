#ifndef SHOESITEM_H
#define SHOESITEM_H

#include <QWidget>
#include <QImage>
#include "photo.h"
namespace Ui {
class ShoesItem;
}

class ShoesItem : public Photo
{
    Q_OBJECT

public:
    explicit ShoesItem(QString shoesName = "商品名称", QString price = "价格",
                       QString photoID = "", QWidget *parent = 0);
    ~ShoesItem();


    void setShoesName(const QString & shoesName);
    void setShoesPrice(const QString & shoesPrice);
    bool setPhoto(void);
private:
    Ui::ShoesItem *ui;

    QString m_photoID;
};

#endif // SHOESITEM_H
