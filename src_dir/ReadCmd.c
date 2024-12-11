#include <stdio.h>
#include "../include/Untitled.h"

void ReadCmd(void)
{
    int cmd;
    if (scanf("%d", cmd))
        ;
    else
        printf("输入命令错误！请重新输入！\n");

}