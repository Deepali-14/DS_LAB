#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
};
typedef struct node node;
node * createnode(int);
node * create(node *);
node * move(node *,int,int);
void display(node *);
int size(node *);
void main()
{
	node *s=NULL;
	int p,q,ch;
	do
	{
	   printf("\n 1. CREATE \n 2. DISPLAY \n 3. MOVE \n 0. EXIT");
	   printf("\n Enter your choice : ");
	   scanf("%d",&ch);
	   switch(ch)
	   {
	   	    case 1:
	   	    	s=create(s);
	   	    	break;
	   	    case 2:
	   	        display(s);
	   	    	break;
	   	    case 3:
	   	    	if(s!=NULL)
	   	    	{
	   	    		do
	   	    		{
	   	    			printf("\n Enter position of node to move : ");
	   	    		    scanf("%d",&p);
	   	    		    printf("\n Enter position to move node to : ");
	   	    		    scanf("%d",&q);
				    }while((p>size(s) || p<1) || (q>size(s) || q<1));
				    s=move(s,p,q);
				}
				else
				printf("\n LINKED LIST IS EMPTY");
	   	    	break;
	   	    case 0:
	   	    	printf("\n Exiting");
	   	    	break;
	   	    default:
	   	    	printf("\n Wrong choice");
	   }
	}while(ch!=0);
}
node * createnode(int x)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->info=x;
	temp->next=NULL;
	return temp;
}
node * create(node *s)
{
	node *temp,*p;
	int n,x,i;
	printf("\n Enter number of nodes in linked list : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter data : ");
		scanf("%d",&x);
		temp=createnode(x);
		if(s==NULL)
		s=temp;
		else
		{
			for(p=s;p->next!=NULL;p=p->next);
		    p->next=temp;
		}
	}
	return s;
}
void display(node *s)
{
	node *p;
	if(s==NULL)
	printf("\n LINKED LIST IS EMPTY");
	else
	{
		printf("\n LINKED LIST :\n");
	    for(p=s;p!=NULL;p=p->next)
	    printf(" %d ",p->info);
	}
}
int search(node *s,int x)
{
	node *p;
	int flag=0,i;
	for(p=s,i=1;p!=NULL;i++,p=p->next)
	{
		if(p->info==x)
		{
			flag=1;
			return i;
		}
		else
		continue;
	}
	if(p==NULL && flag==0)
	return 0;
}
node * move(node *s,int x,int y)
{
	int pos;
	node *p,*t,*q;
	if(x==1)
	{
		t=s;
		s=s->next;
	}
	else
	{
		for(pos=1,p=s;pos<(x-1);pos++,p=p->next);
	    t=p->next;
	    p->next=t->next;
	}
	if(y==1)
	{
		t->next=s;
		s=t;
	}
	else
	{
		for(pos=1,p=s;pos<(y-1);pos++,p=p->next);
		q=p->next;
		t->next=q;
		p->next=t;
	}
	return s;
}
int size(node *s)
{
	int i;
	node *p;
	if(s==NULL)
	return 0;
	else
	{
	    for(i=1,p=s;p->next!=NULL;i++,p=p->next);
	    return i;
	}
}
