#include<stdio.h>
#define max 5
void init(int *);
void push(int [],int *,int);
int pop(int [],int *);
void print(int [],int *);
int underflow(int *);
int overflow(int *);
int size(int *);
int peek(int [],int *);
int main()
{
  int ch,n,y,top=-1;
  int stk[max];
  do
  {
    printf("\n1.Push \n2.Pop \n3.Display \n4.Initialization \n5.Overflow \n6.Underflow \n7.Size \n8.Peek \n9.Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
            printf("\nEnter an element : ");
            scanf("%d",&n);
            push(stk,&top,n);
            break;
      case 2:
            y=(pop(stk,&top));
            if(y!=-999)
            printf("\nThe deleted element : %d",y);
            else
            printf("\nStack underflow");
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
            if(peek(stk,&top))
            printf("\nThe current element in the stack : %d",peek(stk,&top));
            else
            printf("\nThere is no element to display");
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
void push(int stk[],int *top,int x)
{
	if(*top==max-1)
	printf("\nStack overflow");
	else
	{
       (*top)++;
       stk[*top]=x;
    }
}
int pop(int stk[],int *top)
{
	int x;
	if(*top==-1)
       return -999;
    else
    {
       x=stk[*top];
       (*top)--;
       return x;
    }   
}
void print(int stk[],int *top)
{
    int i;
    if(*top==-1)
    printf("\nThere is no element to display");
    else 
    {
       printf("\nSTACK : \n");
       for(i=*top;i>-1;i--)
       {
          printf("%d\t",stk[i]);
       }
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
   y=*top+1;
   return y;
}
int peek(int stk[],int *top)
{
   if(*top==-1)
   return 0;
   else
   return stk[*top];
}
