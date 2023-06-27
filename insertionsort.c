#include<stdio.h>

void read(int [],int);

void print(int [],int);

void isort(int [],int);

int main()
{
	int a[10],n;
	
	printf("\n Enter the number of elements in array : ");
	scanf("%d",&n);

    read(a,n);
    
	printf("\n Unsorted array : \n");
    print(a,n);
	
	isort(a,n);
	
	printf("\n Sorted array after insertion sort : \n");
	print(a,n);
	
	return 0;
}

void read(int a[],int n)
{
	int i;
	
	printf("\n Enter array : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void print(int a[],int n)
{
	int i;
	
    for(i=0;i<n;i++)
	    printf("%d ",a[i]);
    printf("\n");
}

void isort(int a[],int n)
{
	int i,j,key;
	
	for(i=1;i<n;i++)
	{
		key=a[i];
		
		for(j=i-1;(j>-1)&&(a[j]>key);j--)
		   a[j+1]=a[j];
		a[j+1]=key;
    }
}
