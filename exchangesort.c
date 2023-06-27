#include<stdio.h>
void esort(int [],int);
int main()
{
	int a[10],i,n;
	printf("\nEnter the number of elements in array : ");
	scanf("%d",&n);
	printf("\nEnter array : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nThe original array is : \n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	esort(a,n);
	printf("\nThe sorted array after exchange sorting is : \n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	return 0;
}
void esort(int a[],int n)
{
	int i,j,t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		if(a[i]<a[j])
		{
			t=a[i];
		    a[i]=a[j];
		    a[j]=t;
		}
	}
}
