#include <time.h>
#include <stdlib.h>
#include "config.h"
//#include "RandNumGen.h"


#define MAX_VALUE 20


void randNumGen(int *arr)
{
    srand(time(NULL));
    for (int i = 0; i < ARR_LEN; i++)
        arr[i] = (rand() % MAX_VALUE);
}
