#ifndef SHOESITEM_H
#define SHOESITEM_H

#include <QWidget>
#include <QImage>

namespace Ui {
class ShoesItem;
}

class ShoesItem : public QWidget
{
    Q_OBJECT

public:
    explicit ShoesItem(QString shoesName = "商品名称", QString price = "价格",
                       QString photoID = "", QWidget *parent = 0);
    ~ShoesItem();

    bool setItemPhoto(void);
    void setShoesName(const QString & shoesName);
    void setShoesPrice(const QString & shoesPrice);
private:
    Ui::ShoesItem *ui;

    QString m_photoID;
};

#endif // SHOESITEM_H
