#include<stdio.h>
void main()
{
	int a[10],n,key,i;
	printf("\n Enter size of array : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	printf("%d",a[i]);
	printf("\n Enter element to search : ");
	scanf("%d",&key);
	for(i=0;i<n;i++)
	{
		if(key==a[i])
		printf("%d found at %d location",key,++i);
	}
}
