#include <stdio.h>

int linearSearch(int x, int arr[], int i){
    if(arr[i] == x){
        return i;
    }
    else if(arr[i]!=0 && i>0){
        i--;
        return linearSearch(x, arr, i);
    }
    return -1;
}