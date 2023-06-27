#include<stdio.h>

#define max 100

int binsearch(int [],int,int);

void print(int [],int);

int main()
{
	int a[max],i,j,n,x,r;
	
	printf("\nEnter the number of elements in array : ");
	scanf("%d",&n);
	
	printf("\nEnter array in descending order : \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	printf("\nThe original array is : \n");
    print(a,n);
    
	printf("\nRead element to search : ");
    scanf("%d",&x);
    
	r=binsearch(a,n,x);
	
	if(r!=-999)
	    printf("\n%d found at location %d",x,r);
	else
    	printf("\n%d not found",x);    
    
	return 0;
}

int binsearch(int a[], int n, int x)
{
	int l=0,h=n-1,m;
	
	do
	{
		m=(l+h)/2;
		if(x>a[m])
		  h=m-1;
		else if(x<a[m])
		  l=m+1;
		else
		  return m;	
	}while(l<=h);
	
	return -999;
}

void print(int a[],int n)
{
	int i;
    
	for(i=0;i<n;i++)
	    printf("%d\t",a[i]);
}
