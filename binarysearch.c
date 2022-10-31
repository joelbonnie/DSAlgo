#include <stdio.h>


int binarySearch(int arr[], int x, int low, int high){
    int mid = (low + high) /2;
    while(low < high){
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid]>x){
            binarySearch(arr, x, low, mid-1);
        }
        else if(arr[mid] < x){
            binarySearch(arr, x, mid+1, high);
        }
    }
    return -1;
}