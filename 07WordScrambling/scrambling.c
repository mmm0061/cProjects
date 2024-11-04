#include "scrambling.h"
#include <stdlib.h>
#include <ctype.h>//to set the charactors to lower case, so that we can move them around
#include <string.h>
#include <stdio.h>
#include "trim.h"
#include "RandIndexGen.h"


void scramble(char *string)
{
    int length = strlen(string);
    
    //To convert all letters to lowercase letters
    for (int i = 0; i < length; i++) {
        string[i] = tolower(string[i]);
    }
    
    //In case the string contains only one letter:
    if (length == 1)
        return;//we use return without 0, because the function is of type "void"
    
    //In case the string contains only two letters, we will do the normal swap:
    if (length == 2) {
        char temp = string[0];
        string[0] = string[1];
        string[1] = temp;
        return;
    }
    
    //In case the string has three letters or more:
    //we need to keep a copy of the original string, so that we can compare the scrambled string to the non-scramble one; if it wasn't scrambled by more than 60%, the function should rescramble again! This step is to make sure that the string is well-scrambled. Note: the percentage (60%) is a varaible
    char originalString[length+1];
    strcpy(originalString, string);
    int newlength = trim(string);
    printf("The text without whitespaces & capital letters: %s \n", string);
    char newString[newlength];
    int randNumArr[newlength];
    int* randArr = uniqueRandNum(newlength, randNumArr);
    
    for (int i = 0; i < newlength; i++) {
        newString[randArr[i]] = string[i];
    }
    printf("The text after scrambling: %s \n", newString);
}
