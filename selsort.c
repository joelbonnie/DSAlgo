#include <stdio.h>
int arr[]={45, 33, 12, 99, 10, 16};
int len=6;

void selSort(int a[]){
    int i,j,t;
    for(i=0; i<len-1; i++){
        for(j=i+1; j<len; j++){
            if(a[j] < a[i]){
                t = a[j];
                a[j] = a[i];
                a[i] = t;
            }
        }
    }
    for(i=0; i<len; i++){
        printf("%d\t", a[i]);
        printf("\n");
    }   
}

void main(){
    selSort(arr);
}