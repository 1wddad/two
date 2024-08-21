#include "tcp.h"
#include <stdio.h>
#include <string.h>
#define M 1000   //1000个车位


int	    MyFun_Sever_Carnum(char *p,char *q)  //服务端   车辆
{
	int sfd=socket(AF_INET,SOCK_STREAM,0);  //create
	if(sfd<0)
	{
		perror("sfd  create failed\n");
		return -1;
	}
	struct sockaddr_in addr;  //ipv4
	addr.sin_family=AF_INET;   //地址族
	addr.sin_port=atoi(q);   //port
	int ret=inet_pton(AF_INET,p,(struct addr *)&(addr.sin_addr));  //点分式字符串转化为二进制字符串
	if(ret<=0)
	{
		perror("pton  failed\n");
		return -1;
	}
	ret=bind(sfd,(struct sockaddr *)&addr,sizeof(addr));   //绑定ip/端口
	if(ret<0)
	{
		perror("bind failed\n");
		return -1;
	}
	ret=listen(sfd,4);
	if(ret<0)
	{
		perror("listen  failed\n");
		return -1;
	}
	struct sockaddr_in cldaddr;   //new val
	cldaddr.sin_family=AF_INET;
	cldaddr.sin_port=atoi(q);
	int cfd=accept(sfd,(struct sockaddr*)&cldaddr,(socklen_t *)&cldaddr.sin_addr);   //new fd
	if(cfd<0)
	{
		perror("accept  failed\n");
		return -1;
	}
    
    char buff[100];
	memset(buff,0,sizeof(buff));
	recv(cfd,buff,sizeof(buff),0);
    printf("recv msg :%s\n",buff);
    int arr[M];   //存放车辆入库、出库的信息,数组里面的元素 1 不可以入库  0  可入库    下标为入库的位置
    memset(arr,0,sizeof(arr));
    int num=0;   //数组的下标
    if(strcmp(buff,"入库")==0)
    {
        if(num<M)
        {
            printf("尊敬的用户!你可以入库:\n");
            //num++;
            arr[num]=1;   //入库后，当前数组元素值为1,代表当前车位不能停放车辆
            num++;
            printf("当前车在车库里\n");   //车当前状态
        }
        else    if(num>=M)   //车位已满
        {
            printf("车位已满!非常抱歉，我们会持续改进并优化\n");
        }
        /*
        for(int i=0;i<M;i++)   //车位的数量有限，再次入库的话，直接找元素为0的位置
        {
            if(arr[i]==0)     //出库和入库一直动态变化
            {
                printf("尊敬的用户!你可以入库:");
                arr[i]=1;   //入库后，当前数组元素值为1,代表当前车位不能停放车辆
                printf("当前车在车库里\n");   //车当前状态
                break;
            }
        }
        */
    }
    if(strcmp(buff,"出库")==0)
    {
        puts("please input your Carport");
        int carport=0;   //车位号
        scanf("%d",&carport);
        if(carport>0&&carport<=M)   //1-1000之间
        {
            printf("尊敬的用户!出库成功\n");
            arr[carport-1]=0;  //出库成功，元素置为0,方便后面用户再次使用
            puts("尊敬的车主,一路平安! 欢迎再次使用,谢谢!");
            printf("当前车已离库\n");   //车当前状态
        }
        else
        {
            puts("you  input error!please again input");
        }    
    }
	close(sfd);
	close(cfd);
    return 0;
}






int	    MyFun_Sever_Carport(char *p,char *q)  //服务端   车位
{
	int sfd=socket(AF_INET,SOCK_STREAM,0);  //create
	if(sfd<0)
	{
		perror("sfd  create failed\n");
		return -1;
	}
	struct sockaddr_in addr;  //ipv4
	addr.sin_family=AF_INET;   //地址族
	addr.sin_port=atoi(q);   //port
	int ret=inet_pton(AF_INET,p,(struct addr *)&(addr.sin_addr));  //点分式字符串转化为二进制字符串
	if(ret<=0)
	{
		perror("pton  failed\n");
		return -1;
	}
	ret=bind(sfd,(struct sockaddr *)&addr,sizeof(addr));   //绑定ip/端口
	if(ret<0)
	{
		perror("bind failed\n");
		return -1;
	}
	ret=listen(sfd,4);
	if(ret<0)
	{
		perror("listen  failed\n");
		return -1;
	}
	struct sockaddr_in cldaddr;   //new val
	cldaddr.sin_family=AF_INET;
	cldaddr.sin_port=atoi(q);
	int cfd=accept(sfd,(struct sockaddr*)&cldaddr,(socklen_t *)&cldaddr.sin_addr);   //new fd
	if(cfd<0)
	{
		perror("accept  failed\n");
		return -1;
	}
    char buff[100];
	memset(buff,0,sizeof(buff));
	recv(cfd,buff,sizeof(buff),0);
    printf("recv msg :%s\n",buff);
    int arr[M];   //存放车辆入库、出库的信息,数组里面的元素 1 不可以入库  0  可入库    下标为入库的位置
    memset(arr,0,sizeof(arr));
    int num=0;   //数组的下标
    if(strcmp(buff,"入库")==0)
    {
        if(num<M)
        {
            printf("尊敬的用户!你可以入库:\n");
            //num++;
            arr[num]=1;   //入库后，当前数组元素值为1,代表当前车位不能停放车辆
            printf("请把车停在第%d个车位处,谢谢!\n",num+1);
            num++;
            printf("当前车在车库里\n");   //车当前状态
            puts("车位大小为---5(m)*4(m)");
            puts("1-2h:---每小时2元");
            puts("3-5h:---超过2h的部分每小时:0.25元");
            puts("5-10h:---超过5h的部分每小时:0.1元");
        }
        else    if(num>=M)   //车位已满
        {
            printf("车位已满!非常抱歉，我们会持续改进并优化\n");
        }
        /*
        for(int i=0;i<M;i++)   //车位的数量有限，再次入库的话，直接找元素为0的位置
        {
            if(arr[i]==0)     //出库和入库一直动态变化
            {
                printf("尊敬的用户!你可以入库:");
                arr[i]=1;   //入库后，当前数组元素值为1,代表当前车位不能停放车辆
                printf("请把车停在第%d个车位处,谢谢!\n",i+1);
                printf("当前车在车库里\n");   //车当前状态
                puts("车位大小为---5(m)*4(m)");
                puts("每小时---2元");
                break;
            }
        }
        */
    }
    if(strcmp(buff,"出库")==0)
    {
        puts("please input your Carport");
        int carport=0;   //车位号
        scanf("%d",&carport);
        if(carport>0&&carport<=1000)   //1-1000之间
        {
            printf("尊敬的用户!出库成功\n");
            arr[carport-1]=0;  //出库成功，元素置为0,方便后面用户再次使用
            puts("尊敬的车主,一路平安! 欢迎再次使用,谢谢!");
            printf("当前车已离库\n");   //车当前状态
        }
        else
        {
            puts("you  input error!please again input");
        }    
    }
	close(sfd);
	close(cfd);
    return 0;
}