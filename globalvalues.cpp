#include "globalvalues.h"
#include <QTime>
#include <QCoreApplication>

QQueue<QString> GlobalValues::g_msgQueue;
UserInfo GlobalValues::g_localUser;
ShoesInfoList *GlobalValues::g_shoesInfoList = new ShoesInfoList;
ShoesDetailsList *GlobalValues::g_shoesDetailsList = new ShoesDetailsList;

void QSleep(unsigned int msec)
{
    QTime reachTime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < reachTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
