#include<stdio.h>
int main()
{
    int m,n,i,j,a[10][10],b[10][10],c[10][10];
    printf("\nEnter rows and columns of matrix : ");
    scanf("%d%d",&m,&n);
    printf("\nEnter matrix 1 elements : ");
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    printf("\nMatrix 1 : \n");
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
      printf("\n");
    }
    printf("\nEnter matrix 2 elements : ");
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        scanf("%d",&b[i][j]);
     printf("\nMatrix 2 : \n");
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
        printf("%d ",b[i][j]);
      printf("\n");
    }
    for(i=0;i<m;i++)
      for(j=0;j<n;j++)
        c[i][j]=a[i][j]+b[i][j];
    printf("\nSum of matrix 1 and matrix 2 : \n");
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
        printf("%d ",c[i][j]);
      printf("\n");
    }
    return 0;
}
