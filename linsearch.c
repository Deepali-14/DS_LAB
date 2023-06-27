#include<stdio.h>
int linsearch(int [],int,int);
void print(int [],int);
int main()
{
	int a[100],i,j,n,x,r;
	printf("\nEnter the number of elements in array : ");
	scanf("%d",&n);
	printf("\nEnter array : \n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("\nThe original array is : \n");
    print(a,n);
    printf("\nRead element to search : ");
    scanf("%d",&x);
	r=linsearch(a,n,x);
	if(r!=-999)
	printf("\n%d found %d times",x,r);
	else
    printf("\n%d not found",x);    
    return 0;
}
int linsearch(int a[], int n, int x)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			printf("\n%d found at location %d",x,i+1);
		    c++;	
		}
	    else
	    continue;
	}
	if(c==0)
	return -999;
	else
	return c;
}
void print(int a[],int n)
{
	int i;
    for(i=0;i<n;i++)
	printf("%d\t",a[i]);
}
