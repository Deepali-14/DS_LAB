#include<stdio.h>
#define max 8
int stack[max];
int t1=-1,t2=max;
void init1();
void init2();
void push1(int);
void push2(int);
int pop1();
int pop2();
int underflow1();
int underflow2();
int overflow();
int size1();
int size2();
int peek1();
int peek2();
void display1();
void display2();
void main()
{
  int ch,x,y,r,s,t,u;
  do
  {
    printf("\n 1. Initialization of Stack 1 \n 2. Initialization of Stack 2 \n 3. Push in Stack 1 \n 4. Push in Stack 2");
 	printf("\n 5. Display Stack 1 \n 6. Display Stack 2 \n 7. Pop from Stack 1 \n 8. Pop from Stack 2");
 	printf("\n 9. Is Stack 1 Underflow \n 10. Is Stack 2 Underflow \n 11. Overflow \n 12. Size of Stack 1");
 	printf("\n 13. Size of Stack 2 \n 14. Peek of Stack 1 \n 15. Peek of Stack 2 \n 16. Exit");
    printf("\n Enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1:
    		init1();
    		break;
    	case 2:
    		init2();
    		break;
    	case 3:
    		if(t2==(t1+1))
	        printf("\n The Stack is full");
        	else
        	{
    	    	printf("\n Enter element to be inserted in Stack 1 : ");
    		    scanf("%d",&x);
    		    push1(x);
    	    }
    		break;
    	case 4:
    		if(t2==(t1+1))
        	printf("\n The Stack is full");
	        else
	        {
    	    	printf("\n Enter element to be inserted in Stack 2 : ");
    	    	scanf("%d",&x);
    	    	push2(x);
        	}
    		break;
    	case 5:
    		display1();
    		break;
    	case 6:
    		display2();
    		break;
    	case 7:
    		r=pop1();
    		if(r==-999)
    		printf("\n Stack 1 is empty");
    		else
    		printf("\n %d deleted from Stack 1",r);
    		break;
    	case 8:
    		s=pop2();
    		if(s==-999)
    	    printf("\n Stack 2 is empty");
    		else
    		printf("\n %d deleted from Stack 2",s);
    		break;
    	case 9:
    		if(underflow1())
    		printf("\n Stack 1 is empty");
    		else
    		printf(" \n Stack  1 is not empty");
    		break;
    	case 10:
    		if(underflow2())
    		printf("\n Stack 2 is empty");
    		else
    		printf(" \n Stack 2 is not empty");
    		break;
    	case 11:
    		if(overflow())
    		printf("\n Stack is full");
    		else
    		printf("\n Stack is not full");
    		break;
    	case 12:
    		if(size1())
    		printf("\n The size of Stack 1 : %d",size1());
    		else
    		printf("\n The size of Stack 1 : 0");
    		break;
    	case 13:
    		if(size2())
    		printf("\n The size of Stack 2 : %d",size2());
    		else
    		printf("\n The size of Stack 2 : 0");
    		break;
    	case 14:
    		t=peek1();
    		if(t==-999)
    		printf("\n Stack 1 is empty");
    		else
    		printf("\n The peek of Stack 1 : %d",peek1());
    		break;
    	case 15:
    		u=peek2();
    		if(u==-999)
    		printf("\n Stack 2 is empty");
    		else
    		printf("\n The peek of Stack 2 : %d",peek2());
    		break;
    	case 16:
    		printf("\n We are exiting");
    		break;
    	default:
    		printf("\n Wrong choice entered!!!");	
	}
  }while(ch!=16);
}
void init1()
{
	t1=-1;
}
void init2()
{
	t2=max;
}
void push1(int x)
{
	stack[++t1]=x;
}
void push2(int x)
{
	stack[--t2]=x;
}
int pop1()
{
	int y;
	if(t1==-1)
	return -999;
	else
	{
		y=stack[t1--];
	    return y;
	}
}
int pop2()
{
	int y;
	if(t2==max)
	return -999;
	else
	{
		y=stack[t2++];
	    return y;
	}
}
int underflow1()
{
	if(t1==-1)
	return 1;
	else
	return 0;
}
int underflow2()
{
	if(t2==max)
	return 1;
	else
	return 0;
}
int size1()
{
	if(t1==-1)
	return 0;
	else 
	return (t1+1);
}
int size2()
{
	if(t2==max)
	return 0;
	else 
	return (max-t2);
}
int peek1()
{
	if(t1==-1)
	return -999;
	else 
	return (stack[t1]);
}
int peek2()
{
	if(t2==max)
	return -999;
	else 
	return (stack[t2]);
}
void display1()
{
	int i;
	if(t1==-1)
	printf("\n Stack 1 is empty");
	else
	{
		printf("\n The stack elements : \n");
		for(i=t1;i>-1;i--)
    	printf("%d ",stack[i]);
	}
}
void display2()
{
	int i;
	if(t2==max)
	printf("\n Stack 2 is empty");
	else
	{
		printf("\n The stack elements : \n");
		for(i=t2;i<max;i++)
    	printf("%d ",stack[i]);
	}
}
int overflow()
{
	if(t2==(t1+1))
	return 1;
	else
	return 0;
}
