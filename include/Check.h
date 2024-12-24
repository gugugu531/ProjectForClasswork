#ifndef CHECK
#define CHECK

#include "ContactFileSystem.h"
#include <stdbool.h>

bool is_unique_id(const char* id, Student* phead);

bool is_valid_name(const char* name);

bool is_valid_gender(const char* gender);

bool is_valid_phoneNumber(const char* phoneNumber);

bool is_valid_email(const char* emailAddress);

#endif