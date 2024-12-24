#ifndef STUDENT
#define STUDENT

typedef struct student
{
    char StudentID[20];
    char Name[20];
    char gender[2];
    char school[20];
    char major[20];
    char address[20];
    char phoneNumber[20];
    char qqNumber[20];
    char emailAddr[35];
    struct student * pnext;
}Student;

/*
*传入链表起始节点对应地址，返回链表头
*/
Student* Create(Student* phead);

/*
*传入链表起始节点对应地址，返回链表头
*/
Student* Delete(Student* phead);

/*
*传入链表起始节点对应地址，无返回值
*/
void Modify(Student* phead);

/*
*模糊搜索
*/
void FuzzySearch(void);

/*
*传入链表头，传出链表头，由IDSort和NameSort两部分组成
*/
Student* Sort(Student* phead);

/*
*传入链表头，传出按学号排序后的链表头
*/
Student* IDSort(Student* phead);

/*
*传入链表头，传出姓名排序后的链表头
*/
Student* NameSort(Student* phead);

void SendEmail(void);

#endif