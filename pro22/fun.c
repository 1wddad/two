#include "menu.h"
#include "fun.h"
#include "tcp.h"
#include "sql.h"
#include <stdio.h>
#include <string.h>




void    Loading(char *p,char *q)   //登录
{
    char P[10]={0},Q[10]={0};
    puts("please input loading user and password:");
    scanf("%s%s",P,Q);   
    if((strcmp(p,P)==0&&strcmp(q,Q)==0))  //user and password  rigth
    {
        printf("登录成功\n");
        MyFun_Linklist_Handle();  //用户信息管理
    }
    else
    {
        printf("please check  user and password\n");
    }
}


void    MyFun_Linklist_Handle()  //用户信息管理
{
    puts("please input data");
    DATA data;
    scanf("%s",data.name);
    scanf("%d",&(data.phone));
    scanf("%s",data.carnum);
    MyFun_SQL2(&data);   //插入一个数据后，存储到数据库(用户信息)
}



void    MyFun_Insert_Carinfo()    //添加车辆信息
{
    puts("please input data");
    DATA data;
    scanf("%s",data.name);
    scanf("%d",&(data.phone));
    scanf("%s",data.carnum);
    scanf("%s",data.model);
    scanf("%s",data.color);
    MyFun_SQL3(&data);    //插入一个数据后，存储到数据库(车辆信息)
}




void    MyFun_Car_InAndPut(char *ip,char *port)    //出入库
{
    puts("please input 1-2:  1代表入库    2代表出库");
    int ret=0;
    scanf("%d",&ret);
    switch(ret)
    {
        case 1: MyFun_Sever_Carnum(ip,port);
        //MyFun_Client_Carnum(ip,port);
        break;
        case 2: MyFun_Sever_Carnum(ip,port);
        //MyFun_Client_Carnum(ip,port);
        break;
    }
}


void    MyFun_Car_Parking_Space(char *ip,char *port)   //分配车位
{
    puts("please input 1-2:  1代表入库(分配车位)    2代表出库(减少车位)");
    int ret=0;
    scanf("%d",&ret);
    switch(ret)
    {
        case 1://MyFun_Client_Carport(ip,port);
        MyFun_Sever_Carport(ip,port);
        break;
        case 2://MyFun_Client_Carport(ip,port);
        MyFun_Sever_Carport(ip,port);
        break;
    }
}



int    MyFun_Money_Count()    //计费
{
    int count_Money=0;
    printf("请输入在库的时长\n");
    int hour=0;
    scanf("%d",&hour);
    if(hour>0&&hour<=2)  //1-2h
    {
        count_Money=hour*2;
        return count_Money;
    }
    if(hour>=3&&hour<=5)  //3-5h
    {
        count_Money=2*2+(hour-2)*0.25;
        return count_Money;
    }
    if(hour>5)  //>5h
    {
        count_Money=2*2+3*0.25+(hour-5)*0.1;
        return count_Money;
    }
}

void    MyFun_Pay(int num)   //支付
{
    puts("****************************************************");
    puts("****************************************************");
    puts("*****                1.微信支付                  *****");
    puts("*****                2.支付宝支付                *****");
    puts("*****                3.云闪付支付                *****");
    puts("****************************************************");
    puts("****************************************************");
    int ret=0;
    scanf("%d",&ret);
    switch(ret)
    {
        case 1:MyFun_Wechat_Pay(num);
        break;
        case 2:MyFun_Alipay(num);
        break;
        case 3:MyFun_Union_Pay(num);
        break;
    }
}



void    MyFun_Wechat_Pay(int num)   //微信支付
{
    printf("please input  Money\n");
    int money=0;
    scanf("%d",&money);
    DATA data;
    if(money==num)
    {
        printf("支付成功\n");
        MyFun_SQL4(money);   //存到数据库中
        return ;
    }
    if(money>num)
    {
        printf("找你的零钱：%d\n",money-num);
        return ;
    }
    if(money<num)
    {
        printf("你输入的钱少了!或者换种支付方式付费!谢谢");
    }
}


void     MyFun_Alipay(int num)  //支付宝支付
{
    printf("please input  Money\n");
    int money=0;
    scanf("%d",&money);
    DATA data;
    if(money==num)
    {
        printf("支付成功\n");
        MyFun_SQL5(money);   //存到数据库中
        return ;
    }
    if(money>num)
    {
        printf("找你的零钱：%d\n",money-num);
        MyFun_SQL5(money);   //存到数据库中
        return ;
    }
    if(money<num)
    {
        printf("你输入的钱少了!或者换种支付方式付费!谢谢");
    }
}

void    MyFun_Union_Pay(int num)  //云支付支付
{
    printf("please input  Money\n");
    int money=0;
    scanf("%d",&money);
    DATA data;
    if(money==num)
    {
        printf("支付成功\n");
        MyFun_SQL6(money);   //存到数据库中
        return ;
    }
    if(money>num)
    {
        printf("找你的零钱：%d\n",money-num);
        MyFun_SQL6(money);   //存到数据库中
        return ;
    }
    if(money<num)
    {
        printf("你输入的钱少了!或者换种支付方式付费!谢谢");
    }
}



void    MyFun_Money_Find(int num)   //查询费用
{
    puts("****************************************************");
    puts("****************************************************");
    puts("*****               1.微信支付查询              *****");
    puts("*****               2.支付宝支付查询            *****");
    puts("*****               3.云闪付支付查询            *****");
    puts("****************************************************");
    puts("****************************************************");
    int ret=0;
    scanf("%d",&ret);
    DATA data;
    switch(ret)
    {
        case 1: printf("money:%d\n",num);
        break;
        case 2: printf("money:%d\n",num);
        break;
        case 3: printf("money:%d\n",num);
        break;
    }
}




