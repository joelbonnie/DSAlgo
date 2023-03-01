#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadedBinaryTree{
	int lbit, rbit; //indicates whether child is a node or thread
	struct ThreadedBinaryTree *left, *right; 
	int data;
}NODE;

NODE *root=NULL, *dummy; 

void insert(NODE *current, int key){
	NODE *newnode=(NODE *)malloc(sizeof(NODE));
	newnode->data=key;
	newnode->lbit=newnode->rbit=0;
	if(root==NULL){ //Initialising empty tree
		root=newnode;
		newnode->lbit=newnode->rbit=1;
		newnode->left=newnode->right=dummy;
		printf("\nInsertion successful");
	}          
	else{
		while(1){
			if(key<current->data && current->lbit==1){ 
				newnode->left=current->left; 
				newnode->lbit=1;
				current->left=newnode;
				current->lbit=0;
				newnode->right=current;
				newnode->rbit=1;                                                                                                               
				printf("\nInsertion successful");
				break;
			}
			else if(key>current->data && current->rbit==1){
				newnode->right=current->right;
				newnode->rbit=1;
				current->right=newnode;
				current->rbit=0;
				newnode->left=current;
				newnode->lbit=1;                                     
				printf("\nInsertion successful");
				break;
			}
			else if(key<current->data && current->lbit==0){
				current=current->left;
			}
			else if(key>current->data && current->rbit==0){
				current=current->right;
			}
		}
	}                             
}


void inorder(NODE *current){
	while(current->lbit == 0){ //bringing current to the leftmost node
		current=current->left;
	}
	while(current!= dummy){ //terminates at the rightmost node 
		printf("%d\t", current->data);
		current=current->right; //moving current to inorder successor
	}
}



//MAIN
int main(){
	int opt=0,e;
	while(opt != 8){
		printf("\n\nMenu: ");
		printf("\n\t1. Insert an element");
		printf("\n\t2. Inorder traversal");
		printf("\n\t8. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("\nEnter element to be inserted: ");
				scanf("%d", &e);
				insert(root, e);
				break;
			case 2:
				if(root==NULL){
					printf("\nEmpty Tree. Unable to traverse.");
				}
				else{
					inorder(root);
				}
				break;
			case 8:
				printf("\nEnding Binary Tree Operations");
				break;
			default:
				printf("\nPlease enter a valid option");
				break;
		}
	}
	return 0;
}
//main ends

//END

