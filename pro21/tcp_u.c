#include "tcp.h"
#include <stdio.h>
#include <string.h>


int  MyFun_Client_Carnum(char *p,char *q)   //客户端   车辆
{
	int cfd=socket(AF_INET,SOCK_STREAM,0);  //create
	if(cfd<0)
	{
		perror("cfd  create failed\n");
		return -1;
	}
	struct sockaddr_in addr;  //ipv4
	addr.sin_family=AF_INET;   //地址族
	addr.sin_port=atoi(q);   //port
	int ret=inet_pton(AF_INET,p,(struct sockaddr_in *)&(addr.sin_addr));  //点分式转化为二进制字符串
	if(ret<=0)
	{
		perror("pton failed\n");
		return -1;
	}
	ret=connect(cfd,(struct sockaddr *)&addr,sizeof(addr));
	if(ret <0)
	{
		perror("connect  failed\n");
		return -1;
	}
	char buff[100];
    memset(buff,0,sizeof(buff));
	printf("please input data send to server\n");
    scanf("%s",buff);
    if(strcmp(buff,"入库")==0||strcmp(buff,"出库")==0)   //出入库才向服务端发送数据
    {
		send(cfd,buff,sizeof(buff),0);
    }
    else
    {
        perror("you  input errror\n");
        return -1;
    }
	close(cfd);
    return 0;
}


int  MyFun_Client_Carport(char *p,char *q)   //客户端   车位
{
	int cfd=socket(AF_INET,SOCK_STREAM,0);  //create
	if(cfd<0)
	{
		perror("cfd  create failed\n");
		return -1;
	}
	struct sockaddr_in addr;  //ipv4
	addr.sin_family=AF_INET;   //地址族
	addr.sin_port=atoi(q);   //port
	int ret=inet_pton(AF_INET,p,(struct sockaddr_in *)&(addr.sin_addr));  //点分式转化为二进制字符串
	if(ret<=0)
	{
		perror("pton failed\n");
		return -1;
	}
	ret=connect(cfd,(struct sockaddr *)&addr,sizeof(addr));
	if(ret <0)
	{
		perror("connect  failed\n");
		return -1;
	}
	char buff[100];
    memset(buff,0,sizeof(buff));
	printf("please input data send to server\n");
    scanf("%s",buff);
    if(strcmp(buff,"入库")==0||strcmp(buff,"出库")==0)   //出入库才向服务端发送数据
    {
		send(cfd,buff,sizeof(buff),0);
    }
    else
    {
        perror("you  input errror\n");
        return -1;
    }
	close(cfd);
    return 0;
}

