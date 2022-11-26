#include <stdio.h>
#include <stdlib.h>

/*
This program only contains the functions for circular singly linked list 
that are different from singly linked list. All others have been omitted 
cause I'm lazy asf
Included functions:
1. insertFirst
2. insertLast
3. deleteFirst
4. deleteLast
5. display

*/

//declaring structure
//same node structure as singly linked list
typedef struct CSLL{
    int data; //data 
    struct CSLL *next; //pointer to next node
}NODE;

NODE *head=NULL;

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
    }while(temp->next!=head); //stops execution but last node is not printed

    printf("%d\n", temp->data); //last node is printed
    return; //function end
}

void insertLast(int k){
    /*
    params:
        int k - input value from user that needs to be inserted into the end of the current list
    desc:
        if the list is currently empty, the head node is simply made to point to the newnode
        if the list is not empty, the function inserts the newnode at the end of the list
    */
    NODE *newnode; //creating newnode of type node
    newnode = (NODE*)malloc(sizeof(NODE)); //using dynamic memory allocation to allot slot for node
    //also, the newly assigned memory is typecasted to type NODE using (NODE*)
    newnode->data = k; //assigning data as provided by the user
    if(head==NULL){ //empty list
        head=newnode; //head is assigned directly to newnode
        head->next=newnode;
    }
    else{ //nonempty list
        NODE *temp=head; //helper pointer to help traverse to end of list
        while(temp->next!=head){ 
            //loop enables traveral to final node
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode; //final node points to newnode which is the new final node with next=head
    }
    printf("\nInsertion successful"); //only prints if insertion is successful
    return; //function end
}


void insertFirst(int k){
    /*
    params:
        int k - value entered by the user
    desc:
        inserts the entered element at the beginning of the list
        newnode becomes the new head node 
    */
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data=k;
    newnode->next=head; 
    /*since newnode is inserted at the very beginning, its next element is the node 
    currently pointed to by head*/
    NODE *temp=head;
    while(temp->next != head){
        temp=temp->next;
    }
    temp->next=newnode;
    head=newnode; //head is replaced by newnode
}



int deleteFirst(){
    /*
    params: NIL
    desc:
        deletes first element in the list and deallocates the memory 
        that was allocated to it
    */
    int k;
    k=head->data; //saves data to be returned 
    NODE *del;
    del=head; //del points to first element
    head=head->next; //head now points to the second element
    NODE *temp=head;
    while(temp->next != del){
        temp=temp->next;
    }
    temp->next=head;
    free(del); //first element is deallocated
    return k; //deleted data is returned
}


int deleteLast(){
    /*
    params: NIL
    desc:
        traverses to the last node, deletes it, deallocates alloted memory
    */
    NODE *temp=head; //helper node
    while(temp->next->next != head){ //traverses to second last element
        temp=temp->next;
    }
    int k;
    k = temp->next->data; //stores data of last node
    free(temp->next); //deletes last node
    temp->next=head; //sets next value of second last element to head
    return k; //returns deleted value
}



void options(){
        printf("\n----------------------------------------------------------------------");
        printf("\n\nOptions: ");
        printf("\n1. Insert a node at the end");
        printf("\n2. Insert a node at the beginning");
        printf("\n4. Delete first node");
        printf("\n5. Delete last node");
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
            case 4:
                e=deleteFirst();
                printf("Deleted element: %d", e);
                break;
            case 5:
                e=deleteLast();
                printf("Deleted element: %d", e);
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