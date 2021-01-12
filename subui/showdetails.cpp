#include "showdetails.h"
#include "ui_showdetails.h"
#include "globalvalues.h"
#include "showimg.h"
#include <QDebug>
ShowDetails::ShowDetails(const QString &shoesName, QWidget *parent) :
    Photo(parent),
    ui(new Ui::ShowDetails)
{
    ui->setupUi(this);
    ui->lb_shoesName->setText(shoesName);

    ui->lb_price->setText("0");
    ui->lb_stock->setText("0");
    m_isLock = false;
    //m_showCount = 0;
}

ShowDetails::~ShowDetails()
{
    delete ui;
}

void ShowDetails::setDetails()
{
    m_isLock = true;
    ui->cb_color->clear();
    ui->cb_size->clear();
    qDebug() << "GlobalValues::g_shoesDetailsList->count()" << GlobalValues::g_shoesDetailsList->count();
    //将所有尺码配色放到下拉框里
    for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
    {
        if(ui->cb_size->findText(GlobalValues::g_shoesDetailsList->at(i).getSize()) == -1) //如果没有这个尺码就添加
        {
            ui->cb_size->addItem(GlobalValues::g_shoesDetailsList->at(i).getSize());
        }
        if(ui->cb_color->findText(GlobalValues::g_shoesDetailsList->at(i).getColor()) == -1)
        {
            ui->cb_color->addItem(GlobalValues::g_shoesDetailsList->at(i).getColor());
        }

    }
    m_isLock = false;
    //通过当前配色尺码找到相应的价格库存
    for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
    {
        if(ui->cb_color->currentText() == GlobalValues::g_shoesDetailsList->at(i).getColor())
        {
            if(ui->cb_size->currentText() == GlobalValues::g_shoesDetailsList->at(i).getSize())
            {
                ui->lb_price->setText(GlobalValues::g_shoesDetailsList->at(i).getPrice());
                ui->lb_stock->setText(GlobalValues::g_shoesDetailsList->at(i).getStock());
            }
            m_currentPhotoInfo.setID(GlobalValues::g_shoesDetailsList->at(i).getPhotoID());//根据配色找到ID
            qDebug() << "m_currentPhotoInfo.setID" << GlobalValues::g_shoesDetailsList->at(i).getPhotoID();
        }
    }

    qDebug() << "加载商品图片 图片信息列表数目" << GlobalValues::g_photoInfoList->count();
    ////加载商品图片
    //申请详情图片
    GlobalValues::g_mainWindow->slotGetPhotoForPhotoID(GlobalValues::g_localUser.getID(), m_currentPhotoInfo.getID(), true);
    GlobalValues::setPhotoMap.insert(m_currentPhotoInfo.getID(), this);
    qDebug() << "申请商品详情图片";
}
bool ShowDetails::setPhoto()
{
    qDebug() << "ShowDetails::setPhoto()";
    ListWidgetItemToMap.clear();
    ui->listWidget->clear();
    if(m_currentPhotoInfo.getID().isNull())
    {
        return false;
    }
    for(int i = 0; i < GlobalValues::g_photoInfoList->count(); i++)
    {
        qDebug() << "判断：" << m_currentPhotoInfo.getID() << "=" << GlobalValues::g_photoInfoList->at(i).getID();
        if(m_currentPhotoInfo.getID() == GlobalValues::g_photoInfoList->at(i).getID())
        {
            ui->listWidget->clear();
            m_currentPhotoInfo.setPhotoCount(GlobalValues::g_photoInfoList->at(i).getPhotoCount());
            m_currentPhotoInfo.setPhotoPath(GlobalValues::g_photoInfoList->at(i).getPhotoPath());
            break;
        }
    }
    qDebug() << "ShowDetails::setPhoto count:" << m_currentPhotoInfo.getPhotoCount().toInt();
    for(int i = 0; i < m_currentPhotoInfo.getPhotoCount().toInt(); i++)
    {
        m_imgPath = m_currentPhotoInfo.getPhotoPath() +
                        m_currentPhotoInfo.getID() + QString(" (%1).jpg").arg(i+1);
        qDebug() << "加载图片的路径：" << m_imgPath;
        ui->listWidget->addItem("");

        ShowImg *item = new ShowImg(m_imgPath);
        if(!item->setPhoto())
        {
            return false;
        }
        ui->listWidget->item(i)->setSizeHint(QSize(60, 80));//指定推荐尺寸大小

        ui->listWidget->setItemWidget(ui->listWidget->item(i), item);
        ListWidgetItemToMap.insert(i, item);
    }
    ui->lb_photo->setPixmap(QPixmap::fromImage(ListWidgetItemToMap[0]->getImage())
            .scaledToWidth(400, Qt::SmoothTransformation));

    return true;
}
void ShowDetails::on_cb_size_currentTextChanged(const QString &arg1)
{
    if(!m_isLock)
    {
        for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
        {
            if(ui->cb_color->currentText() == GlobalValues::g_shoesDetailsList->at(i).getColor())
            {
                if(ui->cb_size->currentText() == GlobalValues::g_shoesDetailsList->at(i).getSize())
                {
                    ui->lb_price->setText(GlobalValues::g_shoesDetailsList->at(i).getPrice());
                    ui->lb_stock->setText(GlobalValues::g_shoesDetailsList->at(i).getStock());
                    break;
                }
                ui->lb_stock->setText("0");//如果没找到就设置库存为0
            }
        }
    }

}

void ShowDetails::on_cb_color_currentTextChanged(const QString &arg1)
{
    if(!m_isLock)
    {

        for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
        {
            if(arg1 == GlobalValues::g_shoesDetailsList->at(i).getColor())
            {
                m_currentPhotoInfo.setID(GlobalValues::g_shoesDetailsList->at(i).getPhotoID());
            }
        }


        for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
        {
            if(ui->cb_color->currentText() == GlobalValues::g_shoesDetailsList->at(i).getColor())
            {
                if(ui->cb_size->currentText() == GlobalValues::g_shoesDetailsList->at(i).getSize())
                {
                    ui->lb_price->setText(GlobalValues::g_shoesDetailsList->at(i).getPrice());
                    ui->lb_stock->setText(GlobalValues::g_shoesDetailsList->at(i).getStock());
                    break;
                }
                ui->lb_stock->setText("0");//如果没找到就设置库存为0
            }
        }
        if(!setPhoto())     //如果图片没有设置成功，则申请图片
        {
            GlobalValues::g_mainWindow->slotGetPhotoForPhotoID(GlobalValues::g_localUser.getID(), m_currentPhotoInfo.getID(), true);
            GlobalValues::setPhotoMap.insert(m_currentPhotoInfo.getID(), this);
            qDebug() << "申请商品详情图片";
        }
    }
}

void ShowDetails::on_listWidget_currentRowChanged(int currentRow)
{
    ui->lb_photo->setPixmap(QPixmap::fromImage(ListWidgetItemToMap[currentRow]->getImage())
            .scaledToWidth(400, Qt::SmoothTransformation));
}
