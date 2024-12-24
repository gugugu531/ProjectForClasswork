#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "../include/ContactFileSystem.h"

void ShowTheData(Student* phead)
{
    Student* current = phead;
    if (current == NULL)
    {
        printf("没有数据，无法显示！\n");
        printf("该子程序即将退出！\n");
        Sleep(3000);
        return;
    }
    for ( ; current != NULL; )
    {
        printf("********************************\n");
        printf("StudentID:%s\n", current->StudentID);
        printf("Name:%s\n", current->Name);
        printf("Gender:%s\n", current->gender);
        printf("School:%s\n", current->school);
        printf("Major:%s\n", current->major);
        printf("Address:%s\n", current->address);
        printf("Phone number:%s\n", current->phoneNumber);
        printf("QQ number:%s\n", current->qqNumber);
        printf("Email address:%s\n", current->emailAddr);
        current = current->pnext;
    }
    printf("********************************\n");
    
    int cmd;
    printf("输入0退出：");
    scanf("%d", &cmd);
}

void ImportTheData(Student* phead)
{

    int cmd;
    printf("请确保原来没有写入数据！\n");
    printf("输入1继续，0退出：");
    L:
    scanf("%d", &cmd);
    switch (cmd)
    {
    case 1:
        fflush(stdin);
        break;
    case 2:
        fflush(stdin);
        return;
        break;
    default:
        printf("请输入正确的指令！");
        fflush(stdin);
        goto L;
        break;
    }

    if (phead != NULL)
    {
        printf("内存中已写入数据！\n");
        printf("此功能即将退出。\n");
        return;
    }
    

    char filepath[50];
    L2:
    printf("请输入文件所在路径：");
    fflush(stdin);
    scanf("%s", filepath);
    FILE *file = fopen(filepath, "r");
    if (!file) 
    {
        printf("打开指定文件失败\n");
        goto L2;
    }


    Student* pnew = NULL, *pold = NULL;
    
    for ( ; ; )
    {
/*
*申请内存（若申请不到则显示错误信息并退出程序）
*/
        pnew = (Student*)malloc(sizeof(Student));
        if (pnew == NULL)
        {
            printf("堆区内存已用完！即将退出程序！");
            Sleep(3000);
            exit(0);
        }

        if (phead == NULL)//第一次插入数据时若分配到内存空间则将链表头设置为pnew
        {
            phead = pnew;
        }

        if (pold != NULL)//如果已创建了一个节点就使老节点中指针指向下一个节点
            pold->pnext = pnew;

//待办：检查数据合理性
//待办：读入数据并写入链表模块
        char line[100];
        fscanf(file, "%s", line);

        char* token;
        token = strtok(line, ",");
        strcpy(pnew->StudentID, token);

        token = strtok(NULL, ",");
        strcpy(pnew->Name, token);

        token = strtok(NULL, ",");
        strcpy(pnew->gender, token);

        token = strtok(NULL, ",");
        strcpy(pnew->school, token);

        token = strtok(NULL, ",");
        strcpy(pnew->major, token);

        token = strtok(NULL, ",");
        strcpy(pnew->address, token);

        token = strtok(NULL, ",");
        strcpy(pnew->phoneNumber, token);

        token = strtok(NULL, ",");
        strcpy(pnew->qqNumber, token);

        token = strtok(NULL, ",");
        strcpy(pnew->emailAddr, token);

/*
*此部分用来更新节点状态，保存现在已创建节点地址，
*并将节点内指向下一节点的指针设为NULL，为接下来创建新节点做准备
*/
        pold = pnew;
        pold->pnext = NULL;
    }
    fclose(file);
    printf("已成功导入！");
}

void ExportTheData(Student* phead)
{
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
        fprintf(file, "=\"%s\",%s,%s,%s,%s,%s,=\"%s\",=\"%s\",%s\n",//此处采用=\"%s"的写法是防止excel打开csv时自动将长整数用科学计数法表示
                current->StudentID, current->Name, current->gender, current->school, current->major,
                current->address, current->phoneNumber, current->qqNumber, current->emailAddr);
        fflush(stdout);
        current = current->pnext;
    }
    fclose(file);
    printf("数据已导出至%s", FILE_NAME);
    Sleep(3000);
}

void SaveTheLog(const char* str)
{
    time_t current;
    time(&current);
    FILE *logfile = fopen(LOGFILE_NAME, "a+");
    if (!logfile) 
    {
        printf("打开或创建目录文件失败\n");
        Sleep(3000);
        return;
    }
    fprintf(logfile, "%s", ctime(&current));
    fprintf(logfile, str);

    fclose(logfile);
}