#include <stdio.h>
#include <stdlib.h>

/*
README
This program manipulates a single global list with the help of a head pointer
Included functions:
1. display
2. create (doubles as insertLast)
3. insertFirst
4. insertPos
5. deleteFirst
6. deleteLast
7. deletePos
8. reverse
*/

//declaring singly linked list user defined structure

typedef struct SLL{
    int data;  
    struct SLL *next;
}NODE;


NODE *head=NULL; //global declaration of head

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


void create(int k){
    /*
    params:
        int k - input value from user that needs to be inserted into the end of the current list
    desc:
        if the list is currently empty, the head node is simply made to point to the newnode
        if the list is not empty, the function inserts the newnode at the end of the list
        This function doubles as the insert-last function
    */
    NODE *newnode; //creating newnode of type node
    newnode = (NODE*)malloc(sizeof(NODE)); //using dynamic memory allocation to allot slot for node
    //also, the newly assigned memory is typecasted to type NODE using (NODE*)
    newnode->data = k; //assigning data as provided by the user
    newnode->next = NULL; //insertion at last => next is NULL
    if(head==NULL){ //empty list
        head=newnode; //head is assigned directly to newnode
    }
    else{ //nonempty list
        NODE *temp=head; //helper pointer to help traverse to end of list
        while(temp->next!=NULL){ 
            //loop enables traveral to final node
            temp=temp->next;
        }
        temp->next=newnode; //final node points to newnode which is the new final node with next=NULL
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
    head=newnode; //head is replaced by newnode 
}


void insertPos(int k, int pos){
    /*
    params: 
        int k: element to be inserted
        int pos: position at which element is to be inserted
    desc:
        the element at pos is replaced by the entered element. 
        All succeeding elements are pushed forward by one index
        The memory location of the pushed elements remain unchanged
    */
    NODE *newnode = (NODE *)malloc(sizeof(NODE)), *temp=head; //declarations
    newnode->data=k; //data is assigned to newnode
    int i;
    for(i=0; i<pos-1; i++){ //loop to bring temp to the element to index pos-1
        temp=temp->next;
    }
    newnode->next = temp->next; // newnode.next is updated to temp.next
    temp->next = newnode;   //newnode-1.next is updated to newnode
    printf("\nInsertion successful");
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
    while(temp->next->next != NULL){ //traverses to second last element
        temp=temp->next;
    }
    int k;
    k = temp->next->data; //stores data of last node
    free(temp->next); //deletes last node
    temp->next=NULL; //sets next value of second last element to null
    return k; //returns deleted value
}

int deletePos(int pos){
    /*
    params: 
        int p: position of element to be deleted
    desc:
        traverses to element to be deleted
        reassigns next value of previous node
        deallocates deleted node
    */
    int i;
    NODE *temp=head; //helper node
    for(i=0; i<pos-1; i++){ //traverses the node right before node to be deleted
        temp=temp->next;
    }
    int k;
    k = temp->next->data; //storing data of node to be deleted
    NODE *del=temp->next; //storing node to be deleted
    temp->next = del->next; //removing link to deleted node
    free(del); //deallocating memory used by deleted node
    return k; //returning deleted value
}

void reverse(){
    /*
    params: NIL
    desc:
        Iterative approach that simply reverses all the links
        Memory locations of all nodes stays the same
    */
    NODE *prevnode=NULL, *currentnode, *nextnode; 
    //prevnode init to NULL because first node has no previous node
    //current node points to node being manipulated
    //next node points to succeeding node since its link will be destoyed
    currentnode=nextnode=head;
    while(nextnode!=NULL){ //breaks when last element is reached
        nextnode=currentnode->next; //pointing to succeeding node
        currentnode->next=prevnode; //link reversed
        prevnode=currentnode; //prevnode updated
        currentnode=nextnode; //currentnode updated
    }
    head=prevnode; //last element of old list is now head

}

void options(){
        printf("\n----------------------------------------------------------------------");
        printf("\n\nOptions: ");
        printf("\n1. Insert a node at the end");
        printf("\n2. Insert a node at the beginning");
        printf("\n3. Insert a node at entered index");
        printf("\n4. Delete first node");
        printf("\n5. Delete last node");
        printf("\n6. Delete node at entered index");
        printf("\n7. Reverse current list");
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
                create(e);
                break;
            case 2:
                printf("\nEnter element to be inserted: ");
                scanf("%d",&e);
                insertFirst(e);
                break;
            case 3:
                printf("Enter element to be inserted: ");
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
                printf("\nEnter index of node to be deleted: ");
                scanf("%d", &p);
                deletePos(p);
                break;
            case 7:
                reverse();
                printf("\nList reversed");
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
