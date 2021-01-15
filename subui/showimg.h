#ifndef SHOWIMG_H
#define SHOWIMG_H

#include <QWidget>
#include <QImage>
#include "photo.h"

namespace Ui {
class ShowImg;
}

class ShowImg : public Photo//显示单张照片
{
    Q_OBJECT

public:
    explicit ShowImg(const QString &photoPath, QWidget *parent = 0);
    ShowImg(const QString &photoID, const QString &photoDir, QWidget *parent = 0);//只需要显示一张照片的情况下使用
    ~ShowImg();
    bool setPhoto();
    QImage getImage();
    void setImgScaledToWidth(int wigth);
    void getImageFromServerByPhotoID();
private:
    Ui::ShowImg *ui;
    QString m_imgPath;
    QImage m_image;
    QString m_photoID;

};

#endif // SHOWIMG_H
