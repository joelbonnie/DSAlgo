#include <stdio.h>
#include <stdlib.h>

//test set : 20, 30, 50, 10, 5, 70, 80, 90, 45, 40 (only LL, RR rotations)

typedef struct AVLTree{
	struct AVLTree *left, *right;
	int data;
}NODE;


NODE *root=NULL;  //initialising empty tree

// Helper functions
int getHeight(NODE* current)
{
	int hr, hl;
	if(current == NULL) 
	{
		return 0;
	}
	else
	{
		hl = getHeight(current->left);
		hr = getHeight(current->right);
		return(1+hl>rl?hl:rl);
	}
}

int balanceFactor (NODE* current)
{
	return (getHeight(current->left) - getHeight(current->right));
}

void balanceNode(NODE* current) //uses postorder traversal to find the bottommost disbalanced node
{
	if(current)
	{
		balanceNode(current->left);
		balanceNode(current->right);
		if (getHeight(current)==-1 || getHeight(current)==0 || getHeight(current)==1)
		{
			return;
		}
		else
		{
			if(getHeight(current)<-1)
			{
				rotateRR(current);
			}
			else if(getHeight(current)>1)
			{
				rotateLL(current);
			}
		}	
	}
}


NODE* searchParent(NODE* child){
	NODE* parent = root;
	while(1){
		if(parent->right == child || parent->left == child){
				return parent;
		}
		if(child->data > parent->data){	
			parent = parent->right;
		}
		else if(child->data < parent)->data{
			parent = parent->left;
		}
	}
}

void rotateLL(NODE* current{
	NODE *parent = searchParent(current), *leftchild;
	if (parent == NULL){
		root = current->left;
	}
	else if(parent->left == current){
		parent->left = current->left;
	}
	else if(parent->right == current){
		parent->right = current->left;
	}
	leftchild = current->left;
	current->left = leftchild->right;
	leftchild->right = current;
}

void rotateRR(){
	NODE *parent = searchParent(current), *rightchild;
	if (parent == NULL){
		root = current->right;
	}
	else if(parent->right == current){
		parent->right = current->right;
	}
	else if(parent->left == current){
		parent->left = current->right;
	}
	rightchild = current->right;
	current->right = rightchild->left;
	rightchild->left = current;
}

//Insertion
void insert(NODE* current, int key)
{
	//allocating new node
	NODE *newnode = (NODE *)malloc(sizeof(NODE)); 
	newnode->data = key;
	newnode->left = NULL;
	newnode->right = NULL;
	if(!current)
	{
		root=newnode;
		printf("\nInsertion successful");
	}
	else
	{
		while(current)
		{
			if(key<current->data && !current->left)
			{
				current->left=newnode;
				printf("\nInsertion successful");
				break;
			}
			else if(key>current->data && !current->right)
			{
				current->right=newnode;
				printf("\nInsertion successful");
				break;
			}
			else if(key<current->data && current->left)
			{
				current=current->left;
			}
			else if(key>current->data && current->right)
			{
				current=current->right;
			}
		}
	}	
	//checks
}

//TRAVERSALS
void inorder(NODE *r)
{
	if(r)
	{
		inorder(r->left);
		printf("%d\t", r->data);
		inorder(r->right);
	}
}

//MAIN
int main()
{
	int opt=0,e;
	while(opt != 8)
	{
		printf("\n\nMenu: ");
		printf("\n\t1. Insert an element");
		printf("\n\t2. Inorder traversal");
//		printf("\n\t3. Preorder traversal");
//		printf("\n\t4. Postorder traversal");
//		printf("\n\t5. Preorder Non Recursive traversal");
//		printf("\n\t6. Inorder Non Recursive traversal");
//		printf("\n\t7. Postorder Non Recursive traversal");
		printf("\n\t8. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &opt);
		switch(opt)
		{
			case 1:
				printf("\nEnter element to be inserted: ");
				scanf("%d", &e);
				insert(root, e);
				break;
			case 2:
				if(root==NULL)
				{
					printf("\nEmpty Tree. Unable to traverse.");
				}
				else
				{
					inorder(root);
				}
				break;
//			case 3:
//				if(root==NULL){
//					printf("\nEmpty Tree. Unable to traverse.");
//				}
//				else{
//					preorder(root);
//				}
//				break;
//			case 4:
//				if(root==NULL){
//					printf("\nEmpty Tree. Unable to traverse.");
//				}
//				else{
//					postorder(root);
//				}
//				break;
//			case 5:
//				if(root==NULL){
//					printf("\nEmpty Tree. Unable to traverse.");
//				}
//				else{
//					preorderNonRecursive(root);
//				}
//				break;
//			case 6:
//				if(root==NULL){
//					printf("\nEmpty Tree. Unable to traverse.");
//				}
//				else{
//					inorderNonRecursive(root);
//				}
//				break;
//			case 7:
//				if(root==NULL){
//					printf("\nEmpty Tree. Unable to traverse.");
//				}
//				else{
//					postorderNonRecursive(root);
//				}
//				break;
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
