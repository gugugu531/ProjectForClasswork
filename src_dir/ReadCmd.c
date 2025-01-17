#include <stdio.h>
#include <stdlib.h>
#include "../include/ContactFileSystem.h"

Student* ReadCmd(Student* phead)
{
    int cmd = 0;

    printf("请输入你想执行的操作的对应数字：");

    if (scanf("%d", &cmd))
    {
        fflush(stdin);
        switch (cmd)
        {
        case 1:
            ClearTheSurface();
            phead = Create(phead);
            SaveTheLog(CREATE);
            break;
        case 2:
            ClearTheSurface();
            phead = Delete(phead);
            SaveTheLog(DELETE);
            break;
        case 3:
            ClearTheSurface();
            Modify(phead);
            SaveTheLog(MODIFY);
            break;
        case 4:
            ClearTheSurface();
            FuzzySearch(phead);
            break;
        case 5:
            ClearTheSurface();
            ExportTheData(phead);
            SaveTheLog(EXPORT_THE_DATA);
            break;
        case 6:
            ClearTheSurface();
            SendEmail();
            break;
        case 7:
            ClearTheSurface();
            phead = ImportTheData(phead);
            SaveTheLog(IMPORT_THE_DATA);
            break;
        case 8:
            ClearTheSurface();
            ShowTheData(phead);
            break;
        case 9:
            ClearTheSurface();
            phead = Sort(phead);
            break;
        default:
            printf("请输入正确的指令！请重新输入！\n");
            ReadCmd(phead);
            break;
        }
    }
    else
    {
        printf("输入命令错误！请重新输入！\n");
        fflush(stdin);
        ReadCmd(phead);
    }
    return phead;
}