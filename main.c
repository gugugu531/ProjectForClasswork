#include <stdio.h>
#include <Windows.h>
#include "..\include\Untitled.h"

int main(void)
{
    SetConsoleCP(CP_UTF8);  //配置控制台应用输入为UTF-8编码
    SetConsoleOutputCP(CP_UTF8);    //配置控制台应用输出为UTF-8编码

    for ( ; ; ) //循环读取命令并执行指定命令
    {
        ShowTheMenu();  //显示菜单
        ReadCmd();  //读取命令并执行
        ClearTheSurface();  //刷新程序界面
    }

    return 0;
}