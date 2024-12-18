#include <stdio.h>
#include <stdlib.h>
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
        scanf("%d", &pnew->StudentID);
        fflush(stdin);
        printf("请输入学生性别：(M为男，W为女)");
        scanf("%c", &pnew->gender);
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
        scanf("%d", &pnew->phoneNumber);
        fflush(stdin);
        printf("请输入学生QQ号：");
        scanf("%d", &pnew->qqNumber);
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
void Delete(void)
{
    printf("Delete: no error\n");
    system("pause");
}
void Modify(void)
{
    printf("Modify: no error\n");
    system("pause");
}

void Sort(void)
{
    printf("Sort: no error\n");
    system("pause");
}

void FuzzySearch(void)
{
    printf("FuzzySearch: no error\n");
    system("pause");
}