#include "globalvalues.h"

QQueue<QString> GlobalValues::g_msgQueue;
UserInfo GlobalValues::g_localUser;
ShoesInfoList *GlobalValues::g_shoesInfoList = new ShoesInfoList;
