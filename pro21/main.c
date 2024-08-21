#include "menu.h"
#include "fun.h"
#include "sql.h"
#include "tcp.h"
#include <stdio.h>


int   main(int argc,char **argv)
{
    Welcome();
    while(1)
    {
        if((Show_Menu(argv[1],argv[2],argv[3],argv[4]))==0)         //user   password   sever :IP+port   client:  IP+port
        {
            break;
        }
    }
    puts("******************************");
    puts("****                      ****");
    puts("****  感谢您的使用谢谢!   ****");
    puts("****                      ****");
    puts("******************************");
    return 0;
}
