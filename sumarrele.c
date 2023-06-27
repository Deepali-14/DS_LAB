#include<stdio.h>
void bsort(int [],int);
void print(int [],int);
int sum(int [], int);
int main()
{
	int a[100],i,n,r;
	printf("\nEnter the number of elements in array : ");
	scanf("%d",&n);
	printf("\nEnter array : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nThe original array is : \n");
    print(a,n);
    r=sum(a,n);
    printf("\nThe sum of array elements is %d",r);
    return 0;
}
int sum(int b[], int p)
{
	int s=0,i;
	for(i=0;i<p;i++)
		s=s+b[i];
	return s;
}
void print(int a[],int n)
{
	int i;
    for(i=0;i<n;i++)
    {
	    printf("%d\t",a[i]);
    }
}
