#ifndef SHOWIMG_H
#define SHOWIMG_H

#include <QWidget>
#include <QImage>

namespace Ui {
class ShowImg;
}

class ShowImg : public QWidget
{
    Q_OBJECT

public:
    explicit ShowImg(const QString &photoPath, QWidget *parent = 0);
    ~ShowImg();
    bool setPhoto();
    QImage getImage();
private:
    Ui::ShowImg *ui;
    QString m_imgPath;
    QImage m_image;
};

#endif // SHOWIMG_H
