#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int* uniqueRandNum(int length, int *randNumArr)
{
    int temp;
    bool isRandom;
    
    srand(time(NULL));
    
    for (int i = 0; i < length; i++) {
        do {
            isRandom = true;
            temp = (rand()%length)+1;
            for (int j = 0; j < i; j++) {
                if (randNumArr[j] == temp){
                    isRandom = false;
                    break;
                }
            }
            if (isRandom == true)
                randNumArr[i] = temp;
        } while (isRandom == false);
    }
    
    for (int i = 0; i < length; i++) randNumArr[i] -= 1;
    return randNumArr;
}
