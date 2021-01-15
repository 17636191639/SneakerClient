#ifndef PHOTO_H
#define PHOTO_H

#include <QWidget>
#include <QString>

class Photo :public QWidget
{
    Q_OBJECT
public:
    Photo(QWidget *parent = 0);
    virtual bool setPhoto(void) = 0;//纯虚函数，可以不在父类中实现，但是父类是抽象类无法实体化
    QString m_imgPath;
};

#endif // PHOTO_H
