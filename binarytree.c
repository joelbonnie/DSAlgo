#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

//Binary tree functions begin
typedef struct BTree {
	struct BTree *left; //left child
	int data;
	struct BTree *right; //right child
}NODE;

NODE *root = NULL; //initialising empty tree
NODE *arr[SIZE];
int top=-1;
//stack functions start


void push(NODE *temp){
	top++;
	arr[top] = temp;
}


NODE *pop(){
	if (top==-1){return NULL;}
	NODE* temp = arr[top];
	top--;
	return temp;
}
//stack functions end


void inorder(NODE *r){
	if(r){
		inorder(r->left);
		printf("%d\t", r->data);
		inorder(r->right);
	}
}

void preorder(NODE *r){
	if(r){
		printf("%d\t",r->data);
		preorder(r->left);
		preorder(r->right);
	}
}

void postorder(NODE *r){
	if(r){
		postorder(r->left);
		postorder(r->right);
		printf("%d\t",r->data);	
	}
}


void preorderNonRecursive(NODE *r){
	NODE* r1=r;
	while(1){
		while(r1){
			printf("%d\t", r1->data);
			if(r1->right){
				push(r1->right);
			}
			r1=r1->left;
		}
		r1=pop();
		if(!r1){
			break;
		}
	}
}


void insert(int k){
	NODE *newnode = (NODE *)malloc(sizeof(NODE)); //allotting space for new node
	newnode->data = k;
	newnode->left = NULL;
	newnode->right = NULL;
	if(root == NULL){ //creating root node of empty tree
		root = newnode;
		printf("\nInsertion Successful. Tree created.");
		return;
	}
	//for an existing tree
	NODE *temp = root, *prev;
	int c;
	printf("\nValue in ROOT: %d", root->data);	
	while (temp != NULL){
		printf("\nValue in current node: %d", temp->data);
		printf("\nDo you wish to create left(1) or right(2) subtree? :");
		scanf("%d", &c);
		if(c==1){
			prev=temp;
			temp=temp->left;
			if(temp==NULL){
				temp=newnode;
				prev->left=temp;
				printf("\nInsertion Successful");
				return;
			}
			
		}
		else if(c==2){
			prev=temp;
			temp=temp->right;
			if(temp==NULL){
				temp=newnode;
				prev->right=temp;
				printf("\nInsertion Successful");
				return;
			}	
		}
	}
}


//binary tree functions end


//main begins
int main(){
	int opt=0,e;
	while(opt != 7){
		printf("\n\nMenu: ");
		printf("\n\t1. Insert an element");
		printf("\n\t2. Inorder traversal");
		printf("\n\t3. Preorder traversal");
		printf("\n\t4. Postorder traversal");
		printf("\n\t5. Preorder Non Recursive traversal");
		printf("\n\t7. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("\nEnter element to be inserted: ");
				scanf("%d", &e);
				insert(e);
				break;
			case 2:
				if(root==NULL){
					printf("\nEmpty Tree. Unable to traverse.");
				}
				else{
					inorder(root);
				}
				break;
			case 3:
				if(root==NULL){
					printf("\nEmpty Tree. Unable to traverse.");
				}
				else{
					preorder(root);
				}
				break;
			case 4:
				if(root==NULL){
					printf("\nEmpty Tree. Unable to traverse.");
				}
				else{
					postorder(root);
				}
				break;
			case 5:
				if(root==NULL){
					printf("\nEmpty Tree. Unable to traverse.");
				}
				else{
					preorderNonRecursive(root);
				}
				break;
			case 7:
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