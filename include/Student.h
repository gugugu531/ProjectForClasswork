#ifndef STUDENT
#define STUDENT

typedef struct student
{
    int StudentID;
    char Name[20];
    char gender;
    char school[20];
    char major[20];
    char address[20];
    int phoneNumber;
    int qqNumber;
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