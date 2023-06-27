#include<stdio.h>
#define max 50
void push(int [],int *,int *);
int pop(int [],int *);
void main()
{
    int n,r;
    int stack[max];
    int top=-1;
    printf("\nEnter decimal number : ");	
    scanf("%d",&n);
    while(n>0)
      push(stack,&top,&n);
    printf("\nCorresponding binary number : ");
    while(top>-1)
    {
    	r=pop(stack,&top);
    	printf("%d",r);
	}
}
void push(int stack[],int *top,int *a)
{
	stack[++(*top)]=*a%2;
	*a=*a/2;
}
int pop(int stack[],int *top)
{
	int x;
	x=stack[(*top)--];
	return x;
}
