/*
This is a basic implementation for Quick Sort Algorithm. There are a lot of aspects that can be optimize in the code, such as the method of choosing the pivot. However, the mean reason for writing this code is joyment, so I didn't work hard on optimazation.

This code was shadowing for the video: https://www.youtube.com/watch?v=0jDiBM68NGU&ab_channel=PortfolioCourses
Choosing the pivat can be done in different ways, such as the one the video uses (at the end of the video); however, as far as I know is that, the most efficient way is to pick the mediam value of the beginning, the middle, and the last element in the array.
*/

#include "config.h"

void quickSortAlgo(int arr[]);
void quickSortRecursion(int arr[], int first, int last);
int partitioning(int arr[], int first, int last);
void swap(int *a, int *b);

void quickSortAlgo(int arr[]){//it is just a wrapper!
    quickSortRecursion(arr, 0, ARR_LEN-1);
}
void quickSortRecursion(int arr[], int first, int last){
    if(first < last){
        int pivetIndx = partitioning(arr, first, last);
        quickSortRecursion(arr, first, pivetIndx - 1);
        quickSortRecursion(arr, pivetIndx + 1, last);
        //printf("Line 38");
    }
}

int partitioning (int arr[], int first, int last){
    
    int pivatValue = arr[last];
    int i = first;
    
    for(int j = first; j < last; j++){
        if(arr[j] <= pivatValue){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[last]);
    return i;
}

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
