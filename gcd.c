#include<stdio.h>
int gcd(int,int);
int main()
{
	int m,n,r;
	printf("\nEnter two numbers : ");
	scanf("%d %d",&m,&n);
	r=gcd(m,n);
	printf("\nThe gcd of the numbers is %d",r);
	return 0;
}
int gcd(int p,int q)
{
	if (q==0)
	return p;
	else
	return gcd(q,p%q);
}
