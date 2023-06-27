#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node stack;
stack *top=NULL;
stack * createnode();
void init();
void display();
void push();
int pop();
int size();
int peek();
int underflow();
void main()
{
	int n,ch,a,b,c,d;
	do
	{
		printf("\n 1. Initialization \n 2. Push \n 3. Pop \n 4. Display \n 5. Underflow \n 6. Size \n 7. Peek \n 8. Exit");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
			    init();
			    break;
			case 2: 
			    printf("\n Enter element to push : ");
			    scanf("%d",&n);
			    push(n);
			    break;
			case 3: 
			    a=pop();
			    if(a!=-999)
			    printf("\n Deleted element : %d",a);
			    else
			    printf("\n Stack underflow");
			    break;
			case 4: 
			    display();
			    break;
			case 5: 
			    b=underflow();
			    if(b==1)
			    printf("\n Stack underflow");
			    else
			    printf("\n Stack is not underflow");
			    break;
			case 6: 
			    c=size();
			    if(c!=-999)
			    printf("\n Stack size : %d",c);
			    else
			    printf("\n Stack size : 0");
			    break;
			case 7: 
			    d=peek();
			    if(d!=-999)
			    printf("\n Stack peek : %d",d);
			    else
			    printf("\n Stack underflow");
			    break;
			case 8: 
			    printf("\n Exiting");
			    break;
			default: 
			    printf("\n Wrong choice entered");
		}
	}while(ch!=8);
}
void init()
{
	top=NULL;
}
stack * createnode(int x)
{
	stack *temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void push(int x)
{
	stack *temp;
	temp=createnode(x);
	if(top==NULL)
	{
	    top=temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}
int pop()
{
	int x;
	stack *p;
	if(top==NULL)
	return -999;
	else
	{
		p=top;
		x=p->data;
		top=p->next;
		free(p);
		return x;
	}
}
void display()
{
	stack *p;
	if(top==NULL)
	printf("\n Stack underflow");
	else
	{
		printf("\n Stack : \n");
	    for(p=top;p!=NULL;p=p->next)
	    {
		   printf("%d ",p->data);
	    }
	}
}
int underflow()
{
	if(top==NULL)
	return 1;
	else
	return 0;
}
int size()
{
	int i;
	stack *p;
	if(top==NULL)
	return -999;
	else
	{
		for(p=top,i=1;p->next!=NULL;i++,p=p->next);
		return i;
	}
}
int peek()
{
	if(top==NULL)
	return -999;
	else
	return top->data;
}
