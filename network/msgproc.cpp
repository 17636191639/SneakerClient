#include "msgproc.h"
#include "globalvalues.h"
#include <QDataStream>
#include <QDebug>
#include "shoesinfo.h"
#include <QImage>
#include "shoesdetails.h"
#include "photoinfo.h"
#include "shopcart.h"
#include "buyerinfo.h"

MsgProc::MsgProc(QThread *parent) : QThread(parent)
{
    m_isExit = false;
    m_tcpBlockSize = 0;
    m_tcpSocket = new QTcpSocket(this);
    m_byte.clear();

    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    m_tcpSocket->connectToHost("localhost", 5555);
}
MsgProc::~MsgProc()
{

}

void MsgProc::parseUserAsk(QString msg)
{
    QStringList list = msg.split("#");
    int cmd = msg.at(0).toLatin1();
    switch (cmd) {
    ///通用请求命令
    case CMD_UserLogin_L: parseUserLogin(list.at(1)); break;
    case CMD_UserInfo_I: parseUserInfo(list.at(1)); break;
    case CMD_ChangePswd_H: parseChangePswd(list.at(1)); break;
    case CMD_UserExit_X: parseUserExit(list.at(1)); break;
    ///卖家命令
    case CMD_GetShoesInfo_G: parseSellerGetShoesInfo(list.at(1)); break;
    case CMD_NewShoes_N: parseSellerNewShoes(list.at(1)); break;
    case CMD_ChangeShoes_C: parseSellerChangeShoes(list.at(1)); break;
    case CMD_DeleteShoes_D: parseSellerDeleteShoes(list.at(1)); break;
    case CMD_ShowOrders_S: parseSellerShowOrders(list.at(1)); break;
    case CMD_ModifyOrder_M: parseSellerModifyOrder(list.at(1)); break;
    case CMD_ViewEvaluations_V: parseSellerViewEvaluation(list.at(1)); break;
    case CMD_ReceiveEvaluation_E: parseSellerReceiveEvaluation(list.at(1)); break;
    ///买家命令
    case CMD_GetShoes_T: parseBuyerGetShoesInfo(list.at(1)); break;
    case CMD_GetOrder_O: parseBuyerGetOrder(list.at(1)); break;
    case CMD_ViewShopCart_P: parseBuyerViewShopCart(list.at(1)); break;
    case CMD_ViewEvaluation_W: parseBuyerViewEvaluation(list.at(1)); break;
    case CMD_UploadEvaluation_U: parseBuyerUploadEvaluation(list.at(1)); break;
    case CMD_GetShoesPhoto_A: parseBuyerGetShoesPhoto(list.at(1)); break;
    case CMD_GetShoesDetail_F:parseBuyerGetShoesDetails(list.at(1)); break;
    case CMD_GetShoesDetailFromDetailsID_f:parseBuyerGetShoesDetailFromDetailsID(list.at(1));break;
    case CMD_GetShoesDetailByOrder_o:parseBuyerGetShoesDetailsByOrder(list.at(1));break;
    case CMD_AddToShopCart_p:parseBuyerAddToShopCart(list.at(1));break;
    case CMD_GetBuyerInfo_B:parseBuyerGetBuyerInfo(list.at(1));break;

    default:
        break;
    }
}
//////////////////////////////////////////////  user  //////////////////////////////
void MsgProc::parseUserLogin(QString data)//解析登录返回数据
{
    QStringList list = data.split("|");
    int result = data.at(0).toLatin1();
    if(result == RES_Success)
    {
        GlobalValues::g_localUser.setID(list.at(1));
        GlobalValues::g_localUser.setPswd(list.at(2));
        GlobalValues::g_localUser.setRole(list.at(3));
        GlobalValues::g_localUser.setDate(list.at(4));
        emit signalLoginResult(true);
    }else
    {
        emit signalLoginResult(false);
    }

}
void MsgProc::parseUserInfo(QString data)
{

}

