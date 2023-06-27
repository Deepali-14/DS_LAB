#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node lq;
lq *f=NULL,*r=NULL;
lq * createnode();
void init();
void display();
void enqueue();
int dequeue();
int size();
int peek();
int underflow();
void main()
{
	int n,ch,a,b,c,d;
	do
	{
		printf("\n 1. Initialization \n 2. Enqueue \n 3. Dequeue \n 4. Display \n 5. Underflow \n 6. Size \n 7. Peek \n 8. Exit");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
			    init();
			    break;
			case 2: 
			    printf("\n Enter element to insert : ");
			    scanf("%d",&n);
			    enqueue(n);
			    break;
			case 3: 
			    a=dequeue();
			    if(a!=-999)
			    printf("\n Deleted element : %d",a);
			    else
			    printf("\n Linear queue underflow");
			    break;
			case 4: 
			    display();
			    break;
			case 5: 
			    b=underflow();
			    if(b==1)
			    printf("\n Linear queue underflow");
			    else
			    printf("\n Linear queue is not underflow");
			    break;
			case 6: 
			    c=size();
			    if(c!=-999)
			    printf("\n Linear queue size : %d",c);
			    else
			    printf("\n Linear queue size : 0");
			    break;
			case 7: 
			    d=peek();
			    if(d!=-999)
			    printf("\n Linear queue peek : %d",d);
			    else
			    printf("\n Linear queue underflow");
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
	f=r=NULL;
}
lq * createnode(int x)
{
	lq *temp;
	temp=(lq *)malloc(sizeof(lq));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void enqueue(int x)
{
	lq *temp;
	temp=createnode(x);
	if(r==NULL)
	{
	    r=f=temp;
	}
	else
	{
		r->next=temp;
		r=temp;
	}
}
int dequeue()
{
	int x;
	lq *p;
	if(f==NULL)
	return -999;
	else
	{
		if(r==f)
		{
			p=f;
	        x=p->data;
			f=r=NULL;
			return x;
		}
		else
		{
			p=f;
	        x=p->data;
			f=p->next;
			free(p);
			return x;
		}
	}
}
void display()
{
	lq *p;
	if(f==NULL)
	printf("\n Linear queue underflow");
	else
	{
		printf("\n Linear queue : \n");
	    for(p=f;p!=NULL;p=p->next)
	    {
		   printf("%d ",p->data);
	    }
	}
}
int underflow()
{
	if(f==NULL)
	return 1;
	else
	return 0;
}
int size()
{
	int i;
	lq *p;
	if(f==NULL)
	return -999;
	else
	{
		for(p=f,i=1;p->next!=NULL;i++,p=p->next);
		return i;
	}
}
int peek()
{
	if(f==NULL)
	return -999;
	else
	return f->data;
}
