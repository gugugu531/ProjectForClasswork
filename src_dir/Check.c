#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "../include/ContactFileSystem.h"

bool is_valid_email(const char *email) 
{
    const char *at = strchr(email, '@');
    const char *dot = strrchr(email, '.');
    return at && dot && at < dot && strlen(email) < 50;
}

bool is_valid_phone(const char *phone) 
{
    if (strlen(phone) > 15) return false;
    for (int i = 0; phone[i] != '\0'; i++) {
        if (!isdigit(phone[i])) return false;
    }
    return true;
}

bool is_unique_id(const char* id, Student* phead) 
{
    Student *current = phead;
    while (current) 
    {
        if (current->StudentID == id) 
            return false;
        current = current->pnext;
    }
    return true;
}

bool is_valid_name(const char *name) 
{
    if (strlen(name) >= 50) return false;
    for (int i = 0; name[i] != '\0'; i++) 
    {
        if (!isalpha(name[i]) && name[i] != ' ') 
            return false;
    }
    return true;
}