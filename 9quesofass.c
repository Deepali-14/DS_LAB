#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max 20
int expvalid (char []);
void intopost (char []);
double evaluate (char[]);
int pre(char);
void push (int);
char pull ();
char st[max];
int top=-1;
void main()
{
	char exp[max],*t;
	int r;
	printf("\nEnter an expression : ");
	gets(exp);
	r=expvalid(exp);
	if(r==1)
	{
       printf("\nThe expression is valid...!");
       intopost(exp);
    }
	else
	printf("\nThe expression is not valid...!");
}
int expvalid (char a[])
{
	char ch,opr=0,opd=0;
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		ch=a[i];
		if(isalpha(ch))
		opd++;
		else if (ch=='(' ||ch=='{' || ch=='[')  
		push(ch);
		else if (ch==')'||ch=='}' || ch==']')
		{
          if (top==-1)
          break;
          else
          {
            if ((st[top]=='(' && ch==')')|| (st[top]=='{' && ch=='}' ) || (st[top]=='[' && ch==']')) 
            pull();
            else
            break;
          }
        }
        else
        opr++;
        if (!(opd>=opr))
        break;
	}
	printf("\nOperands = %d and Operators = %d",opd,opr);
    if (top==-1 && a[i]=='\0' && opd==(opr+1) )
    return 1;
    else 
    return 0;
}
void intopost (char b[])
{
	int i,j=0,k;
	double res;
	char ch,post[max];
    for(i=0;b[i]!='\0';i++)
    {
     ch=b[i];      
	 if(ch=='['||ch=='{') 
	    ch='(';
	 else if(ch==']'||ch=='}') 
	    ch=')';
     if (isalpha(ch))
     post[j++]=ch;
     else if (ch=='(')
     push(ch);
     else if (ch==')')
     {
       while(st[top]!='(')
       post[j++]=pull();
       top--;
     }
     else
     { 
       for(k=top;(k>-1 && st[k] !='(' && pre(ch)<=pre(st[k]));k--)
       post[j++]=pull();
       push(ch);
     }
   }
   while(top>-1)
   post[j++]=pull();
   post[j]='\0';
   printf("\nFinal postfix expression : ");
   puts(post);
   res = evaluate (post);
   printf("\nFinal evaluated postfix expression : %lf",res);
}
int pre(char x)
{
  if (x=='^')
  return 9;
  else if (x=='*'|| x=='/')
  return 7;
  else if (x=='+'|| x=='-')
  return 5;
}
double evaluate (char c[])
{
   int i;
   char ch;
   double temp,op1,op2;
   for(i=0;c[i]!='\0';i++)  
   {
     ch=c[i];    
     if (isalpha(ch))
     {
       printf("\nRead value of %c : ",ch);  
       scanf ("%lf",&temp); 
       push(temp);
     }
     else
     {
       op1=pull(); 
       op2=pull(); 
       switch(ch)
       {
         case '+': push(op2+op1); 
		           break; 
         case '-': push(op2-op1);  
		           break; 
         case '*': push(op2*op1);  
		           break;   
         case '/': push(op2/op1);  
		           break;
         case '^': push(pow(op2,op1)); 
		           break;  
       }     
     }
   }
   return (pull());
}
void push(int x)
{
	++top;
	st[top]=x;
}
char pull()
{
	char x;
	x=st[top--];
	return x;
}
