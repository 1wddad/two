#ifndef __TCP__H
#define __TCP__H

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>




int 	MyFun_Sever_Carnum(char *p,char *q);  //服务端   车辆
int     MyFun_Client_Carnum(char *p,char *q);   //客户端  车辆
int	    MyFun_Sever_Carport(char *p,char *q); //服务端   车位
int    MyFun_Client_Carport(char *p,char *q);   //客户端   车位

#endif