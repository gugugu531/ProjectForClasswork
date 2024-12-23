#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "../include/Untitled.h"

//待办：已有数据重新添加这种情况未解决
Student* Create(Student* phead)
{
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

/*
*此部分用来读入手动输入的数据
*/
        printf("请输入学生姓名：");
        scanf("%s", &pnew->Name);
        fflush(stdin);
        printf("请输入学生学号:");
        scanf("%s", &pnew->StudentID);
        fflush(stdin);
        printf("请输入学生性别：(M为男，W为女)");
        scanf("%s", &pnew->gender);
        fflush(stdin);
        printf("请输入学生所属学院：");
        scanf("%s", &pnew->school);
        fflush(stdin);
        printf("请输入学生专业 ：");
        scanf("%s", &pnew->major);
        fflush(stdin);
        printf("请输入学生居住地址：");
        scanf("%s", &pnew->address);
        fflush(stdin);
        printf("请输入学生电话号码：");
        scanf("%s", &pnew->phoneNumber);
        fflush(stdin);
        printf("请输入学生QQ号：");
        scanf("%s", &pnew->qqNumber);
        fflush(stdin);
        printf("请输入学生电子邮箱地址：");
        scanf("%s", &pnew->emailAddr);
        fflush(stdin);

/*
*此部分用来更新节点状态，保存现在已创建节点地址，
*并将节点内指向下一节点的指针设为NULL，为接下来创建新节点做准备
*/
        pold = pnew;
        pold->pnext = NULL;

/*
*读取指令，确认是否要继续创建节点
*如果是，继续执行for循环语句创建节点
*否则返回一个值（）并退出函数
*输入错误指令显示报错语句并跳转到L处重新执行该模块
*/
        L:
        int cmd;
        printf("是否继续插入？（需要继续输入1，否则输入0）");
        scanf("%d", &cmd);
        switch (cmd)
        {
        case 0:
            //需要添加退出函数的语句
            return phead;
            break;
        case 1:
            break;
        default:
            printf("请输入正确的指令！");
            fflush(stdin);
            goto L;
            break;

        }
    }
}
Student* Delete(Student* phead)
{
/*     printf("Delete: no error\n");
    system("pause");*/
    char id[20];
    printf("请输入要删除学生学号：");
    scanf("%s", id);
    
    Student* current = phead;
    Student* previous = NULL;

    if (current == NULL)
    {
        printf("数据为空，无法执行操作，即将退出");
        Sleep(3000);
        return current;
    }
    for ( ; current != NULL; )
    {
        if (strcmp(current->StudentID, id) == 0)
        {
            goto L1;
        }
        previous = current;
        current = current->pnext;
    }
    goto L2;

    L1:
    {
        printf("要删除学生信息为：\n");
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
        printf("********************************\n");
        printf("确认删除？（输入0退出，输入1继续）\n");
        
        int cmd;
        scanf("%d", &cmd);

        L11:
        switch (cmd)
        {
        case 0:
            return phead;
            break;
        case 1:
            if (previous == NULL)
            {
                phead = current->pnext;
                free(current);
                return phead;
            }
            previous->pnext = current->pnext;
            free(current);
            return phead;
            break; 
        default:
            printf("请输入正确的指令！");
            goto L11;
            break;
        }
    }

    L2:
    {
        printf("未能找到指定学生！\n");
        printf("程序即将退出！\n");
        Sleep(3000);
        return phead;
    }
}
void Modify(Student* phead)
{
    char id[20];
    printf("请输入要删除学生学号：");
    scanf("%s", id);
    
    Student* current = phead;

    if (current == NULL)
    {
        printf("数据为空，无法执行操作，即将退出");
        Sleep(3000);
        return;
    }
    for ( ; current != NULL; )
    {
        if (strcmp(current->StudentID, id) == 0)
        {
            goto L1;
        }
        current = current->pnext;
    }
    goto L2;

    L1:
    {
        printf("要修改学生信息为：\n");
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
        printf("********************************\n");
        printf("确认修改？（输入0退出，输入1继续）\n");
        
        int cmd;
        scanf("%d", &cmd);

        L11:
        switch (cmd)
        {
        case 0:
            return;
            break;
        case 1:
            printf("请输入学生姓名：");
            scanf("%s", &current->Name);
            fflush(stdin);
            printf("请输入学生学号:");
            scanf("%s", &current->StudentID);
            fflush(stdin);
            printf("请输入学生性别：(M为男，W为女)");
            scanf("%s", &current->gender);
            fflush(stdin);
            printf("请输入学生所属学院：");
            scanf("%s", &current->school);
            fflush(stdin);
            printf("请输入学生专业 ：");
            scanf("%s", &current->major);
            fflush(stdin);
            printf("请输入学生居住地址：");
            scanf("%s", &current->address);
            fflush(stdin);
            printf("请输入学生电话号码：");
            scanf("%s", &current->phoneNumber);
            fflush(stdin);
            printf("请输入学生QQ号：");
            scanf("%s", &current->qqNumber);
            fflush(stdin);
            printf("请输入学生电子邮箱地址：");
            scanf("%s", &current->emailAddr);
            fflush(stdin);
            return;
            break; 
        default:
            printf("请输入正确的指令！");
            goto L11;
            break;
        }
    }

    L2:
    {
        printf("未能找到指定学生！\n");
        printf("程序即将退出！\n");
        Sleep(3000);
        return;
    }
}

//sort部分未完成

Student* Sort(Student* phead)
{
/*     printf("Sort: no error\n");
    system("pause"); */
    printf("请选择排序方式：（1.学号排序；2.姓名排序）");

    int cmd;
    scanf("%d", &cmd);
    switch (cmd)
    {
    case 1:
        phead = IDSort(phead);
        break;
    case 2:
        phead = NameSort(phead);
        break;
    default:
        break;
    }
}

Student* IDSort(Student* phead)
{
    Student* min;
    for (Student* current1 = phead; current1 != NULL; current1 = current1->pnext)
    {
        min = current1;
        for (Student* current2 = current1->pnext; current2 != NULL; current2 = current2->pnext)
        {
            if (strcmp(current2->StudentID, min->StudentID) < 0)
            {
                min = current2;
            }
        }

        if (min != current1)
        {
            Student* temp;
            temp = current1;
            current1 = min;
            min = temp;
        }
    }
    return min;
}

Student* NameSort(Student* phead)
{
    Student* min;
    for (Student* current1 = phead; current1 != NULL; current1 = current1->pnext)
    {
        min = current1;
        for (Student* current2 = current1->pnext; current2 != NULL; current2 = current2->pnext)
        {
            if (strcmp(current2->Name, min->Name) < 0)
            {
                min = current2;
            }
        }

        if (min != current1)
        {
            Student* temp;
            temp = current1;
            current1 = min;
            min = temp;
        }
    }
    return min;
}


void FuzzySearch(void)
{
    printf("FuzzySearch: no error\n");
    system("pause");
}