#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define max 30
void push(double);
double pop();
double stk[max];
int top=-1;
void main()
{
	char post[max],ch;
	int i;
	double op1,op2,n;
	printf("\nEnter a valid postfix expression : ");
	gets(post);
	for(i=0;post[i]!='\0';i++)
	{
		ch=post[i];
		if(isalpha(ch))
		{
			printf("\nRead value of %c : ",ch);
			scanf("%lf",&n);
			push(n);
		}
		else
		{
			op1=pop();
			op2=pop();
			switch(ch)
			{
				case '+' :  push(op2+op1);
				            break;
				case '-' :  push(op2-op1);
				            break;
				case '*' :  push(op2*op1);
				            break;
				case '/' :  push(op2/op1);
				            break;
				case '^' :  push(pow(op2,op1));
				            break;
			}
		}
	}
	printf("\nThe final evaluated postfix expression : %lf",pop());
}
void push(double n)
{
	stk[++top]=n;
}
double pop()
{
	double x;
	x=stk[top--];
	return x;
}
