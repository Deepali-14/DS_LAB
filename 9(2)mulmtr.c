#include<stdio.h>
int main()
{
    int r,c,i,j,k,a[10][10],b[10][10],m[10][10];
    printf("\nEnter rows and columns of square matrix : ");
    scanf("%d%d",&r,&c);
    printf("\nEnter matrix 1 elements : ");
    for(i=0;i<r;i++)
      for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);
    printf("\nMatrix 1 : \n");
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        printf("%d ",a[i][j]);
      printf("\n");
    }
    printf("\nEnter matrix 2 elements : ");
    for(i=0;i<r;i++)
      for(j=0;j<c;j++)
        scanf("%d",&b[i][j]);
     printf("\nMatrix 2 : \n");
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        printf("%d ",b[i][j]);
      printf("\n");
    }
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
      {
        m[i][j]=0;
        for(k=0;k<c;k++)
          m[i][j]+=a[i][k]*b[k][j];
      }
    }
    printf("\nMultiplication of matrix 1 and matrix 2 : \n");
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
        printf("%d ",m[i][j]);
      printf("\n");
    }
    return 0;
}
