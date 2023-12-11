#include <stdio.h>
#include <stdlib.h>

#define N 6

void fastest_way(int a[][N],int t[][N-1],int e[],int x[],int f[][N],int l[][N],int n);
void print_station(int l[][N],int last_l,int n);
void print_station_recursive();
//ȫ�ֱ�����last_t��ʾ���ʱ��,last_l��ʾ���һ��װ��վ���ڵ�װ���߱��
int last_f,last_l;

int main()
{
    int a[2][6] = {{7,9,3,4,8,4},{8,5,6,4,5,7}};
    int t[2][5] = {{2,3,1,3,4},{2,1,2,2,1}};
    int f[2][6] = {0};
    int l[2][6] = {0};
    int e[2] = {2,4};
    int x[2] = {3,2};
    int i,j;
    fastest_way(a,t,e,x,f,l,6);
    //��ӡ�������װ�����ϸ���װ��վִ�е����ʱ��
    for(i=0;i<2;++i)
    {
        printf("f%d is: ",i+1);
        for(j=0;j<6;++j)
          printf("%d ",f[i][j]);
        printf("\n");
    }
    printf("last_f is: %d\nlast_l is: %d\n",last_f,last_l);
    for(i=0;i<2;++i)
    {
        printf("l%d is: ",i+1);
        for(j=0;j<6;++j)
          printf("%d ",l[i][j]);
        printf("\n");
    }
    print_station(l,last_l,6);
    printf("output sequence by recursive.\n");
    print_station_recursive(l,last_l,6);
    system("pause");
}

void fastest_way(int a[][N],int t[][N-1],int e[],int x[],int f[][N],int l[][N],int n)
{
    int i,j;
    f[0][0] = e[0] + a[0][0];
    f[1][0] = e[1] + a[1][0];
    l[0][0] = 1;
    l[1][0] = 2;
    for(j=1;j<n;j++)
    {
        if(f[0][j-1] < f[1][j-1] + t[1][j-1])
        {
            f[0][j] = f[0][j-1] + a[0][j];
            l[0][j] = 1;
        }
        else
        {
            f[0][j] = f[1][j-1] + t[1][j-1] + a[0][j];
            l[0][j] = 2;
        }
        if(f[1][j-1] < f[0][j-1] + t[0][j-1])
        {
            f[1][j] = f[1][j-1] + a[1][j];
            l[1][j] = 2;
        }
        else
        {
            f[1][j] = f[0][j-1] + t[0][j-1] + a[1][j];
            l[1][j] = 1;
        }
    }
    if(f[0][n-1] + x[0] < f[1][n-1] + x[1])
    {
        last_f = f[0][n-1] + x[0];
        last_l = 1;
    }
    else
    {
        last_f = f[1][n-1] + x[1];
        last_l = 2;
    }
}

void print_station(int l[][N],int last_l,int n)
{
    int i = last_l;
    int j;
    printf("line %d,station %d\n",i,n);
    for(j=n-1;j>0;--j)
    {
        i = l[i-1][j];
        printf("line %d,station %d\n",i,j);
    }
}
void print_station_recursive(int l[][N],int last_l,int n)
{
    int i = last_l;
    if(n == 1)
        printf("line %d,station %d\n",i,n);
    else
    {
         print_station_recursive(l,l[i-1][n-1],n-1);
         printf("line %d,station %d\n",i,n);
    }

}