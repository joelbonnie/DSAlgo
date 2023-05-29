//implementing graph using adjacency matrix
//traversing graph using bfs
//considering static graph size

//functions
/*
createMatrix() - creates the matrix using user input
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 6

int matrix[SIZE][SIZE];


int createMatrix()
{
    int i,j,opt;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            printf("Is there a link between %d and %d[0-no/1-yes]: ", i+1,j+1);
            scanf("%d", &opt);
            if(opt)
            matrix[i][j] = optP;
        }
    }
    return 0;
}


int showMatrix()
{   
    int i, j;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}


int BFS()
{
    //pass
}

int main()
{
    createMatrix();
    showMatrix();
}