#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 50
char stk[max];
int top=-1;
void push(char);
int pop();
int prec(char);
void main()
{
	char exp[max],pre[max];
	int i,j=0,k;
	char ch;
	printf("\nEnter Infix expression : ");
	gets(exp);
	strrev(exp);
	for(i=0;exp[i]!='\0';i++)
	{
		ch=exp[i];
		if(ch=='['||ch=='{')
		ch='(';
		else if(ch==']'||ch=='}')
		ch=')';
		if(isalpha(ch))
	    pre[j++]=ch;
	    else if(ch==')')
	    push(ch);
	    else if(ch=='(')
	    {
	    	while(stk[top]!=')')
	    	pre[j++]=pop();
	    	top--;
		}
		else
		{
			for(k=top;((k>-1) && (stk[k]!=')') && (prec(stk[top])>prec(ch)));k--)
			pre[j++]=pop();
			push(ch);
		}
	}
	while(top>-1)
	pre[j++]=pop();
	pre[j]='\0';
	strrev(pre);
	printf("\nCorresponding prefix expression : ");
	puts(pre);
}
void push(char ch)
{
	stk[++top]=ch;
}
int pop()
{
	int x;
	x=stk[top--];
	return x;
}
int prec(char x)
{
	if(x=='^')
	return 9;
	else if(x=='*'||x=='/')
	return 7;
	else if(x=='+'||x=='-')
	return 5;
}
