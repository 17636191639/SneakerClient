#ifndef HOME_H
#define HOME_H

#include <QWidget>

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT
signals:
    void signalGetShoesInfo(void);
public slots:
    void slotGetShoesResult(bool);
public:
    explicit Home(QWidget *parent = 0);
    ~Home();
    void updateTalbeWidget(void);

private slots:
    void on_pb_refresh_clicked();

private:
    Ui::Home *ui;
};

#endif // HOME_H
