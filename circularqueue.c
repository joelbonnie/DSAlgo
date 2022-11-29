#include <stdio.h>
#define SIZE 5

int cq[SIZE];

int front=-1, rear=-1;


int insert(int e){
    if((rear+1)%SIZE==front){
        printf("\nQueue is full. No more elements can be inserted.");
        return -1;
    }	
    if(front==-1)
        front = 0;
    rear = (rear + 1) % SIZE;
    cq[rear] = e;
    printf("\nElement inserted successfully");
    return 0;
}

int del(){
    if(front == -1){
        printf("\nQueue is empty. Nothing to delete");
        return -1;
    }
    int e = cq [front];
    if(front == rear){
        front = rear = -1;
    }else{
        front = (front + 1) % SIZE;
        printf("\nDeleted element: %d", e);
        return e;
    }
}

void display(){
    if(front == -1){
        printf("\nQueue is empty. Nothing to display");
    }
    int i;
    for(i=front; i != rear; i=(i+1)%SIZE){
        printf("%d \n", cq[i]);
    }
    printf("%d \n", cq[rear]);
    
}

void main(){
	int opt, e;
	printf("\nEnter an option(1-insert, 2-delete, 3-display, 4-quit): ");
	scanf("%d: ",&opt);
	while(opt!=4){
			if(opt==1){
				printf("\nEnter element for insertion: ");
				scanf("%d: ",&e);
				insert(e);
			}else if(opt==2){
				e = del();
			}else if(opt==3){
				display();
			}else{
				printf("\nPlease enter a valid option.");
			}
			printf("\nEnter an option(1-insert, 2-delete, 3-display, 4-quit): ");
			scanf("%d: ",&opt);	
		}
	printf("\nExiting. Bye!\n");
}

