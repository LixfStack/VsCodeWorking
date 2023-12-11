#include <stdio.h>
#include <stdlib.h>

#define X_LEN 7
#define Y_LEN 6
#define EQUAL 0
#define UP    1
#define LEVEL 2

void lcsLength(char *x,char *y,int c[X_LEN+1][Y_LEN+1],int b[X_LEN+1][Y_LEN+1])
{
    int i,j;
    for ( i = 0; i < X_LEN; i++)
    {
        c[i][0] = 0;
    }
    for ( j = 0; i < Y_LEN; j++)
    {
       c[0][j] = 0;
    }
    for ( i = 1; i <= X_LEN; i++)
    {
        for ( j = 1; j <= Y_LEN; j++)
        {
            if (x[i] == y[j])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i][j] = EQUAL;
            }
            else if (c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = UP;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = LEVEL;
            }
             
        }
        
    }
    
}

void printLCS(int b[X_LEN+1][Y_LEN+1], char *x,int i,int j)
{
    if (i==0 || j==0)
    {
        return;
    }
    if (b[i][j] == EQUAL)
    {
        printLCS(b,x,i-1,j-1);
        printf("%c ",x[i]);
    }
    else if (b[i][j] == UP)
    {
        printLCS(b,x,i-1,j);
    }
    else
    {
        printLCS(b,x,i,j-1);
    }
    
    
}

int main()
{
    char X[X_LEN+1] = {' ','A','B','C','B','D','A','B'};
    char Y[Y_LEN+1] = {' ','B','D','C','A','B','A'};
    int c[X_LEN+1][Y_LEN+1]={0};
    int b[X_LEN+1][Y_LEN+1] = {0};
    int i,j;
    lcsLength(X,Y,c,b);

    for ( i = 1; i <= X_LEN; i++)
    {
        for ( j = 1; j <= Y_LEN; j++)
        { 
            printf("%d ",c[i][j]);
        }
        printf("\n");
        
    }
    printf("The length of LCS is:%d\n",c[X_LEN][Y_LEN]);
    printf("The longest of LCS is:");
    printLCS(b,X,X_LEN,Y_LEN);
    system("pause");
    
}