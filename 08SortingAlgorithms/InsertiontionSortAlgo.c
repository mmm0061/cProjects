#include <stdio.h>
#include "config.h"


void insertionSortAlgo(int *arr)
{
    int temp, j;
    for (int i = 0; i < ARR_LEN; i++) {
        j = i + 1;
        if(arr[i] > arr[j]) {
            do {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                if (i > 0) {
                    i--;
                    j--;
                }
            } while (i > 0 || arr[i] > arr[j]);
        }
    }
}
