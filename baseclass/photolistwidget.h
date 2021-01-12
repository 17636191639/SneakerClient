#ifndef PHOTOLISTWIDGET_H
#define PHOTOLISTWIDGET_H

#include <QListWidget>
#include <QImage>

class PhotoListWidget : public QListWidget
{
public:
    PhotoListWidget();
    QImage *item(int row);
};

#endif // PHOTOLISTWIDGET_H
