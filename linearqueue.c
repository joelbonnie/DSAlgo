#include <stdio.h>
#define SIZE 5
//init
int q[SIZE];
int front=0, rear=-1;


void enqueue(int x){
    //enqueues element
    //prints message if queue is full
    if(rear == SIZE-1){
        printf("\nQueue full.");
    }
    else{
        rear++;
        q[rear] = x;
    }
}

void dequeue(){
    //deqeues element
    //prints message if queue is empty
    if(front>rear){
        printf("\nQueue empty. Nothing to dequeue");
    } 
    else{
        printf("\nDequeued element: %d", q[front]);
        front++;
    }
}

void display(){
    //displays current queue
    //prints message if queue is empty
    if(front>rear){
        printf("\nQueue is empty. Nothing to display.");
    }
    else{
        int i;
        printf("\nCurrent queue: \n");
        for(i=front; i<=rear; i++){
            printf("%d\n", q[i]);
        }
    }
}

void main(){
    int opt=1, x;
    while(opt!=4){
        printf("\nEnter an option(1-Enqueue, 2-Dequeue, 3-Display, 4-Exit): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("\nEnter element to be enqueued: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nEnding queue operations.");
            break;
        default:
            printf("\nPlease enter a valid option.");
            break;
        }
    }
    printf("\nExiting. Bye!\n");
}