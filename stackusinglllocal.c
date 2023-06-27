#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node stack;
stack * createnode(int);
stack * init(stack *top);
stack * push(stack *top,int);
stack * pop(stack *top);
void display(stack *top);
int size(stack *top);
int peek(stack *top);
int underflow(stack *top);
void main()
{
	stack *top=NULL;
	int ch,x;
	do
	{
		printf("\n 1. Push \n 2. Pop \n 3. Underflow \n 4. Initialization \n 5. Size \n 6. Peek \n 7. Display \n 8. Exit");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n Enter element to push : ");
				scanf("%d",&x);
			    top=push(top,x);
			    break;
			case 2:
				top=pop(top);
			    break;
			case 3:
				if(underflow(top))
				printf("\n Stack underflow");
				else
				printf("\n Stack is not underflow");
			    break;
			case 4:
				top=init(top);
			    break;
			case 5:
				if(size(top)==-999)
				printf("\n Size of stack : 0");
				else
				printf("\n Size of stack : %d",size(top));
			    break;
			case 6:
				if(peek(top)==-999)
				printf("\n Stack underflow");
				else
				printf("\n Peek of stack : %d",peek(top));
			    break;
			case 7:
				display(top);
			    break;
			case 8:
				printf("\n Exiting...");
			    break;
			default:
				printf("\n Wrong choice entered");
		}
	}while(ch!=8);
}
stack * init(stack *top)
{
	top=NULL;
	return top;
}
stack * createnode(int x)
{
	stack * temp;
	temp=(stack *)malloc(sizeof(stack));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
stack * push(stack *top,int x)
{
	stack *temp;
	temp=createnode(x);
	if(top==NULL)
	{
		top=temp;
		return top;
	}
	else
	{
		temp->next=top;
		top=temp;
		return top;
	}
}
stack * pop(stack *top)
{
	int x;
	stack *p;
	if(top==NULL)
    {
    	printf("\n Stack underflow");
    	return top;
	}
	else
	{
		p=top;
		x=top->data;
		printf("%d popped",x);
		top=p->next;
		free(p);
		return top;
	}
}
int underflow(stack *top)
{
	if(top==NULL)
	return 1;
	else
	return 0;
}
int size(stack *top)
{
	int c=0;
	stack *p;
	if(top==NULL)
	return 0;
	else
	{
		for(p=top;p!=NULL;p=p->next)
		c++;
		return c;
	}
}
int peek(stack *top)
{
	if(top==NULL)
	return -999;
	else
	return top->data;
}
void display(stack *top)
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
