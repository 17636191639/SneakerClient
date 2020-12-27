#include "msgproc.h"
#include "globalvalues.h"
#include <QDataStream>
#include <QDebug>
#include "shoesinfo.h"
#include <QImage>

MsgProc::MsgProc(QThread *parent) : QThread(parent)
{
    m_isExit = false;
    m_tcpBlockSize = 0;
    m_tcpSocket = new QTcpSocket(this);
    m_count = 0;
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

}
void MsgProc::parseBuyerViewShopCart(QString data)
{

}
void MsgProc::parseBuyerViewEvaluation(QString data)
{

}
void MsgProc::parseBuyerUploadEvaluation(QString data)
{

}
void MsgProc::parseBuyerGetShoesPhoto(QString data)
{
    qDebug() << m_count++;
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
        //qDebug() << m_tcpSocket->state();
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

            if(tempByte.size() - sizeof(quint32) < m_tcpBlockSize) //总接受大小-2个字节就是数据大小
            {
                return;
            }
            qDebug() << "当前数据包大小：" << tempByte.size();
            QString msg;
            in >> msg;
            qDebug() << "Client Recv: " << msg;


            if(msg.at(0) == CMD_GetShoesPhoto_A)
            {
                QStringList msgList = msg.split("#");
                //应专门起一个线程处理图片
                QStringList list = msgList.at(1).split("|");
                QStringList photoInfo = list.at(1).split("&");
                QByteArray imgArray;
                in >> imgArray;

                QImage img;
                if(img.loadFromData(imgArray))  //图片加载成功
                {
                    QString savePath = QString("./shoes_photo/") + photoInfo.at(0) + QString(" (1).jpg") ;

                    qDebug() << "img.save():" << img.save(savePath);
                    emit signalSavePhotoSuccess(photoInfo.at(0));
                    //qDebug() << "img.save();" << savePath;
                }

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
