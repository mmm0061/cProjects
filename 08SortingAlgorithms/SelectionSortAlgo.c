#include <stdio.h>
#include "config.h"

void selectionSortAlgo(int *arr)
{
    int currentMin, temp;
    for (int i = 0; i < ARR_LEN; i++) {
        temp = i;
        currentMin = arr[i];
        for (int j = i + 1; j < ARR_LEN; j++) {
            if (currentMin > arr[j]) {
                currentMin = arr[j];
                temp = j;
            }
            if (j == ARR_LEN - 1) {
                arr[temp] = arr[i];
                arr[i] = currentMin;
            }
        }
    }
}
