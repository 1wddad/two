#include "sql.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <mysql/mysql.h>



int MyFun_sql(MYSQL *p,const char *query)  //注册
{
	int ret=mysql_query(p,query);
	if(ret!=0)
	{
		printf("query sql faield:%s\n",query);
		mysql_close(p);
		exit(0);
	}
	return 0;
}

char *user,*password;
int MyFun_SQL( char *r,char *q)   //注册的数据库
{
	user=r,password=q;
	char *u="root";
	char *p2="ldh88888";
	MYSQL *p=mysql_init(NULL);
	if(p==NULL)
	{
		perror("mysql init failed\n");
		return -1;
	}
	p=mysql_real_connect(p,"127.0.0.1","root","ldh010724qwer",NULL,0,NULL,0);
	if(p==NULL)   //failed   close
	{
		perror("concent failed\n");
		mysql_close(p);
		return -1;
	}
	MyFun_sql(p,"create database if not exists store_info;");
	MyFun_sql(p,"use store_info;");
	MyFun_sql(p,"create table if not exists loading(name varchar(10) primary key,password varchar(8) unique key);");   //注册
	mysql_set_character_set(p,"utf8");
	char sql_query[256]={'\0'};   //sql_query 指向insert 语句 '%s' =='root' 
	sprintf(sql_query,"insert into loading (name,password) values ('%s','%s');",r,q);   //格式化字符串
	if(MyFun_sql(p,sql_query)!=0)   //调用MyFun_sql函数
	{
		perror("query failed\n");
		mysql_close(p);
		return -1;
	}
    if(strcmp(r,u)==0&&strcmp(q,p2)==0)   //管理员可以查看数据库中的数据
    {
	    MyFun_sql(p,"select *from loading;");
	    MYSQL_RES *r=mysql_store_result(p);  //存储数据集
	    if(r==NULL)
	    {
		    perror("store failed\n");
		    mysql_close(p);
		    return -1;
	    }
	    unsigned int temp=0;
	    temp=mysql_num_fields(r);   //字段数
	    //printf("temp=%lu\n",temp);
	    MYSQL_FIELD *l=mysql_fetch_fields(r);//指向字段的指针,结构体
	    for(int i=0;i<temp;i++)   //遍历字段
	    {
	        printf("%10s",(l+i)->name);
	    }
	    puts("");
	    my_ulonglong num=mysql_num_rows(r);  //记录数
	    for(int i=0;i<num;i++)   //遍历每条数据
	    {
		    MYSQL_ROW ppp=mysql_fetch_row(r);
		    for(int j=0;j<temp;j++)
	    	{
			    printf("%10s",ppp[j]);
		    }
	    }
	    printf("\n");
	    mysql_free_result(r);
	    mysql_close(p);
    }
	return 0;
}



int MyFun_sql2(MYSQL *p,const char *query)  //用户信息
{
	int ret=mysql_query(p,query);
	//printf("ret=%d\n",ret);
	if(ret!=0)
	{
		perror("query sql faield\n");
		mysql_close(p);
		exit(0);
	}
	return 0;
}


int MyFun_SQL2(const  DATA *r)   //   存储用户信息的数据库
{
	MYSQL *p=mysql_init(NULL);
	if(p==NULL)
	{
		perror("mysql init failed\n");
		return -1;
	}
	p=mysql_real_connect(p,"127.0.0.1","root","ldh010724qwer",NULL,0,NULL,0);
	if(p==NULL)   //failed   close
	{
		perror("concent failed\n");
		mysql_close(p);
		return -1;
	}
	char *u="root";
	char *p2="ldh88888";
	MyFun_sql2(p,"create database if not exists store_info;");
	MyFun_sql2(p,"use store_info;");
	MyFun_sql2(p,"create table if not exists user_info(name varchar(10),phone int,carnum varchar(10));");   //创建表的字段
	mysql_set_character_set(p,"utf8");
	char sql_query[256]={'\0'};   //sql_query 指向insert 语句 '%s' =='root' 
	sprintf(sql_query,"insert into user_info(name,phone,carnum) values ('%s','%d','%s');",r->name,r->phone,r->carnum);   //格式化字符串
	if(MyFun_sql(p,sql_query)!=0)   //调用MyFun_sql函数
	{
		perror("query failed\n");
		mysql_close(p);
		return -1;
	}
	//sprintf((char *)p,"insert into user_info(name,phone,carnum) values ('%s','%ld','%s');",r->name,r->phone,r->carnum);   //添加数据
	if(strcmp(user,u)==0&&strcmp(password,p2)==0)   //管理员可以查看数据库中的数据
    {   
	    MyFun_sql2(p,"select *from user_info);");
	    MYSQL_RES *r=mysql_store_result(p);  //存储数据集
	    if(r==NULL)
	    {
		    perror("store failed\n");
	    	mysql_close(p);
		    return -1;
	    }
        unsigned int temp=0;
	    temp=mysql_num_fields(r);   //字段数
	    //printf("temp=%lu\n",temp);
	    MYSQL_FIELD *l=mysql_fetch_fields(r);//指向字段的指针,结构体
	    for(int i=0;i<temp;i++)   //遍历字段
	    {
	        printf("%10s",(l+i)->name);
	    }
	    puts("");
	    my_ulonglong num=mysql_num_rows(r);  //记录数
	    for(int i=0;i<num;i++)   //遍历每条数据
	    {
		    MYSQL_ROW ppp=mysql_fetch_row(r);
		    for(int j=0;j<temp;j++)
	    	{
			    printf("%10s",ppp[j]);
		    }
	    }
	    printf("\n");
	    mysql_free_result(r);
	    mysql_close(p);
    }
	return 0;
}



