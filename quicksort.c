#include<stdio.h>
void quicksort(int [], int, int);
int partition(int [], int, int);
void swap(int *, int *);
void read(int[],int);
void print(int[],int);
void main()
{
	int n;
	int a[50];
	printf("\nEnter number of elements in the array : ");
	scanf("%d",&n);
	printf("\nEnter the elements : \n");
	read(a,n);
	printf("\nThe unsorted array : \n");
	print(a,n);
	quicksort(a,0,n-1);
	printf("\nThe sorted array : \n");
	print(a,n);
}
void quicksort(int b[], int low, int high)
{
	int pi;
	if(low<high)
	{
		pi=partition(b,low,high);
		quicksort(b,low,pi-1);
		quicksort(b,pi+1,high);
	}
}
int partition(int c[], int low, int high)
{
	int pivot,i,j;
	pivot=c[high];
	i=low-1;
	for(j=low;j<high;j++)
	{
		if(c[j]<pivot)
		{
			i++;
			if(i!=j)
			swap(&c[i],&c[j]);
		}
	}
	swap(&c[i+1],&c[high]);
	return (i+1);
}
void swap(int *a, int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void read(int d[],int n)
{
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&d[i]);
}
void print(int d[],int n)
{
	int i;
	for(i=0;i<n;i++)
	printf("%d\t",d[i]);
	printf("\n");
}
