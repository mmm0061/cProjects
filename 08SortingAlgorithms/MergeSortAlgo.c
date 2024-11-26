#include <stdio.h>
#include "MergeSortAlgo.h"
#include "config.h"


//the purpose of this function is to ease the process for the programmer, because all they need to provide is the array and its length
void mergeSortAlgo(int arr[]){
    mergeSortRecursion(arr, 0, ARR_LEN-1);//I gave zero and length-1 because this function will be called at the beginning of the algorithm only. Therefore, the leftmost element will always be zero and the mostright element will be always length-1 (because arrays start from zero!)
}

void mergeSortRecursion(int arr[], int l, int r){
    
    if(l < r){
        int m = l + (r - l) / 2;
        mergeSortRecursion(arr, l, m); //to sort the left side of the array (the smaller part of the array)
        mergeSortRecursion(arr, m+1, r); // to sort the right side of the array
        mergeSortedArrays(arr, l, m, r); //to merge the sorted arrays of the previous two functions
    }
}

void mergeSortedArrays(int arr[], int l, int m, int r)
{
    int leftLength = m - l + 1;
    int rightLength = r - m;
    //we define two temporary arrays to hold the two parts of the array we want to sort
    int tempLeftArr[leftLength];
    int tempRightArr[rightLength];
    
    int i, j, k;//counting variables, we will need them to index all three arrays on the third loop
    for(int i = 0; i < leftLength; i++)
        tempLeftArr[i] = arr[l + i];
    for(int i = 0; i < rightLength; i++)
        tempRightArr[i] = arr[m + 1 + i];
    for(i = 0, j = 0, k = l; k <= r; k++){
        if((i < leftLength) && (j >= rightLength || tempLeftArr[i] <= tempRightArr[j])){
            arr[k] = tempLeftArr[i];
            i++;
        }
        else{
            arr[k] = tempRightArr[j];
            j++;
        }
    }
        
}
