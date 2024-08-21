#include "menu.h"
#include "sql.h"
#include "fun.h"
#include <stdio.h>
#include <unistd.h>

void    Welcome()  //欢迎界面
{
    puts("****************************************");
    puts("****************************************");  
    puts("*****    欢迎使用车位管理系统      *****");
    puts("*****                              *****");
    puts("*****                              *****");
    puts("*****        version-6.6.6         *****");
    puts("****************************************");
    puts("****************************************");
}


int    Show_Menu(char *p,char *q,char *ip,char *port)  //菜单
{
    puts("****************************************************");
    puts("****************************************************");
    puts("*****               0.退出菜单                 *****");
    puts("*****               1.用户管理                 *****");
    puts("*****               2.车辆管理                 *****");
    puts("*****               3.车位管理                 *****");
    puts("*****               4.费用管理                 *****");
    puts("****************************************************");
    puts("****************************************************");
    printf("please input 0-4:\n");
    int num;
    scanf("%d",&num);
    switch(num)
    {
        case 0: break;
        case 1:User_Mger(p,q); 
        break;
        case 2:Car_Num(ip,port);   //车辆
        break;
        case 3:Carnum_Num(ip,port);  //车位
        break;
        case 4:Money_Mger();  //费用
        break;
    }
    return num;
}

int    User_Mger(char *p,char *q)   //用户管理
{
    puts("****************************************************");
    puts("****************************************************");
    puts("*****                 0.返回                   *****");    
    puts("*****                 1.注册                   *****");
    puts("*****                 2.登录                   *****");
    puts("****************************************************");
    puts("****************************************************");
    puts("please input 0-2:");   
    int ret;
    scanf("%d",&ret);
    switch(ret)
    {
        case 0: break;
        case 1: MyFun_SQL(p,q);   // 注册 
        printf("注册成功\n");
        break;
        case 2: Loading(p,q);    //登录
        break;
    }
    return ret;
}


int    Car_Num(char *ip,char *port)    //车辆管理
{
    puts("****************************************************");
    puts("****************************************************");
    puts("*****                0.返回                    *****");    
    puts("*****             1.添加车辆信息               *****");
    puts("*****           2.出入库管理-车辆状态          *****");
    puts("****************************************************");
    puts("****************************************************");
    puts("please input 0-2:");
    int ret;
    scanf("%d",&ret);
    switch(ret)
    {
        case 0: break;
        case 1: MyFun_Insert_Carinfo();   //添加车辆信息
        printf("添加成功\n");
        break;
        case 2: MyFun_Car_InAndPut(ip,port);   //出入库
        break;
    }
    return ret;
}
    



int    Carnum_Num(char *ip,char *port)    //车位管理
{
    puts("****************************************************");
    puts("****************************************************");
    puts("*****                 0.返回                   *****");    
    puts("*****               1.分配车位                 *****");
    puts("****************************************************");
    puts("****************************************************");
    puts("****************************************************");
    int num=0;
    scanf("%d",&num);
    switch(num)
    {
        case 0: break;
        case 1: MyFun_Car_Parking_Space(ip,port); //分配车位
        break;
    }
    return num;
}


int    Money_Mger()    //费用
{
    puts("****************************************************");
    puts("****************************************************");
    puts("*****                  0.返回                  *****");    
    puts("*****                1.费用计费                *****");
    puts("*****                2.支付费用                *****");
    puts("*****                3.费用查询                *****");
    puts("****************************************************");
    puts("****************************************************");
    int ret;
    scanf("%d",&ret);
    int num=0;   //费用
    switch(ret)
    {
        case 0: break;
        case 1: num=MyFun_Money_Count();    //费用
        //break;
        case 2: MyFun_Pay(&num);   //支付
        //break;
        case 3: MyFun_Money_Find(&num);   //查询
        break;
    }
    return ret;
}