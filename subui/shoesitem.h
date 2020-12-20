#ifndef SHOESITEM_H
#define SHOESITEM_H

#include <QWidget>

namespace Ui {
class ShoesItem;
}

class ShoesItem : public QWidget
{
    Q_OBJECT

public:
    explicit ShoesItem(QString shoesName = "商品名称", QString price = "价格", QWidget *parent = 0);
    ~ShoesItem();

    void setItemPhoto(const QString & photoPath);
    void setShoesName(const QString & shoesName);
    void setShoesPrice(const QString & shoesPrice);
private:
    Ui::ShoesItem *ui;
};

#endif // SHOESITEM_H
