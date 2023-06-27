#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#define max 25
void init(int *);
void push(char [][max],int *,char []);
char * pop(char [][max],int *);
void print(char [][max],int *);
int underflow(int *);
int overflow(int *);
int size(int *);
void peek(char [][max],int *);
int main()
{
  int ch,top=-1;
  char * y;
  char s[max];
  char stk[max][max];
  do
  {
    printf("\n1.Push \n2.Pop \n3.Display \n4.Initialization \n5.Overflow \n6.Underflow \n7.Size \n8.Peek \n9.Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
            printf("\nEnter element to be inserted : ");
            fflush(stdin);
            gets(s);
            push(stk,&top,s);
            break;
      case 2:
            y=pop(stk,&top);
            printf("\nThe deleted element : ");
            puts(y);
            break;
      case 3:
            print(stk,&top);
            break;
      case 4:
            init(&top);
            break;
      case 5:
            if (overflow(&top))
            printf("\nStack overflow");
            else
            printf("\nStack is not overflow");
            break;
      case 6:
            if (underflow(&top))
            printf("\nStack underflow");
            else
            printf("\nStack is not underflow");
            break;
      case 7:
            printf("\nThe size of the stack : %d",size(&top));
            break;
      case 8:
            peek(stk,&top);
            break;
      case 9:
            printf("\nExiting....");
            break;
      default:
            printf("\nWrong choice");
    }
  }while(ch!=9);
  return 0;
}
void init(int *top)
{
    *top=-1;
}
void push(char stk[][max],int *top,char st[])
{
	if(*top==max-1)
	printf("\nStack overflow");
	else
	{
       (*top)++;
       strcpy(stk[*top],st);
    }
}
char * pop(char stk[][max],int *top)
{
	char *x;
	x=(char *)malloc(sizeof(char)*max);
	if(*top==-1)
    {
    	printf("\nStack underflow");
    	strcpy(x,"No element");
    	return x; 
	}
    else
    {
       strcpy(x,stk[*top]);
       (*top)--;
       return x; 
    }  
}
void print(char stk[][max],int *top)
{
    int i;
    if(*top==-1)
    printf("\nThere is no element to display");
    else 
    {
       printf("\nSTACK : \n");
       for(i=*top;i>-1;i--)
       puts(stk[i]);
    }
}
int overflow(int *top)
{
   if(*top==max-1)
       return 1;
   else
       return 0;
}
int underflow(int *top)
{
   if(*top==-1)
       return 1;
   else
       return 0;
}
int size(int *top)
{
   int y;
   if(*top==-1)
   return 0;
   y=*top+1;
   return y;
}
void peek(char stk[][max],int *top)
{
	if(*top==-1)
	printf("\nStack underflow");
	else
	{
		printf("\nThe peek of linear queue : ");
		puts(stk[*top]);
	}
}