int MyFun_sql3(MYSQL *p,const char *query)  //车辆信息
{
	int ret=mysql_query(p,query);
	if(ret!=0)
	{
		perror("query sql faield\n");
		mysql_close(p);
		exit(0);
	}
	return 0;
}


int MyFun_SQL3(const   DATA *r)   //   存储车辆信息的数据库
{
	MYSQL *p=mysql_init(NULL);
	if(p==NULL)
	{
		perror("mysql init failed\n");
		return -1;
	}
	p=mysql_real_connect(p,"127.0.0.1","root","ldh010724qwer",NULL,0,NULL,0);
	if(p==NULL)   //failed   close
	{
		perror("concent failed\n");
		mysql_close(p);
		return -1;
	}
	char *u="root";
	char *p2="ldh88888";
	MyFun_sql3(p,"create database if not exists store_info;");
	MyFun_sql3(p,"use store_info;");
	MyFun_sql3(p,"create table if not exists car_info(name varchar(10),phone long,carnum varchar(10),model varchar(10),color varchar(10));");   //创建表的字段
	mysql_set_character_set(p,"utf8");
	char sql_query[256]={'\0'};   //sql_query 指向insert 语句 '%s' =='root' 
	sprintf(sql_query,"insert into car_info(name,phone,carnum,model,color) values ('%s','%d','%s','%s','%s');",r->name, r->phone,r->carnum,r->model,r->color);   //格式化字符串
	if(MyFun_sql(p,sql_query)!=0)   //调用MyFun_sql函数
	{
		perror("query failed\n");
		mysql_close(p);
		return -1;
	}
//	sprintf((char *)p,"insert into car_info(name,phone,carnum,model,color) values ('%s','%ld','%s','%s','%s');",r->name, r->phone,r->carnum,r->model,r->color);   //添加数据
    if(strcmp(user,u)==0&&strcmp(password,p2)==0)   //管理员可以查看数据库中的数据
    {   
	    MyFun_sql3(p,"select *from car_info;");
	    MYSQL_RES *r=mysql_store_result(p);  //存储数据集
	    if(r==NULL)
	    {
		    perror("store failed\n");
	    	mysql_close(p);
		    return -1;
	    }
        unsigned int temp=0;
	    temp=mysql_num_fields(r);   //字段数
	    //printf("temp=%lu\n",temp);
	    MYSQL_FIELD *l=mysql_fetch_fields(r);//指向字段的指针,结构体
	    for(int i=0;i<temp;i++)   //遍历字段
	    {
	        printf("%10s",(l+i)->name);
	    }
	    puts("");
	    my_ulonglong num=mysql_num_rows(r);  //记录数
	    for(int i=0;i<num;i++)   //遍历每条数据
	    {
		    MYSQL_ROW ppp=mysql_fetch_row(r);
		    for(int j=0;j<temp;j++)
	    	{
			    printf("%10s",ppp[j]);
		    }
	    }
	    printf("\n");
	    mysql_free_result(r);
	    mysql_close(p);
    }
	return 1;
}



int MyFun_sql4(MYSQL *p,const char *query)  //费用信息
{
	int ret=mysql_query(p,query);
	if(ret!=0)
	{
		perror("query sql faield\n");
		mysql_close(p);
		exit(0);
	}
	return 0;
}


