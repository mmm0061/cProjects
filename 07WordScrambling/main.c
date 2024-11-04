/*
 Purpose: I built this project for fun only. In this code, there are many aspects can be improved to make better, but as I said, I built it just for fun ^_*
 Functionality: It takes a predefined text (e.g. "Mesfer Alqarni  ") then scrambles it. The code works as follow:
                    1- It replaces capitale letters with small, so that it can easily move them around.
                    2- It removes whitespaces such as ' ', '\t', and '\n' from the text.
                    3- It scrambles the text. Note, the scrambled text might be different everytime you run the code; this is how it was designed!
 */

#include <stdio.h>
#include "scrambling.h"

int main(void) {
    
    char string[] = "Mesfer Alqarni\t";
    printf("The original Text: %s \n", string);
    scramble(string);
    
    return 0;
}
