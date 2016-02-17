//
//  main.cpp
//  RandomizedQuicksort
//
//  Created by Kevin Zhang on 2016-02-13.
//  Copyright © 2016 Kevin Zhang. All rights reserved.
//

#include <iostream>
using namespace std;

void printArray(int arr[], int arr_size);
//quickSort wrapper
int RquickSort(int arr[], int arr_size);
//
int doRQuickSort(int arr[], int low, int high);
int RPartition(int arr[], int low, int high);
int RandomizedPartition(int arr[], int low, int high);


int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[5] = {5,4,3,2,1};
    int arr_size = 5;
    RquickSort(arr, arr_size);
    printArray(arr, arr_size);
    return 0;
}

//wrapper call
int RquickSort(int arr[], int arr_size){
    int low = 0;
    int high = arr_size-1;
    
    int barOps= doRQuickSort(arr, low, high);
    return barOps;
    
}

int doRQuickSort(int arr[], int low, int high){
    int barOps=0;
    if (low < high){
        int pivot = RandomizedPartition(arr, low, high);
        doRQuickSort(arr, low, pivot-1);
        doRQuickSort(arr, pivot+1, high);
    }
    return barOps;
}

int RandomizedPartition(int arr[], int low, int high){
    int i = low + rand()%(high-low+1);
    //swap arr[high] with arr[i]
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    
    return RPartition(arr, low, high);
}

int RPartition(int arr[], int low, int high){
    int pivot=arr[high];
    int i = low;
    for (int j = low; j<=high-1; ++j) {
        if (arr[j]<=pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    //
    return i;
}

void printArray(int arr[], int arr_size){
    //read every element of the array
    for (int i = 0; i<arr_size; ++i) {
        cout<< " " <<arr[i];
    }
    //print out that element
}

