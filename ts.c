#include<stdio.h>
#define max 10
int stack[max];
int t1=-1,t2=max/3-1,t3=max;
void init1();
void init2();
void init3();
void push1(int);
void push2(int);
void push3(int);
int pop1();
int pop2();
int pop3();
int underflow1();
int underflow2();
int underflow3();
int overflow1();
int overflow2();
int overflow3();
int size1();
int size2();
int size3();
int peek1();
int peek2();
int peek3();
void display1();
void display2();
void display3();
void main()
{
	
  int ch,x,r,t;
  do
  {
  	printf("\n %d",t1);
	printf("\n %d",t2);
	printf("\n %d",t3);
  	printf("\n ***** TRIPLE MULTIPLE STACK ***** \n");
    printf("\n Initialization \n 1. Stack 1 \n 2. Stack 2 \n 3. Stack 3 \n Push \n 4. Stack 1 \n 5. Stack 2 \n 6. Stack 3");
    printf("\n Pop \n 7. Stack 1 \n 8. Stack 2 \n 9. Stack 3 \n Underflow \n 10. Stack 1 \n 11. Stack 2 \n 12. Stack 3");
    printf("\n Overflow \n 13. Stack 1 \n 14. Stack 2 \n 15. Stack 3 \n Display \n 16. Stack 1 \n 17. Stack 2 \n 18. Stack 3");
    printf("\n Size \n 19. Stack 1 \n 20. Stack 2 \n 21. Stack 3 \n Peek \n 22. Stack 1 \n 23. Stack 2 \n 24. Stack 3 \n 0. Exit");
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
    		init3();
    		break;
    	case 4:
    		if(overflow1())
	        printf("\n The Stack 1 is full");
        	else
        	{
    	    	printf("\n Enter element to be inserted in Stack 1 : ");
    		    scanf("%d",&x);
    		    push1(x);
    	    }
    		break;
    	case 5:
    		if(overflow2())
        	printf("\n The Stack 2 is full");
	        else
	        {
    	    	printf("\n Enter element to be inserted in Stack 2 : ");
    	    	scanf("%d",&x);
    	    	push2(x);
        	}
    		break;
    	case 6:
    	if(overflow3())
	        printf("\n The Stack 3 is full");
        	else
        	{
    	    	printf("\n Enter element to be inserted in Stack 3 : ");
    		    scanf("%d",&x);
    		    push3(x);
    	    }
    		break;
    	case 7:
    		r=pop1();
    		if(r==-999)
    		printf("\n Stack 1 is empty");
    		else
    		printf("\n %d deleted from Stack 1",r);
    		break;
    	case 8:
    		r=pop2();
    		if(r==-999)
    	    printf("\n Stack 2 is empty");
    		else
    		printf("\n %d deleted from Stack 2",r);
    		break;
    	case 9:
    		r=pop3();
    		if(r==-999)
    	    printf("\n Stack 3 is empty");
    		else
    		printf("\n %d deleted from Stack 3",r);
    		break;
    	case 10:
    		if(underflow1())
    		printf("\n Stack 1 is empty");
    		else
    		printf(" \n Stack  1 is not empty");
    		break;
    	case 11:
    		if(underflow2())
    		printf("\n Stack 2 is empty");
    		else
    		printf(" \n Stack 2 is not empty");
    		break;
    	case 12:
    		if(underflow3())
    		printf("\n Stack 3 is empty");
    		else
    		printf(" \n Stack 3 is not empty");
    		break;
    	case 13:
    		if(overflow1())
    		printf("\n Stack 1 is full");
    		else
    		printf("\n Stack 1 is not full");
    		break;
    	case 14:
    		if(overflow2())
    		printf("\n Stack 2 is full");
    		else
    		printf("\n Stack 2 is not full");
    		break;
    	case 15:
    		if(overflow3())
    		printf("\n Stack 3 is full");
    		else
    		printf("\n Stack 3 is not full");
    		break;
    	case 16:
    		display1();
    		break;
    	case 17:
    		display2();
    		break;
    	case 18:
    		display3();
    		break;
    	case 19:
    		printf("\n The size of Stack 1 : %d",size1());
    		break;
    	case 20:
    		printf("\n The size of Stack 2 : %d",size2());
    		break;
    	case 21:
    		printf("\n The size of Stack 3 : %d",size3());
    		break;
    	case 22:
    		t=peek1();
    		if(t==-999)
    		printf("\n Stack 1 is empty");
    		else
    		printf("\n The peek of Stack 1 : %d",peek1());
    		break;
    	case 23:
    		t=peek2();
    		if(t==-999)
    		printf("\n Stack 2 is empty");
    		else
    		printf("\n The peek of Stack 2 : %d",peek2());
    		break;
    	case 24:
    		t=peek3();
    		if(t==-999)
    		printf("\n Stack 3 is empty");
    		else
    		printf("\n The peek of Stack 3 : %d",peek3());
    		break;
    	case 0:
    		printf("\n We are exiting..!");
    		break;
    	default:
    		printf("\n Wrong choice entered..!");	
	}
  }while(ch!=0);
}
void init1()
{
	t1=-1;
}
void init2()
{
	t2=max/3-1;
}
void init3()
{
	t3=max;
}
void push1(int x)
{
	stack[++t1]=x;
}
void push2(int x)
{
	stack[++t2]=x;
}
void push3(int x)
{
	stack[--t3]=x;
}
int pop1()
{
	int y;
	if(underflow1())
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
	if(underflow2())
	return -999;
	else
	{
		y=stack[t2--];
	    return y;
	}
}
int pop3()
{
	int y;
	if(underflow3())
	return -999;
	else
	{
		y=stack[t3++];
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
	if(t2==max/3-1)
	return 1;
	else
	return 0;
}
int underflow3()
{
	if(t3==max)
	return 1;
	else
	return 0;
}
int size1()
{
	if(underflow1())
	return 0;
	else 
	return (t1+1);
}
int size2()
{
	if(underflow2())
	return 0;
	else 
	return (t2-max/3+1);
}
int size3()
{
	if(underflow3())
	return 0;
	else 
	return (max-t3);
}
int peek1()
{
    if(underflow1())
	return -999;
	else 
	return (stack[t1]);
}
int peek2()
{
    if(underflow2())
	return -999;
	else 
	return (stack[t2]);
}
int peek3()
{
	if(underflow3())
	return -999;
	else 
	return (stack[t3]);
}
void display1()
{
	int i;
    if(underflow1())
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
	if(underflow2())
	printf("\n Stack 2 is empty");
	else
	{
		printf("\n The stack elements : \n");
		for(i=t2;i>max/3-1;i--)
    	printf("%d ",stack[i]);
	}
}
void display3()
{
	int i;
	if(underflow3())
	printf("\n Stack 3 is empty");
	else
	{
		printf("\n The stack elements : \n");
		for(i=t3;i<max;i++)
    	printf("%d ",stack[i]);
	}
}
int overflow1()
{
	if(t1==((max/3-1)))
	return 1;
	else
	return 0;
}
int overflow2()
{
	if(t2==(2*(max/3)-1))
	return 1;
	else
	return 0;
}
int overflow3()
{
	if(t3==2*(max/3))
	return 1;
	else
	return 0;
}
