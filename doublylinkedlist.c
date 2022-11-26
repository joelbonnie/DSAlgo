#include <stdio.h>
#include <stdlib.h>

typedef struct DLL{
    int data; 
    struct DLL *prev, *next; //pointers to previous and next nodes
}NODE;

NODE *head=NULL; //initialising head pointer

void display(){
    /*
    params: NIL
    desc:
        Simple function to use the head pointer to parse through the linked list
        and display each node
    */
    NODE *temp=head; //helper node to traverse
    if(head==NULL){ //print condition for empty list
        printf("Empty list");
        return; //breaks function
    }
    printf("\nCurrent List:\n");
    do{ //start traversal
        printf("%d\t", temp->data);
        temp=temp->next;
    }while(temp->next!=NULL); //stops execution but last node is not printed

    printf("%d\n", temp->data); //last node is printed
    return; //function end
}

void insertLast(int k){
    /*
    params: 
        int k: Element to be inserted into the the list
    desc:
        Parses through the list using head pointer
        Inserts node at end
    */
    NODE *newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=k;
    newnode->next=NULL; //next pointer of last node is NULL
    if(head==NULL){ //condition if list is empty
        head=newnode;
        newnode->prev=NULL; 
    }
    else{ //if list is nonempty
        NODE *temp=head; //helper pointer to traverse the list
        while(temp->next != NULL){ //traverses to last node
            temp = temp->next;
        }
        temp->next=newnode; //adding newnode to list
        newnode->prev=temp;
    }
    printf("\nInsertion successful");
}


void insertFirst(int k){
    NODE *newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=k;
    newnode->prev=NULL;
    newnode->next=head;
    head=newnode;
    printf("\nInsertion successful");
}












void options(){
        printf("\n----------------------------------------------------------------------");
        printf("\n\nDoubly linked list operations: ");
        printf("\n1. Insert a node at the end");
        printf("\n2. Insert a node at the beginning");
        // printf("\n3. Insert a node at entered index");
        // printf("\n4. Delete first node");
        // printf("\n5. Delete last node");
        // printf("\n6. Delete node at entered index");
        // printf("\n7. Reverse current list");
        printf("\n8. Display current list");
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
                insertLast(e);
                break;
            case 2:
                printf("\nEnter element to be inserted: ");
                scanf("%d",&e);
                insertFirst(e);
                break;
            // case 3:
            //     printf("Enter element to be inserted: ");
            //     scanf("%d", &e);
            //     printf("\nEnter position to insert at: ");
            //     scanf("%d", &p);
            //     insertPos(e,p);
            //     break;
            // case 4:
            //     e=deleteFirst();
            //     printf("Deleted element: %d", e);
            //     break;
            // case 5:
            //     e=deleteLast();
            //     printf("Deleted element: %d", e);
            //     break;
            // case 6:
            //     printf("\nEnter index of node to be deleted: ");
            //     scanf("%d", &p);
            //     deletePos(p);
            //     break;
            // case 7:
            //     reverse();
            //     printf("\nList reversed");
            //     break;
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