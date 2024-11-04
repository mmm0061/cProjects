#include <stdlib.h>
#include <string.h>

int trim(char *string)
{
    int j = 0;
    int length = strlen(string);
    for (int i = 0; i < length ; i++) {//you could use isspace() function in order to check whitespaces
        if (string[i] != ' ' && string[i] != '\n' && string[i] != '\t' ) {
            string[j++] = string[i];
        }
    }
    string[j] = '\0'; // Null-terminate the modified string
    return strlen(string);
}


