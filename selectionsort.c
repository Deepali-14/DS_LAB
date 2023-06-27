#include<stdio.h>
void ssort(int [],int);
int main()
{
	int a[10],i,n;
	printf("\nEnter the number of elements in array : ");
	scanf("%d",&n);
	printf("\nEnter array : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nThe original array is : \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	ssort(a,n);
	printf("\nThe sorted array after selection sorting is : \n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
}
void ssort(int a[],int n)
{
	int i,j,min,t;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		  if(a[min]>a[j])
		    min=j;
		t=a[i];
		a[i]=a[min];
		a[min]=t;
	}
}
