#include <stdio.h>
#include "config.h"

void bubbleSortAlgo(int *arr)
{
    int temp, k;
    for (int i = 0; i < ARR_LEN; i++)
        for (int j = 0; j < ARR_LEN; j++) {
            k = j+1;
            if (arr[j] > arr[k]) {
                temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
            }
        }
}
