#ifndef UNTITLED
#define UNTITLED

typedef struct STUDENT
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

}Student;


void ShowTheMenu(void);
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