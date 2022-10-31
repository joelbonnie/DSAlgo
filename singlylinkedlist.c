#include <stdio.h>

// typedef struct List{
//     int key;
//     struct List *next;
// }NODE;

// NODE *head = NULL;

// void create(int k){
//     NODE *x = (NODE *)malloc(sizeof(NODE)), *y=head;
//     x -> key=k;
//     x -> next=NULL;
//     if(!head){
//         head = x;
//         return;
//     }
//     while(y -> next!=NULL){
//         y=y->next;
//     }
//     y->next=x;
// }


typedef struct node{
    int data;
    struct node *next;
}NODE;

NODE *head, *new=(NODE *)malloc(sizeof(NODE));
head = NULL;
*new = (NODE *)malloc(sizeof(NODE));