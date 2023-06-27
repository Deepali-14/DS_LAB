#include<stdio.h>
int main()
{
    int a[10],b[10],i,j,n;
    printf("\nEnter number of elements in array : ");
    scanf("%d",&n);
    printf("\nEnter elements : ");
    for (i=0;i<n;i++)
      scanf("%d",&a[i]);
    printf("\nOriginal array : \n");
    for (i=0;i<n;i++) 
      printf("%d\t",a[i]);
    for (i=0,j=n-1;i<n;i++,j--)
      b[j]=a[i];
    printf("\nReversed array : \n");
    for(j=0;j<n;j++)
      printf("%d\t",b[j]);
    return 0;
}
