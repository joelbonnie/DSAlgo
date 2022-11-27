#include <stdio.h>
#include <stdlib.h>


//user defined structure
typedef struct BTree{
    struct Btree *left; //left child
    int data; //data
    struct Btree *right; //right child
}NODE;

NODE *root=NULL; //empty tree initialised