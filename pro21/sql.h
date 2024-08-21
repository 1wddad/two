#ifndef __SQL_H
#define __SQL_H

#include <mysql/mysql.h>


typedef struct car  
{
    char name[20];
    int phone;  //电话号
    char carnum[20];    //车牌号
    char model[20];
    char color[20];
    int cnum;   //车位信息
    int WechatPay;  //微信
    int Alipay;   //支付宝
    int Unionpay;   //云闪付
}DATA;


int MyFun_sql(MYSQL *p,const char *query);  //注册
int MyFun_SQL( char *r, char *q);   //注册的数据库
int MyFun_sql2(MYSQL *p,const char *query);
int MyFun_SQL2(const DATA *r);   //   存储车辆信息,用户信息的数据库
int MyFun_sql3(MYSQL *p,const char *query);  //车辆信息
int MyFun_SQL3(const DATA *r);   //   存储车辆信息的数据库
int MyFun_sql4(MYSQL *p,const char *query);  //费用信息
int MyFun_SQL4(int *moneypay);   //   存储费用信息的数据库  微信
int MyFun_sql5(MYSQL *p,const char *query);  //费用信息
int MyFun_SQL5(int *moneypay);   //   存储费用信息的数据库  支付宝
int MyFun_sql6(MYSQL *p,const char *query);  //费用信息
int MyFun_SQL6(int *moneypay);   //   存储费用信息的数据库  云闪付

#endif