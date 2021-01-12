#include "showimg.h"
#include "ui_showimg.h"

ShowImg::ShowImg(const QString &photoPath, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowImg)
{
    ui->setupUi(this);
    m_imgPath = photoPath;
//    QImage img;
//    //QImage img(photo);
//    //photo.scaled(200,200);
//    //QSize size = ui->lb_image->rect().size();
//    if(img.load(m_imgPath))
//    {
//        //安给定大小显示  Qt::SmoothTransformation平滑变换  清晰度
//        //ui->lb_image->setPixmap(QPixmap::fromImage(img).scaled(300, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
//        //适应宽显示
//        ui->lb_image->setPixmap(QPixmap::fromImage(img).scaledToWidth(300, Qt::SmoothTransformation));

//    }
}

ShowImg::~ShowImg()
{
    delete ui;
}
bool ShowImg::setPhoto()
{
    QImage img;
    //QImage img(photo);
    //photo.scaled(200,200);
    //QSize size = ui->lb_image->rect().size();
    if(img.load(m_imgPath))
    {
        //安给定大小显示  Qt::SmoothTransformation平滑变换  清晰度
        //ui->lb_image->setPixmap(QPixmap::fromImage(img).scaled(300, 300, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        //适应宽显示
        m_image = img;
        ui->lb_image->setPixmap(QPixmap::fromImage(img).scaledToWidth(40, Qt::SmoothTransformation));
        return true;
    }
    return false;
}
QImage ShowImg::getImage()
{

    return m_image;
}