void MsgProc::parseChangePswd(QString data)
{

}
void MsgProc::parseUserExit(QString data)
{

}
//////////////////////////////////////////////  seller  //////////////////////////////////////
void MsgProc::parseSellerGetShoesInfo(QString data)
{

}
void MsgProc::parseSellerNewShoes(QString data)
{

}
void MsgProc::parseSellerChangeShoes(QString data)
{

}
void MsgProc::parseSellerDeleteShoes(QString data)
{

}
void MsgProc::parseSellerShowOrders(QString data)
{

}
void MsgProc::parseSellerModifyOrder(QString data)
{

}
void MsgProc::parseSellerViewEvaluation(QString data)
{

}
void MsgProc::parseSellerReceiveEvaluation(QString data)
{

}
//////////////////////////////////////////////  buyer   //////////////////////////////////
void MsgProc::parseBuyerGetShoesInfo(QString data)
{
    QStringList list = data.split("|");
    int result = data.at(0).toLatin1();
    list.pop_front();
    if(result == RES_Success)
    {
        GlobalValues::g_shoesInfoList->clear();
        while(!list.isEmpty())
        {
            QString shoes_info = list.at(0);
            qDebug() << shoes_info;
            QStringList infoList = shoes_info.split("&");
            ShoesInfo info;
            info.setID(infoList.at(0));
            info.setStoreID(infoList.at(1));
            info.setPhotoID(infoList.at(2));
            info.setShoesName(infoList.at(3));
            info.setBottomPrice(infoList.at(4));
            info.setFreight(infoList.at(5));
            GlobalValues::g_shoesInfoList->append(info);
            list.pop_front();
        }

        emit signalGetShoesResult(true);
    }else
    {
        emit signalGetShoesResult(false);
    }


}
void MsgProc::parseBuyerGetOrder(QString data)
{
    //O# !|MH-011|O-202012070001&MH-011&D-0001&1&已付款&2020-12-07 10:10:10&null&null
    QStringList list = data.split("|");
    char result = data.at(0).toLatin1();
    list.pop_front();
    if(result == RES_Success)
    {
        if(list.at(0) == GlobalValues::g_localUser.getID())
        {
            list.pop_front(); //将链表中存储的buyerID删除
            GlobalValues::g_orderInfoList->clear();
            while(!list.isEmpty())
            {
                QString orderInfo = list.at(0);
                qDebug() << orderInfo;
                QStringList infoList = orderInfo.split("&");
                OrderInfo info;
                info.setID(infoList.at(0));
                info.setBuyID(infoList.at(1));
                info.setDetailID(infoList.at(2));
                info.setCount(infoList.at(3));
                info.setState(infoList.at(4));
                info.setCreateDate(infoList.at(5));
                info.setDeliveryDate(infoList.at(6));
                info.setFinishDate(infoList.at(7));
                GlobalValues::g_orderInfoList->append(info);
                list.pop_front();
            }

            emit signalGetOrderInfoResult(true);
        }

    }else
    {
        emit signalGetOrderInfoResult(false);
    }
}
void MsgProc::parseBuyerViewShopCart(QString data)
{
    // !|MH-011&D-0001&1|MH-011&D-0002&2
    QStringList list = data.split("|");
    char result = data.at(0).toLatin1();
    list.pop_front();
    if(result == RES_Success)
    {
        GlobalValues::g_shopCartList->clear();
        while(!list.isEmpty())
        {
            QString shoes_info = list.at(0);
            qDebug() << shoes_info;
            QStringList infoList = shoes_info.split("&");
            ShopCart info;
            info.setID(infoList.at(0));
            info.setDetailID(infoList.at(1));
            info.setCount(infoList.at(2));

            GlobalValues::g_shopCartList->append(info);
            list.pop_front();
        }
        emit signalGetShopCartInfo(true);

    }else
    {
        emit signalGetShopCartInfo(false);
    }
}
void MsgProc::parseBuyerViewEvaluation(QString data)
{

}
void MsgProc::parseBuyerUploadEvaluation(QString data)
{

}
void MsgProc::parseBuyerGetShoesPhoto(QString data)
{

}
void MsgProc::parseBuyerGetShoesDetails(QString data)
{
    QStringList list = data.split("|");
    char result = data.at(0).toLatin1();
    list.pop_front();
    if(result == RES_Success)
    {
        if(list.at(0) == GlobalValues::g_localUser.getID())
        {
            list.pop_front(); //将链表中存储的buyerID删除
            GlobalValues::g_shoesDetailsList->clear();
            while(!list.isEmpty())
            {
                QString shoesDetails = list.at(0);
                qDebug() << shoesDetails;
                QStringList infoList = shoesDetails.split("&");
                ShoesDetails info;
                info.setID(infoList.at(0));
                info.setShoesID(infoList.at(1));
                info.setPhotoID(infoList.at(2));
                info.setSize(infoList.at(3));
                info.setColor(infoList.at(4));
                info.setPrice(infoList.at(5));
                info.setStock(infoList.at(6));
                GlobalValues::g_shoesDetailsList->append(info);
                list.pop_front();
            }

            emit signalGetShoesDetailsResult(true);
        }

    }else
    {
        emit signalGetShoesDetailsResult(false);
    }
}

