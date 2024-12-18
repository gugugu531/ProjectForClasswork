#include <stdio.h>
#include <Windows.h>
#include "..\include\Untitled.h"

void func_exit(void);//程序退出时执行此程序，用于保存日志文件

int main(void)
{
    SetConsoleCP(CP_UTF8);  //配置控制台应用输入为UTF-8编码
    SetConsoleOutputCP(CP_UTF8);    //配置控制台应用输出为UTF-8编码

    atexit(func_exit);

    SaveTheLog(BEGIN);

    Student* phead = NULL;//此处是声明链表的开始节点对应地址

    for ( ; ; ) //循环读取命令并执行指定命令
    {
        ShowTheMenu();  //显示菜单
        phead = ReadCmd(phead);  //读取命令并执行
        ClearTheSurface();  //刷新程序界面
    }

    return 0;
}

void func_exit(void)
{
    ClearTheSurface();
    printf("保存数据中，即将退出程序");
    SaveTheLog(EXIT);
}