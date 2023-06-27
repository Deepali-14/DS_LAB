#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define max 30
void push(double);
double pop();
double stk[max];
int top=-1;
void main()
{
	char pre[max],ch;
	int i;
	double op1,op2,n;
	printf("\nEnter a valid postfix expression : ");
	gets(pre);
	strrev(pre);
	for(i=0;pre[i]!='\0';i++)
	{
		ch=pre[i];
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
				case '+' :  push(op1+op2);
				            break;
				case '-' :  push(op1-op2);
				            break;
				case '*' :  push(op1*op2);
				            break;
				case '/' :  push(op1/op2);
				            break;
				case '^' :  push(pow(op1,op2));
				            break;
			}
		}
	}
	printf("\nThe final evaluated prefix expression : %lf",pop());
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
