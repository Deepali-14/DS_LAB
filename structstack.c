#include<stdio.h>
#define max 7
struct s
{
	int info[max];
	int top;
}stack;
void init();
void push();
int pop();
void print();
int underflow();
int overflow();
int size();
int peek();
int main()
{
  int ch,n,y;
  stack.top=-1;
  do
  {
    printf("\n1.Push \n2.Pop \n3.Display \n4.Initilization \n5.Overflow \n6.Underflow \n7.Size \n8.Peek \n9.Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
            printf("\nEnter an element : ");
            scanf("%d",&n);
            push(n);
            break;
      case 2:
            y=(pop());
            if(y!=-999)
            printf("\nThe deleted element : %d",y);
            else
            printf("\nStack underflow");
            break;
      case 3:
            print();
            break;
      case 4:
            init();
            break;
      case 5:
            if (overflow())
            printf("\nStack overflow");
            else
            printf("\nStack is not overflow");
            break;
      case 6:
            if (underflow())
            printf("\nStack underflow");
            else
            printf("\nStack is not underflow");
            break;
      case 7:
            printf("\nThe size of the stack : %d",size());
            break;
      case 8:
            if(peek())
            printf("\nThe current element in the stack : %d",peek());
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
void init()
{
	stack.top==-1;
}
void push(int x)
{
	if(stack.top==max-1)
	printf("\nStack overflow");
	else
	{
       stack.top++;
       stack.info[stack.top]=x;
    }
}
int pop()
{
	int x;
	if(stack.top==-1)
       return -999;
    else
    {
       x=stack.info[stack.top];
       stack.top--;
       return x;
    }   
}
void print()
{
    int i;
    if(stack.top==-1)
    printf("\nThere is no element to display");
    else 
    {
       printf("\nSTACK : \n");
       for(i=stack.top;i>-1;i--)
       {
          printf("%d\t",stack.info[i]);
       }
    }
}
int overflow()
{
   if(stack.top==max-1)
       return 1;
   else
       return 0;
}
int underflow()
{
   if(stack.top==-1)
       return 1;
   else
       return 0;
}
int size()
{
   int y;
   if(stack.top==-1)
   return 0;
   else
   {
   	 y=stack.top+1;
     return y;
   }
}
int peek()
{
   if(stack.top==-1)
   return 0;
   else
   return stack.info[stack.top];
}

