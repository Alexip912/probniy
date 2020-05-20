#include <ctype.h>
#include <string.h>

int is_valid_number(char* number)
{
    for (int i = 0; i < strlen(number); ++i) {
        if (!isdigit(number[i])) {
            return -1;
        }
    }
    if (strcmp(number, "") == 0) {
        return -1;
    }
    return 1;
}