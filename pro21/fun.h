#ifndef __FUN_H
#define __FUN_H
#include "sql.h"
#include "tcp.h"

void    Loading(char *p,char *q);   //登录
void    MyFun_Linklist_Handle();  //用户信息管理
void    MyFun_Data(DATA data);   //用户信息的数据
void    MyFun_Insert_Carinfo();    //添加车辆信息
void    MyFun_Car_Data(DATA data);   //车辆信息的数据
void    MyFun_Car_InAndPut(char *ip,char *port);    //出入库
void    MyFun_Car_Parking_Space(char *ip,char *port);   //分配车位
int     MyFun_Money_Count();    //计费
void    MyFun_Pay(int *num);   //支付
void    MyFun_Wechat_Pay(int *num);   //微信支付
void    MyFun_Alipay(int *num);  //支付宝支付
void    MyFun_Union_Pay(int *num);  //云支付支付
void    MyFun_Money_Find(int *num);   //查询费用


#endif