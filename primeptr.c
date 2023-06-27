#include<stdio.h>
char * primecheck(int);
void main()
{
	int n;
	printf("\nEnter a number : ");
	scanf("%d",&n);
	printf("\nIf its prime print Yes else print No\n");
	printf("%s",primecheck(n));
}
char * primecheck(int p)
{
	int n;
	for(n=2;n<=p/2;n++)
	{
		if(p%n==0)
		return "No";	
	}
	return "Yes";	
}
