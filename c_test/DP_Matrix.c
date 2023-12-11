#include <stdio.h>
#include <stdlib.h>

#define N 6

void matrixOrder(int *p,int m[N+1][N+1],int s[N+1][N+1])
{
    int i,j,k,t;
    for ( i = 0; i <= N; i++)
    {
        m[i][i] = 0;
    }
    for ( t = 2; t <= N; t++)
    {
        for ( i = 1; i <= N-t+1; i++)
        {
            j = t+i-1;
            m[i][j] = INT_MAX;
            for ( k = i; k <= j-1; k++)
            {
               int temp = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
               if (temp < m[i][j])
               {
                    m[i][j] = temp;
                    s[i][j] = k;
               }
               
            }
            
        }
        
    }

}

void print_Order(int s[N+1][N+1],int i,int j)
{
    if (i == j)
    {   
       printf("A%d",i);
    }
    else
    {
        printf("(");
        print_Order(s,i,s[i][j]);
        print_Order(s,s[i][j]+1,j);
        printf(")");
    }
    
}

int main()
{
    int p[N+1] = {30,35,15,5,10,20,25};
    int m[N+1][N+1]={0};
    int s[N+1][N+1]={0};
    int i,j;
    matrixOrder(p,m,s);
    printf("The m of value is:\n");
    for ( i = 1; i <= N; i++)
    {
        for ( j = 1; j <= N; j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }

    printf("The s of value is:\n");
    for ( i = 1; i <= N; i++)
    {
        for ( j = 1; j <= N; j++)
        {
            printf("%d ",s[i][j]);
        }
        printf("\n");
    }
    printf("The result is:");
    print_Order(s,1,N);
    system("pause");
}