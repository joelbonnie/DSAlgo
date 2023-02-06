#include <stdio.h>
#include <stdlib.h>

//user defined structure for binary tree
typedef struct BTree{
    struct Btree *left; //left child
    int data; //data
    struct Btree *right; //right child
}NODE;


//initialising empty tree
NODE *root=NULL; //global declaration


