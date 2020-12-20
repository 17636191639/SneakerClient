#ifndef GLOBALVALUES_H
#define GLOBALVALUES_H
#include <QQueue>
#include "userinfo.h"
#include "shoesinfo.h"
#include "shoesdetails.h"
enum Oper_Data{
    Oper_None,
    Oper_Add,
    Oper_Del,
    Oper_Mdy
};

enum RESPONSE{
    RES_Success = '!',
    RES_Fail = '?'
};

enum COMMAND{
    ///通用请求命令
    CMD_UserLogin_L = 'L',          //用户登录
    CMD_UserInfo_I = 'I',           //获取个人信息
    CMD_ChangePswd_H = 'H',         //修改密码
    CMD_UserExit_X = 'X',           //用户退出
    ///买家请求命令
    CMD_GetShoes_T = 'T',    //商品信息
    CMD_GetOrder_O = 'O',      //订单信息
    CMD_ViewShopCart_P = 'P',     //购物车信息
    CMD_ViewEvaluation_W = 'W',         //评价信息
    CMD_UploadEvaluation_U = 'U',         //上传评价
    ///卖家请求命令
    CMD_GetShoesInfo_G = 'G',    //商品信息
    CMD_NewShoes_N = 'N',        //上架商品
    CMD_ChangeShoes_C = 'C',         //修改商品
    CMD_DeleteShoes_D = 'D',           //下架商品
    CMD_ShowOrders_S = 'S',         //订单信息
    CMD_ModifyOrder_M = 'M' ,          //订单状态修改

    CMD_ViewEvaluations_V = 'V',     //查看评价信息
    CMD_ReceiveEvaluation_E = 'E'    //回复评价
};
class GlobalValues
{
public:
    static QQueue<QString> g_msgQueue; //消息队列
    static UserInfo g_localUser;
    static ShoesInfoList *g_shoesInfoList;
};

#endif // GLOBALVALUES_H
