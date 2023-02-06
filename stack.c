#include <stdio.h>
#define SIZE 5
int top=-1;
int arr[SIZE];


void display(){
    //displays current stack
    if(top==-1){
        printf("\nStack empty");
    }
    else{
        int i;
        for(i=0; i<=top; i++){
            printf("%d\t", arr[i]);
        }
    }
}

void push(int x){
    //adds a new element to top of stack
    //returns error if stack is already full
    if(top < SIZE-1){
        top++;
        arr[top] = x;
        printf("\nPush successful.");
    }
    else{
        printf("\nStack full.");
    }
}

int pop(){
    //removes element at the top of stack
    //prints error if stack is empty
    if(top==-1){
        printf("\nStack empty");
        return -1;
    }
    else{
        int k=arr[top];
        printf("\nPopped element: %d", k);
        top--;
        return k;
    }
}

void peek(){
    //displays topmost element in stack
    //prints error message for empty stack
    if(top == -1){
        printf("\nStack empty");
    }
    else{
        printf("Top: %d", arr[top]);
    }
}



void options(){
        printf("\n----------------------------------------------------------------------");
        printf("\n\nStack Operations: ");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n8. Display current stack");
        printf("\n9. Terminate\n");
        printf("\nEnter your choice: ");
    }

void main(){
    int flag=1, choice, e, p;
    while(flag){
        options();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter element to be inserted: ");
                scanf("%d",&e);
                push(e);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 8:
                display();
                break;
            case 9:
                printf("\nTerminating. Bye!\n");
                flag=0;
                break; 
            default:
                printf("\nInvalid input. Please try again.");
                break;
        }
    }
}
//end