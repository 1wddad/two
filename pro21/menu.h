#ifndef __MENU_H
#define __MENU_H


void    Welcome();  //欢迎界面
int    Show_Menu(char *p,char *q,char *ip,char *port);  //菜单
int    User_Mger(char *p,char *q);   //用户管理
int    Car_Num(char *ip,char *port);    //车辆管理
int    Carnum_Num(char *ip,char *port);    //车位管理
int    Money_Mger();    //费用

#endif