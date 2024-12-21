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
*传入链表起始地址对应地址，返回链表头
*/
Student* Create(Student* phead);

void Delete(void);

void Modify(void);

void FuzzySearch(void);

void Sort(void);

void SendEmail(void);

#endif