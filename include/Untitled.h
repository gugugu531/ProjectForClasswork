#ifndef UNTITLED
#define UNTITLED

typedef struct student
{
    int StudentID;
    char Name[20];
    int gender;
    int school;
    int major;
    char address[20];
    int phoneNumber;
    int qqNumber;
    char emailAddr[35];
    struct student * next;
}Student;

/*
*
*用来展示命令菜单
*
*/
void ShowTheMenu(void);

/*
*
*刷新控制台应用界面
*
*/
void ClearTheSurface(void);

void ShowTheData(void);

void Insert(void);

void Delete(void);

void Modify(void);

void FuzzySearch(void);

void Sort(void);

void SaveTheLog(void);

void SaveTheData(void);

void ImportTheData(void);

void ExportTheData(void);

void SendEmail(void);

void ReadCmd(void);

#endif