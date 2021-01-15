#include "showimg.h"
#include "ui_showimg.h"
#include "globalvalues.h"
#include <QDebug>

ShowImg::ShowImg(const QString &photoPath, QWidget *parent) :
    Photo(parent),
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

ShowImg::ShowImg(const QString &photoID, const QString &photoDir, QWidget *parent):
    Photo(parent),
    ui(new Ui::ShowImg)
{
    ui->setupUi(this);
    m_imgPath = photoDir + photoID + QString(" (1).jpg");
    m_photoID = photoID;
    //qDebug() << "ShowImg::ShowImg(const QString &photoID, const QString &photoDir, QWidget *parent)";
}
ShowImg::~ShowImg()
{
    delete ui;
}
bool ShowImg::setPhoto()
{
    QImage img;
    //qDebug() << "ShowImg::setPhoto()" << m_imgPath;
    if(img.load(m_imgPath))
    {
        m_image = img;
        ui->lb_image->setPixmap(QPixmap::fromImage(img).scaledToWidth(40, Qt::SmoothTransformation));
        //qDebug() << "setPhoto() 成功";
        return true;
    }
    return false;
}
QImage ShowImg::getImage()
{
    return m_image;
}
void ShowImg::setImgScaledToWidth(int wigth)
{
    ui->lb_image->setPixmap(QPixmap::fromImage(m_image).scaledToWidth(wigth, Qt::SmoothTransformation));
}
void ShowImg::getImageFromServerByPhotoID()  //显示单张照片可直接向服务器申请
{
    GlobalValues::g_mainWindow->slotGetPhotoForPhotoID(GlobalValues::g_localUser.getID(),
                                                       m_photoID, false);
    GlobalValues::setPhotoMap.insert(m_photoID, this);
}
