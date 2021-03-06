﻿#include "globalvalues.h"
#include <QTime>
#include <QCoreApplication>

QMap<QString, Photo *> GlobalValues::setPhotoMap;
QQueue<QString> GlobalValues::g_msgQueue;
UserInfo GlobalValues::g_localUser;
ShoesInfoList *GlobalValues::g_shoesInfoList = new ShoesInfoList;
ShoesDetailsList *GlobalValues::g_shoesDetailsList = new ShoesDetailsList;
PhotoInfoList *GlobalValues::g_photoInfoList = new PhotoInfoList;
MainWindow *GlobalValues::g_mainWindow;
OrderInfoList *GlobalValues::g_orderInfoList = new OrderInfoList;

ShopCartList *GlobalValues::g_shopCartList = new ShopCartList;
BuyerInfo *GlobalValues::g_buyerInfo = new BuyerInfo;



void QSleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
