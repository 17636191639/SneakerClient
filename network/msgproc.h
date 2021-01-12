#ifndef MSGPROC_H
#define MSGPROC_H

#include <QThread>
#include <QTcpSocket>
#include <QByteArray>

class MsgProc : public QThread
{
    Q_OBJECT
public slots:
    void slotReadyRead();
    void slotSendMsg(QString msg);
signals:
    void signalSendMsg(QString msg);
    void signalLoginResult(bool);
    void signalGetShoesResult(bool);

    void signalSaveAllPhotoForIDSuccess(QString photoID);
    void signalGetShoesDetailsResult(bool);
public:
    explicit MsgProc(QThread *parent = 0);
    ~MsgProc();

    void exitThread(void);
protected:
    void run();
private:
    bool m_isExit;
    quint32 m_tcpBlockSize;
    QTcpSocket *m_tcpSocket;
    QByteArray m_byte;


     void parseUserAsk(QString msg);/////协议解析

     void parseUserLogin(QString data);
     void parseUserInfo(QString data);
     void parseChangePswd(QString data);
     void parseUserExit(QString data);

     void parseSellerGetShoesInfo(QString data);
     void parseSellerNewShoes(QString data);
     void parseSellerChangeShoes(QString data);
     void parseSellerDeleteShoes(QString data);
     void parseSellerShowOrders(QString data);
     void parseSellerModifyOrder(QString data);
     void parseSellerViewEvaluation(QString data);
     void parseSellerReceiveEvaluation(QString data);

     void parseBuyerGetShoesInfo(QString data);
     void parseBuyerGetOrder(QString data);
     void parseBuyerViewShopCart(QString data);
     void parseBuyerViewEvaluation(QString data);
     void parseBuyerUploadEvaluation(QString data);
     void parseBuyerGetShoesPhoto(QString data);
     void parseBuyerGetShoesDetails(QString data);
};

#endif // MSGPROC_H
