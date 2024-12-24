#ifndef DATA
#define DATA

#include "ContactFileSystem.h"
#include "Student.h"

/*
*保存程序运行日志文件
*日志文件为txt格式，包含信息有：
*操作（运行程序，调用哪些功能，退出程序）及各操作对应时间
*/
void SaveTheLog(const char* str);

/*
*导入csv文件到内存中
*/
void ImportTheData(Student* phead);

/*
*在内存中有数据的情况下，将数据保存为csv格式
*传入参数为链表头，若为空指针则退出（不保存数据）
*/
void ExportTheData(Student* phead);

/*
*展示内存中已有数据，传入链表头
*/
void ShowTheData(Student* phead);

#endif