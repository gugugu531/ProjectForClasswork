#include <stdio.h>
#include <stdlib.h>
#include "../include/Untitled.h"

void ReadCmd(void)
{
    int cmd = 0;

    printf("请输入你想执行的操作的对应数字：");

    if (scanf("%d", &cmd))
    {
        switch (cmd)
        {
        case 1:
            ClearTheSurface();
            Insert();
            break;
        case 2:
            ClearTheSurface();
            Delete();
            break;
        case 3:
            ClearTheSurface();
            Modify();
            break;
        case 4:
            ClearTheSurface();
            FuzzySearch();
            break;
        case 5:
            ClearTheSurface();
            ImportTheData();
            break;
        case 6:
            ClearTheSurface();
            ExportTheData();
            break;
        default:
            printf("请输入正确的指令！请重新输入！\n");
            ReadCmd();
            break;
        }
    }
    else
    {
        printf("输入命令错误！请重新输入！\n");
        fflush(stdin);
        ReadCmd();
    }
}