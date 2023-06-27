#include<stdio.h>

#define max 20

void linearsrch(int [],int,int);

void main()
{
	int a[max],n,key,i;
	
	printf("\n Enter size of array : ");
	scanf("%d",&n);
	
	printf("\n Enter elements: \n");
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
	
	printf("\n Array : \n");
	for(i=0;i<n;i++)
	   printf("%d ",a[i]);
	printf("\n");
	
	printf("\n Enter element to search : ");
	scanf("%d",&key);
	
	linearsrch(a,n,key);
}

void linearsrch(int a[],int n,int x)
{
	int i,flag=0;
	
	for(i=0;i<n;i++)
	{
		if(x==a[i])
		{
			printf("\n %d found at location %d",x,i);
		    flag++;
		}
	}
	
	if(flag!=0)
	printf("\n %d found %d times",x,flag);
	
	else
	printf("\n %d not found",x);
}
