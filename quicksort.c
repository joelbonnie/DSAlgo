#include <stdio.h>

int a[]={45, 33, 12, 99, 10, 16};
int len=6, low=0, high=5, t;


int partition(int arr[], int lb, int ub){
    int pivot=arr[lb], start=lb, end=ub;
    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end>pivot]){
            end--;
        }
        if(start<end){
            t = arr[start];
            arr[start] = arr[end];
            arr[end] = t;
        }
    }
    t = arr[lb];
    arr[lb] = arr[end];
    arr[end] = t;
    return end;
}

void quickSort(int arr[], int lb, int ub){
    int loc;
    if(lb<ub){
        loc = partition(arr, lb, ub);
        quickSort(arr, lb, loc-1);
        quickSort(arr, loc+1, ub);
    }
}

void display(int arr[]){
    int i;
    printf("\n");
    for(i=0; i<len; i++){
        printf("%d\t", arr[i]);
        printf("\n");
    }
}

void main(){
    quickSort(a, low, high);
    display(a);
}