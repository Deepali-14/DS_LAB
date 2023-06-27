#include<stdio.h>
#define max 50
int stack[max];
int top=-1;
void push(int *);
int pop();
void main()
{
    int n,r;
    printf("\nEnter decimal number : ");	
    scanf("%d",&n);
    while(n>0)
      push(&n);
    printf("\nCorresponding binary number : ");
    while(top>-1)
    {
    	r=pop();
    	printf("%d",r);
	}
}
void push(int *a)
{
	stack[++top]=*a%2;
	*a=*a/2;
}
int pop()
{
	int x;
	x=stack[top--];
	return x;
}
