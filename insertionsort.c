#include <stdio.h>
int arr[]={45, 33, 12, 99, 10, 16};
int len=6;

void insertionSort(int arr[]){
    int i, j, t, key;
    for(i=1; i<len; i++){
        key = arr[i];
        for(j=i-1; j>=0 && arr[j] > key; j--){
            arr[j+1]  = arr[j];
        arr[j] = key;
        }
    }       
        
    for(i=0; i<len; i++){
        printf("%d\t", arr[i]);
        printf("\n");
    }  
}

void main(){
    insertionSort(arr);
}