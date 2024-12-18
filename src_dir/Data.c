#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../include/Untitled.h"

void ShowTheData(void)
{
    printf("ShowTheData: no error\n");
    system("pause");
}

void ImportTheData(void)
{
    printf("ImportTheData: no error\n");
    system("pause");
}

void ExportTheData(Student* phead)
{
/* 
    if (phead == NULL)
    {
        printf("没有数据，无法导出！\n");
        printf("3秒后退出！\n");
        Sleep(3000);
        return 0;
    }
    FILE* file = fopen(FILE_NAME, "w");
    for ( ; ; )
    {
        fprintf(file, "%s,%d,%c,%s,%s,%s,%d,%d,%s\n", phead->Name, phead->StudentID, phead->gender, phead->school, phead->major,
        phead->address, phead->phoneNumber, phead->qqNumber, phead->emailAddr);
        if (phead->pnext == NULL)
            break;
        phead = phead->pnext; 
    }
    fclose(file);
    printf("数据已导出为csv格式！");
    Sleep(3000);
    return 0; */
    if (phead == NULL)
    {
        printf("没有数据，无法导出！\n");
        printf("3秒后退出！\n");
        Sleep(3000);
        return;
    }

    FILE *file = fopen(FILE_NAME, "w");
    if (!file) 
    {
        printf("打开或创建指定文件失败\n");
        Sleep(3000);
        return;
    }

    Student *current = phead;

    while (current) {
        fprintf(file, "%d,%s,%c,%s,%s,%s,%d,%d,%s\n",
                current->StudentID, current->Name, current->gender, current->school, current->major,
                current->address, current->phoneNumber, current->qqNumber, current->emailAddr);
        fflush(stdout);
        current = current->pnext;
    }
    fclose(file);
    printf("数据已导出至%s", FILE_NAME);
    Sleep(3000);
}

//忘记这个要干嘛了。。。
void SaveTheData(void)
{
    printf("SaveTheData: no error\n");
    system("pause");
}

void SaveTheLog(const char* str)
{
/*     printf("SaveTheData: no error\n");
    system("pause"); */
    time_t current;
    time(&current);
    FILE *logfile = fopen(LOGFILE_NAME, "a+");
    if (!logfile) 
    {
        printf("打开或创建目录文件失败\n");
        Sleep(3000);
        return;
    }
    fprintf(logfile, "%s\n", ctime(&current));
    fprintf(logfile, str);

    fclose(logfile);
}