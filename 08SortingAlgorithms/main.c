/*
 - This is an basic implementation (not optomized) for some sorting algorithms, because I just built this project for fun. It contains a set of some famous sorting algorithms that can be used to sort an array of random numbers, such as:
        1- Bubble Sort Algorithm
        2- Selection Sort Algorithm
        3- Insertion Sort Algorithm
        4- Merge Sort Algorithm
        5- Quick Sort Algorithm
 - The program generates an array of random numbers, then sorts the array using each sorting algorithm 10 times, finally, it takes the average value for each sorting algorithm and print it on the screen!
 - Notice: the Quick Sort Algorithm shows a very poor performance. The reason is the way of choosing the pivot. In order to improve its performance, you need to choose one of the optimal methods for choosing the pivot value.
 */

#include <stdio.h>
#include "config.h"
#include "RandNumGen.h"
#include "BubbleSortAlgo.h"
#include "SelectionSortAlgo.h"
#include "InsertionSortAlgo.h"
#include "MergeSortAlgo.h"
#include "QuickSortAlgo.h"
#include <time.h>

int main(void) {
    //creating a specific array for each sorting algorithm so that each algorithm sort the same data, then measure the time taken for each algorithm
    int originalArray[ARR_LEN], bubbleArr[ARR_LEN], selectionArr[ARR_LEN], insertionArr[ARR_LEN], mergeArr[ARR_LEN],quickArr[ARR_LEN];
    randNumGen(originalArray);
    
    //these variables will be used to store the difference between the start and end for each algorithm. That could be done use an array instead of initializing 5 variables, but as I said, I'm building this project for fun! So there are alot of aspects to be improved.
    double bubbleTime = 0;
    double selectionTime = 0;
    double insertionTime = 0;
    double mergeTime = 0;
    double quickTime = 0;
    
    //creating two arrays to store the time before and after executing each function. That could be done using multidimentinal array
    clock_t bubbleStartTimer[RUNNING_TIME];
    clock_t bubbleEndTimer[RUNNING_TIME];
    clock_t selectionStartTimer[RUNNING_TIME];
    clock_t selectionEndTimer[RUNNING_TIME];
    clock_t insertionStartTimer[RUNNING_TIME];
    clock_t insertionEndTimer[RUNNING_TIME];
    clock_t mergeStartTimer[RUNNING_TIME];
    clock_t mergeEndTimer[RUNNING_TIME];
    clock_t quickStartTimer[RUNNING_TIME];
    clock_t quickEndTimer[RUNNING_TIME];
    
//    //printing the original array
//    for (int i = 0; i < ARR_LEN; i++)
//        printf("%d \t", originalArray[i]);
//    printf("\n");
    
    //This loop will run multiple times so that we can take the average of time taken in all runs.
    for (int i = 0; i < RUNNING_TIME; i++) {
        //filling in values in each array, so that it can be sorted again.
        for (int j = 0; j < ARR_LEN; j++) {
            bubbleArr[i] = originalArray[i];
            selectionArr[i] = originalArray[i];
            insertionArr[i] = originalArray[i];
            mergeArr[i] = originalArray[i];
            quickArr[i] = originalArray[i];
        }
        
        quickStartTimer[i] = clock();
        quickSortAlgo(quickArr);
        quickEndTimer[i] = clock();
        
        bubbleStartTimer[i] = clock();
        bubbleSortAlgo(bubbleArr);
        bubbleEndTimer[i] = clock();
        
        selectionStartTimer[i] = clock();
        selectionSortAlgo(selectionArr);
        selectionEndTimer[i] = clock();
        
        insertionStartTimer[i] = clock();
        insertionSortAlgo(insertionArr);
        insertionEndTimer[i] = clock();
        
        mergeStartTimer[i] = clock();
        mergeSortAlgo(mergeArr);
        mergeEndTimer[i] = clock();
    }
    
    //Taking average of all runs
    for (int i = 0; i < RUNNING_TIME; i++) {
        bubbleTime += (double)(bubbleEndTimer[i] - bubbleStartTimer[i]);
        selectionTime += (double)(selectionEndTimer[i] - selectionStartTimer[i]);
        insertionTime += (double)(insertionEndTimer[i] - insertionStartTimer[i]);
        mergeTime += (double)(mergeEndTimer[i] - mergeStartTimer[i]);
        quickTime += (double)(quickEndTimer[i] - quickStartTimer[i]);
    }
    
    printf("Time taken to sort the array ");
//    for (int i = 0; i < ARR_LEN; i++)
//            printf("%d \t", originalArray[i]);
    printf("by each algorithm on average:\n");
    printf("Bubble sort Algorithm: %.2lf\n", bubbleTime/RUNNING_TIME);
    printf("Selection sort Algorithm: %.2lf\n", selectionTime/RUNNING_TIME);
    printf("Insertion sort Algorithm: %.2lf\n", insertionTime/RUNNING_TIME);
    printf("Merge sort Algorithm: %.2lf\n", mergeTime/RUNNING_TIME);
    printf("Quick sort Algorithm: %.2lf\n", quickTime/RUNNING_TIME);
    
    return 0;
}
