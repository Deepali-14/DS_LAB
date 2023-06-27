#include<stdio.h>
void isort(int [],int);
void print(int [],int);
int main()
{
	int a[10],i,j,n;
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
	isort(a,n);
	print(a,n);
	return 0;
}
void isort(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=a[i];
		printf("\nkey=%d",key);
		for(j=i-1;(j>-1)&&(a[j]>key);j--)
		   a[j+1]=a[j];
		a[j+1]=key;
		printf("\ni=%d",i);
		printf("\nelement=%d",key);
		print(a,n);
    }
}
void print(int a[],int n)
{
	int i;
    printf("\nThe sorted array is : \n");
    for(i=0;i<n;i++)
    {
	    printf("%d\t",a[i]);
    }
}
