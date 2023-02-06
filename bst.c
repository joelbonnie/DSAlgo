#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    int key;
    struct BST *left, *right;
}NODE;


NODE *root=NULL; //global init

void inorder(NODE* r){
    printf("\nrunning");
    while(r!= NULL){
        inorder(r->left);
        printf("%d\t", r->key);
        inorder(r->right);
    }
}


NODE* newNode(int k){
    NODE* temp=(NODE *)malloc(sizeof(NODE));
    temp->key=k;
    temp->left = temp->right = NULL;
    return temp;
}

void insert(NODE* node, int k){
    if(node==NULL){
        NODE* newnode = newNode(k);
        node = newnode;
        printf("\nInsertion successful");
    }
    if(k < node->key){
        insert(node->left, k);
    }
    else if(k > node->key){
        insert(node->right, k);
    }
}




void options(){
        printf("\n----------------------------------------------------------------------");
        printf("\n\nBinary Search Tree operations: ");
        printf("\n1. Insert a node ");
//         printf("\n2. Insert a node at the beginning");
//         printf("\n3. Insert a node at entered index");
//         printf("\n4. Delete first node");
//         printf("\n5. Delete last node");
//         printf("\n6. Delete node at entered index");
        printf("\n8. Display current tree");
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
                if(root==NULL){
                    root=newNode(e);
                }else{
                    insert(root, e);
                }
                break;
//             case 2:
//                 printf("\nEnter element to be inserted: ");
//                 scanf("%d",&e);
//                 insertFirst(e);
//                 break;
//             case 3:
//                 printf("\nCaution: This function will only work if the index is available in the existing list");
//                 printf("\nEnter element to be inserted: ");
//                 scanf("%d", &e);
//                 printf("\nEnter position to insert at: ");
//                 scanf("%d", &p);
//                 insertPos(e,p);
//                 break;
//             case 4:
//                 e=deleteFirst();
//                 printf("Deleted element: %d", e);
//                 break;
//             case 5:
//                 e=deleteLast();
//                 printf("Deleted element: %d", e);
//                 break;
//             case 6:
//                 printf("\nCaution: This function will only work if the index is available in the existing list");
//                 printf("\nEnter index of node to be deleted: ");
//                 scanf("%d", &p);
//                 e=deletePos(p);
//                 printf("Deleted element: %d", e);
//                 break;
            case 8:
                inorder(root);
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