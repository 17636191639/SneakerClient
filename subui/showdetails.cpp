#include "showdetails.h"
#include "ui_showdetails.h"
#include "globalvalues.h"
#include <QDebug>
ShowDetails::ShowDetails(const QString &shoesName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowDetails)
{
    ui->setupUi(this);
    ui->lb_shoesName->setText(shoesName);

    ui->lb_price->setText("0");
    ui->lb_stock->setText("0");
    m_isLock = false;
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

    //根据尺码找配色
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
    for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
    {
        if(ui->cb_color->currentText() == GlobalValues::g_shoesDetailsList->at(i).getColor())
        {
            if(ui->cb_size->currentText() == GlobalValues::g_shoesDetailsList->at(i).getSize())
            {
                ui->lb_price->setText(GlobalValues::g_shoesDetailsList->at(i).getPrice());
                ui->lb_stock->setText(GlobalValues::g_shoesDetailsList->at(i).getStock());
            }
        }
    }
    m_isLock = false;

}

void ShowDetails::on_cb_size_currentTextChanged(const QString &arg1)
{
    if(!m_isLock)
    {
        m_isLock = true;
        ui->cb_color->clear();
        //一种尺码下只显示这个尺码有的配色
        for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
        {
            if(arg1 == GlobalValues::g_shoesDetailsList->at(i).getSize())
            {
                if(ui->cb_color->findText(GlobalValues::g_shoesDetailsList->at(i).getColor()) == -1)
                {
                    ui->cb_color->addItem(GlobalValues::g_shoesDetailsList->at(i).getColor());
                }
            }
        }
        m_isLock = false;
        for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
        {
            if(ui->cb_color->currentText() == GlobalValues::g_shoesDetailsList->at(i).getColor())
            {
                if(ui->cb_size->currentText() == GlobalValues::g_shoesDetailsList->at(i).getSize())
                {
                    ui->lb_price->setText(GlobalValues::g_shoesDetailsList->at(i).getPrice());
                    ui->lb_stock->setText(GlobalValues::g_shoesDetailsList->at(i).getStock());
                }
            }
        }
    }

}

void ShowDetails::on_cb_color_currentTextChanged(const QString &arg1)
{
    if(!m_isLock)
    {
        ui->cb_size->clear();
        //一种配色下显示这个配色的尺码
        m_isLock = true;
        for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
        {
            if(arg1 == GlobalValues::g_shoesDetailsList->at(i).getColor())
            {
                if(ui->cb_size->findText(GlobalValues::g_shoesDetailsList->at(i).getSize()) == -1)
                {
                    ui->cb_size->addItem(GlobalValues::g_shoesDetailsList->at(i).getSize());
                }
            }
        }
        m_isLock = false;

        for(int i = 0; i < GlobalValues::g_shoesDetailsList->count(); i++)
        {
            if(ui->cb_color->currentText() == GlobalValues::g_shoesDetailsList->at(i).getColor())
            {
                if(ui->cb_size->currentText() == GlobalValues::g_shoesDetailsList->at(i).getSize())
                {
                    ui->lb_price->setText(GlobalValues::g_shoesDetailsList->at(i).getPrice());
                    ui->lb_stock->setText(GlobalValues::g_shoesDetailsList->at(i).getStock());
                }
            }
        }
    }

}
