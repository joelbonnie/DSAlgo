#include <stdio.h>
#include <stdlib.h>

/*
README
This program manipulates a single global list with the help of a head pointer
Included functions:
1. display **does not work if list has only one node
2. insertLast
3. insertFirst
4. insertPos
5. deleteFirst
6. deleteLast
7. deletePos
deletePos and insertPos do not work on first or last nodes
*/

//declaring user defined structure for doubly linked list
typedef struct DLL{
    struct DLL *prev; //previous node
    int data; 
    struct DLL *next; //next node
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
    /*
    params:
        int k: element to be inserted
    desc:
        Inserts new node at the very beginning. 
        No traversals required
    */
    NODE *newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=k; //assigns key value
    newnode->prev=NULL; //prev is NULL because newnode is now the first node
    //placing newnode into list
    newnode->next=head; 
    head=newnode;
    printf("\nInsertion successful");
}


void insertPos(int k, int pos){
    NODE *newnode=(NODE *)malloc(sizeof(NODE)), *temp=head;
    newnode->data=k;
    int i;
    for(i=0; i<pos-1; i++){ //traversing to node at pos-1
        temp=temp->next;
    }
    newnode->next=temp->next; //forward link 
    newnode->prev=temp; //backward link
    temp->next->prev=newnode; //updating backward link of succeeding node
    temp->next=newnode; //updating forward link of preceding node
}

int deleteFirst(){
    /*
    params: NIL
    desc:
        Deletes the first node and deallocates its memory
        Returns the data stored in the deleted node
    */
    int k;
    NODE *del=head; //node to be deleted
    head=head->next; //head is updated to succeeding node
    head->prev=NULL;
    k=del->data; //return value is assigned
    free(del); //memory deallocated
    return k; 
}

int deleteLast(){
    /*
    params: NIL
    desc:
        Parses through list and deletes last node
        Returns key of last node
    */
    NODE *temp=head, *del;
    int k;
    while(temp->next->next != NULL){ //Traverses to second last node
        temp=temp->next;
    }
    del=temp->next; //sets the node to be deleted
    k = del->data; //storing return value
    temp->next=NULL; //delinking node
    free(del); //deallocating memory
    return k; 
}

int deletePos(int pos){
    /*
    params: 
        int pos: Position of node to be deleted
    desc:
        Parses through list to reach desired node
        Delinks node
        Deallocates memory
        Returns value stored in deleted node
    */
    NODE *del, *temp=head;
    int k,i;
    for(i=0; i<pos-1; i++){ //parses through node right before  node to be deleted
        temp=temp->next;
    }
    del=temp->next; //sets the node to be deleted
    k=del->data; //storing return value
    temp->next=del->next; //delinking node
    del->next->prev=temp; //relinking existing list backwards
    free(del); //deallocating memory
    return k;
}


void options(){
        printf("\n----------------------------------------------------------------------");
        printf("\n\nDoubly linked list operations: ");
        printf("\n1. Insert a node at the end");
        printf("\n2. Insert a node at the beginning");
        printf("\n3. Insert a node at entered index");
        printf("\n4. Delete first node");
        printf("\n5. Delete last node");
        printf("\n6. Delete node at entered index");
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
            case 3:
                printf("\nCaution: This function will only work if the index is available in the existing list");
                printf("\nEnter element to be inserted: ");
                scanf("%d", &e);
                printf("\nEnter position to insert at: ");
                scanf("%d", &p);
                insertPos(e,p);
                break;
            case 4:
                e=deleteFirst();
                printf("Deleted element: %d", e);
                break;
            case 5:
                e=deleteLast();
                printf("Deleted element: %d", e);
                break;
            case 6:
                printf("\nCaution: This function will only work if the index is available in the existing list");
                printf("\nEnter index of node to be deleted: ");
                scanf("%d", &p);
                e=deletePos(p);
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