void MsgProc::exitThread(void)
{
    m_isExit = true;
}

void MsgProc::run()
{
    while(!m_isExit)
    {
        if(!GlobalValues::g_msgQueue.isEmpty())
        {
            QString msg = GlobalValues::g_msgQueue.dequeue();
            parseUserAsk(msg);  //解析命令
        }
        msleep(20);
    }
}
void MsgProc::slotReadyRead()
{


    if(m_tcpSocket->bytesAvailable() == 65536)  //接受数据满包说明没发完
    {
        m_byte.append(m_tcpSocket->readAll());
    }else
    {
        m_byte.append(m_tcpSocket->readAll());

        //处理粘包
        int readSize = 0;
        QByteArray tempByte = m_byte;
        qDebug() << "m_byte.size(): " << m_byte.size();
        while(m_byte.size() - readSize)
        {
            QDataStream in(tempByte);
            in.setVersion(QDataStream::Qt_4_6);

            if(m_tcpBlockSize == 0)
            {
                if(tempByte.size() < sizeof(quint32))
                {
                    return;
                }
                in >> m_tcpBlockSize;  //获取数据的长度
            }
            //处理半包   数据只接受了一半  跳出函数继续接受

            if(tempByte.size() - sizeof(quint32) < m_tcpBlockSize) //总接受大小sizeof(quint32)个字节就是数据大小
            {
                return;
            }
            qDebug() << "当前数据包大小：" << tempByte.size();
            QString msg;
            in >> msg;
            qDebug() << "Client Recv cmd: " << msg;


            if(msg.at(0) == CMD_GetShoesPhoto_A)
            {
                QStringList msgList = msg.split("#");
                //应专门起一个线程处理图片
                QStringList list = msgList.at(1).split("|");
                QStringList photoInfo = list.at(1).split("&");
                int count = photoInfo.at(1).toInt();
                PhotoInfo info(photoInfo.at(0), photoInfo.at(1), photoInfo.at(2));
                GlobalValues::g_photoInfoList->append(info);
                if(photoInfo.at(3) == "true")
                {
                    for(int i = 0; i < count; i++)
                    {
                        QByteArray imgArray;
                        in >> imgArray;

                        QImage img;
                        if(img.loadFromData(imgArray))  //图片加载成功
                        {
                            QString savePath = info.getPhotoPath() + info.getID() + QString(" (%1).jpg").arg(i + 1) ;

                            qDebug() << "img.save():" << img.save(savePath) << savePath;
                            //emit signalSaveAllPhotoForIDSuccess(photoInfo.at(0));

                        }

                    }
                    if(GlobalValues::setPhotoMap.contains(info.getID()))
                    {
                        GlobalValues::setPhotoMap[info.getID()]->setPhoto();
                        GlobalValues::setPhotoMap.remove(info.getID());
                    }
                }else
                {
                    QByteArray imgArray;
                    in >> imgArray;

                    QImage img;
                    if(img.loadFromData(imgArray))  //图片加载成功
                    {
                        QString savePath = info.getPhotoPath() + info.getID() + QString(" (1).jpg") ;
                        qDebug() << "img.save():" << img.save(savePath);
                        if(GlobalValues::setPhotoMap.contains(info.getID()))
                        {
                            GlobalValues::setPhotoMap[info.getID()]->setPhoto();
                            GlobalValues::setPhotoMap.remove(info.getID());
                        }

                        qDebug() << "img.save();" << savePath;
                    }
                }

                //qDebug() << "count" << count;



            }else
            {
                GlobalValues::g_msgQueue.enqueue(msg);
            }

            readSize += m_tcpBlockSize + sizeof(quint32);
            qDebug() << "占位符大小：" << m_tcpBlockSize << "累计已读数据" << readSize;
            tempByte = m_byte.right(m_byte.size() - readSize);
            m_tcpBlockSize = 0;
        }
        m_byte.clear();
    }
}
void MsgProc::slotSendMsg(QString msg)
{
    QByteArray buffer;
    QDataStream out(&buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);


    out << (quint32)0;
    out << msg;
    out.device()->seek(0);
    out << (quint32)(buffer.size() - sizeof(quint32));
    m_tcpSocket->write(buffer);
    qDebug() << "Client Send: " << msg;
}
void MsgProc::parseBuyerGetShoesDetailFromDetailsID(QString data)
{
    //f# !|buyerID|D-0002&SH-0001&PS-0001&41&中帮/黑红脚趾&1170&9
    QStringList list = data.split("|");
    char result = data.at(0).toLatin1();
    list.pop_front();
    if(result == RES_Success)
    {
        if(list.at(0) == GlobalValues::g_localUser.getID())
        {
            list.pop_front(); //将链表中存储的buyerID删除
            GlobalValues::g_shoesDetailsList->clear();
            while(!list.isEmpty())
            {
                QString shoesDetails = list.at(0);
                qDebug() << shoesDetails;
                QStringList infoList = shoesDetails.split("&");
                ShoesDetails info;
                info.setID(infoList.at(0));
                info.setShoesID(infoList.at(1));
                info.setPhotoID(infoList.at(2));
                info.setSize(infoList.at(3));
                info.setColor(infoList.at(4));
                info.setPrice(infoList.at(5));
                info.setStock(infoList.at(6));
                GlobalValues::g_shoesDetailsList->append(info);
                list.pop_front();
            }

            emit signalGetShoesDetailsFromDetailsIDResult(true);
        }

    }else
    {
        emit signalGetShoesDetailsFromDetailsIDResult(false);
    }
}
void MsgProc::parseBuyerGetShoesDetailsByOrder(QString data)
{
    //o# !|MH-011|orderID|D-0001&SH-0001&PS-0001&40&中帮/黑红脚趾&1170&10   //每次只发一条回来
    QStringList list = data.split("|");
    char result = data.at(0).toLatin1();
    list.pop_front();
    if(result == RES_Success)
    {
        if(list.at(0) == GlobalValues::g_localUser.getID())
        {
            list.pop_front(); //将链表中存储的buyerID删除
            GlobalValues::g_shoesDetailsList->clear();
            QString orderID = list.at(0);  //订单ID

            QString shoesDetails = list.at(1);
            qDebug() << shoesDetails;
            QStringList infoList = shoesDetails.split("&");
            ShoesDetails info;
            info.setID(infoList.at(0));
            info.setShoesID(infoList.at(1));
            info.setPhotoID(infoList.at(2));
            info.setSize(infoList.at(3));
            info.setColor(infoList.at(4));
            info.setPrice(infoList.at(5));
            info.setStock(infoList.at(6));
            GlobalValues::g_shoesDetailsList->append(info);



            emit signalGetShoesDetailsByOrderResult(true, orderID);//将订单ID一并返回
            qDebug() << "商品详情列表数量" << GlobalValues::g_shoesDetailsList->count();
        }

    }else
    {
        emit signalGetShoesDetailsByOrderResult(false, "错误");
    }
}
void MsgProc::parseBuyerAddToShopCart(QString data)
{
    //p#  !|MH-011|添加购物车成功！
    QStringList list = data.split("|");
    char result = data.at(0).toLatin1();
    list.pop_front();
    if(result == RES_Success)
    {
        if(list.at(0) == GlobalValues::g_localUser.getID())
        {
            emit signalAddShopCartResult(true);
        }
    }else
    {
        emit signalAddShopCartResult(false);
    }
}
void MsgProc::parseBuyerGetBuyerInfo(QString data)
{
    //B#   !|MH-011|MH-011&希筠&13411111111&山西省太原市杏花岭区
    QStringList list = data.split("|");
    char result = data.at(0).toLatin1();
    list.pop_front();
    if(result == RES_Success)
    {
        if(list.at(0) == GlobalValues::g_localUser.getID())
        {

            QStringList buyerInfo = list.at(1).split("&");
            GlobalValues::g_buyerInfo->setID(buyerInfo.at(0));
            GlobalValues::g_buyerInfo->setName(buyerInfo.at(1));
            GlobalValues::g_buyerInfo->setTelephone(buyerInfo.at(2));
            GlobalValues::g_buyerInfo->setAddress(buyerInfo.at(3));

            emit signalGetBuyerInfoResult(true);

        }
    }else
    {
        emit signalGetBuyerInfoResult(false);
    }
}
