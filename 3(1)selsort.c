#include<stdio.h>
int main()
{
	int a[10],i,n,j,p,t;
	printf("\nEnter size of array : ");
	scanf("%d",&n);
	printf("\nEnter elements : ");
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);	
    printf("\nOriginal array : \n");
    for(i=0;i<n;i++)
	   printf("%d ",a[i]);
	for(i=0;i<n-1;i++)
	{
	   p=i;
	   for(j=i+1;j<n;j++)
	   {
	   	    if(a[p]>a[j])
	   	    p=j;
	   }
	   if(p!=i)
	   {
	   	    t=a[i];
	   	    a[i]=a[p];
	   	    a[p]=t;
	   }
    }
    printf("\nSorted array by selection sorting : \n");
    for(i=0;i<n;i++)
	   printf("%d ",a[i]);	
	return 0;
}
	

