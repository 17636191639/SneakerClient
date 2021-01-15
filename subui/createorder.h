#ifndef CREATEORDER_H
#define CREATEORDER_H

#include <QWidget>

namespace Ui {
class CreateOrder;
}

class CreateOrder : public QWidget
{
    Q_OBJECT

public:
    explicit CreateOrder(const QString &shoesName, const QString &price, const QString &size,
                         const QString &color, const QString &count, const QImage &shoesPhoto,
                         const QString &detailsID, QWidget *parent = 0);
    ~CreateOrder();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreateOrder *ui;
    QString m_detailsID;
};

#endif // CREATEORDER_H
