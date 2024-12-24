#ifndef CMD
#define CMD

#define BEGIN "ran this program\n"
#define CREATE "added a series of data\n"
#define EXPORT_THE_DATA "export the data\n"
#define EXIT "exit\n"
#define IMPORT_THE_DATA "import the data\n"
#define MODIFY "modify one of the students' information\n"
#define DELETE "delete one of the students' information\n"

#include "ContactFileSystem.h"

/*
*传入数据所在链表头，传出链表头
*/
Student* ReadCmd(Student* phead);

#endif