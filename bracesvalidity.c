#include<stdio.h>
#include<ctype.h>
#define max 50
int stk[max];
int top=-1;
void push(char);
void pop();
void main()
{
	char exp[max];
	int i,opr=0,opd=0;
	char ch;
	printf("\nEnter the expression : ");
	gets(exp);
	for(i=0;exp[i]!='\0';i++)
	{
	    ch=exp[i];	
	    printf("\nexp=%c",ch);
	    if(ch=='('||ch=='{'||ch=='[')
	    push(ch);
	    else if(isalpha(ch))
	    opd++;
	    else if(ch==')'||ch=='}'||ch==']')
	    {
	    	if(top==-1)
	    	break;
	    	else
	    	{
	    		if(stk[top]=='('&&ch==')'||stk[top]=='['&&ch==']'||stk[top]=='{'&&ch=='}')
	    		pop();
	    		else 
	    		break;
			}
		}
	    else 
	    opr++;
	}
	printf("\nOperand = %d and operator = %d",opd,opr);
	printf("\ntop=%d",top);
	if((top==-1)&&(exp[i]=='\0')&&(opd==opr+1))
	printf("\nYour expression is valid...!");
	else
	printf("\nYour expression is not valid...!");
}
void push(char ch)
{
	stk[++top]=ch;
}
void pop()
{
	int x;
	x=stk[top--];
}
