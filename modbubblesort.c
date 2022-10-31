#include <stdio.h>
#include <stdio.h>
int arr[]={45, 33, 12, 99, 10, 16};
int len=6;

void modBSort(int arr[]){
    int i, j, t, flag=1;
    for(i=0; i<len-1; i++){
        for(j=0; j<len-i-1 && flag; j++){
            flag = -1; // does not allow outer loop to parse if swaps do not occur
            if(arr[j] > arr[j+1]){
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
                flag = 1;
            }
        }
    }
    for(i=0; i<len; i++){
        printf("%d\t", arr[i]);
        printf("\n");
    }  
}

void main(){
    modBSort(arr);
}