int MyFun_SQL4(int *moneypay)   //   存储费用信息的数据库  微信
{
	MYSQL *p=mysql_init(NULL);
	if(p==NULL)
	{
		perror("mysql init failed\n");
		return -1;
	}
	p=mysql_real_connect(p,"127.0.0.1","root","ldh010724qwer",NULL,0,NULL,0);
	if(p==NULL)   //failed   close
	{
		perror("concent failed\n");
		mysql_close(p);
		return -1;
	}
	char *u="root";
	char *p2="ldh88888";
	MyFun_sql4(p,"create database if not exists store_info;");
	MyFun_sql4(p,"use store_info;");
	MyFun_sql4(p,"create table if not exists Pay_info(Wechat int,Alipay int ,UnionPay int);");   //创建表的字段
	mysql_set_character_set(p,"utf8");
	char sql_query[256]={'\0'};   //sql_query 指向insert 语句 '%s' =='root' 
	sprintf(sql_query,"insert into Pay_info(Wechat) values ('%d');",*moneypay);   //格式化字符串
	if(MyFun_sql(p,sql_query)!=0)   //调用MyFun_sql函数
	{
		perror("query failed\n");
		mysql_close(p);
		return -1;
	}
	//sprintf((char *)p,"insert into Pay_info(Wechat) values ('%d');",moneypay);   //添加数据
	mysql_close(p);
	return 0;
}



int MyFun_sql5(MYSQL *p,const char *query)  //费用信息
{
	int ret=mysql_query(p,query);
	if(ret!=0)
	{
		perror("query sql faield\n");
		mysql_close(p);
		exit(0);
	}
	return 0;
}


int MyFun_SQL5(int *moneypay)   //   存储费用信息的数据库  支付宝
{
	MYSQL *p=mysql_init(NULL);
	if(p==NULL)
	{
		perror("mysql init failed\n");
		return -1;
	}
	p=mysql_real_connect(p,"127.0.0.1","root","ldh010724qwer",NULL,0,NULL,0);
	if(p==NULL)   //failed   close
	{
		perror("concent failed\n");
		mysql_close(p);
		return -1;
	}
	char *u="root";
	char *p2="ldh88888";
	MyFun_sql5(p,"create database if not exists store_info;");
	MyFun_sql5(p,"use store_info;");
	MyFun_sql5(p,"create table if not exists Pay_info(Wechat int,Alipay int,UnionPay int);");   //创建表的字段
	mysql_set_character_set(p,"utf8");
	char sql_query[256]={'\0'};   //sql_query 指向insert 语句 '%s' =='root' 
	sprintf(sql_query,"insert into Pay_info(Alipay) values ('%d');",*moneypay);   //格式化字符串
	if(MyFun_sql(p,sql_query)!=0)   //调用MyFun_sql函数
	{
		perror("query failed\n");
		mysql_close(p);
		return -1;
	}
	//sprintf((char *)p,"insert into Pay_info(Alipay) values ('%d');",moneypay);   //添加数据
    mysql_close(p);
    return 0;
}


int MyFun_sql6(MYSQL *p,const char *query)  //费用信息
{
	int ret=mysql_query(p,query);
	if(ret!=0)
	{
		perror("query sql faield\n");
		mysql_close(p);
		exit(0);
	}
	return 0;
}


int MyFun_SQL6(int *moneypay)   //   存储费用信息的数据库  云闪付
{
	MYSQL *p=mysql_init(NULL);
	if(p==NULL)
	{
		perror("mysql init failed\n");
		return -1;
	}
	p=mysql_real_connect(p,"127.0.0.1","root","ldh010724qwer",NULL,0,NULL,0);
	if(p==NULL)   //failed   close
	{
		perror("concent failed\n");
		mysql_close(p);
		return -1;
	}
	char *u="root";
	char *p2="ldh88888";
	MyFun_sql6(p,"create database if not exists store_info;");
	MyFun_sql6(p,"use store_info;");
	MyFun_sql6(p,"create table if not exists Pay_info(Wechat int,Alipay int,UnionPay int);");   //创建表的字段
	mysql_set_character_set(p,"utf8");
	char sql_query[256]={'\0'};   //sql_query 指向insert 语句 '%s' =='root' 
	sprintf(sql_query,"insert into Pay_info(UnionPay) values ('%d');",*moneypay);   //格式化字符串
	if(MyFun_sql(p,sql_query)!=0)   //调用MyFun_sql函数
	{
		perror("query failed\n");
		mysql_close(p);
		return -1;
	}
	//sprintf((char *)p,"insert into Pay_info(UnionPay) values ('%d');",moneypay);   //添加数据
    mysql_close(p);
	return 0;
}




