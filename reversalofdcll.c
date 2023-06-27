#include<stdio.h>
#include<stdlib.h>
struct dcnode
{
	int info;
	struct dcnode *next;
	struct dcnode *prev;
};
typedef struct dcnode dcnode;
dcnode * createnode(int);
dcnode * create(dcnode *);
void fdisplay(dcnode *);
void bdisplay(dcnode *);
dcnode * reversdcll(dcnode *);
void main()
{
	dcnode *s=NULL;
	int ch;
	do
	{
	   printf("\n 1. CREATE \n 2. DISPLAY \n 3. REVERSE \n 0. EXIT");
	   printf("\n Enter your choice : ");
	   scanf("%d",&ch);
	   switch(ch)
	   {
	   	    case 1:
	   	    	s=create(s);
	   	    	break;
	   	    case 2:
	   	    	printf("\n 1. FORWARD DISPLAY \n 2. BACKWARD DISPLAY");
	   	    	printf("\n Enter your choice : ");
	            scanf("%d",&ch);
	            switch(ch)
	            {
	            	case 1:
	            		fdisplay(s);
	            		break;
	            	case 2:
	            	    bdisplay(s);
	            		break;
	            	default:
	            		printf("\n Wrong choice");
				}
	   	    	break;
	   	    case 3:
	   	    	s=reversdcll(s);
	   	    	break;
	   	    case 0:
	   	    	printf("\n Exiting");
	   	    	break;
	   	    default:
	   	    	printf("\n Wrong choice");
	   }
	}while(ch!=0);
}
dcnode * createnode(int x)
{
	dcnode *temp;
	temp=(dcnode *)malloc(sizeof(dcnode));
	temp->info=x;
	return temp;
}
dcnode * create(dcnode *s)
{
	dcnode *temp,*p;
	int n,x,i;
	printf("\n Enter number of nodes in linked list : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\n Enter data : ");
		scanf("%d",&x);
		temp=createnode(x);
		if(s==NULL)
		{
			s=temp;
			temp->next=s;
			temp->prev=s;
		}
		else
		{
			for(p=s;p->next!=s;p=p->next);
		    p->next=temp;
		    temp->prev=p;
		    s->prev=temp;
		    temp->next=s;
		}
	}
	return s;
}
void fdisplay(dcnode *s)
{
	dcnode *p=s;
	if(s==NULL)
	printf("\n EMPTY DOUBLY CIRCULAR LINKED LIST");
	else
	{
		printf("\n DOUBLY CIRCULAR LINKED LIST :\n");
	    do
	    {
	    	printf(" %d ",p->info);
	    	p=p->next;
		}while(p!=s);
	}
}
void bdisplay(dcnode *s)
{
	dcnode *p,*t;
	if(s==NULL)
	printf("\n EMPTY DOUBLY CIRCULAR LINKED LIST");
	else
	{
		printf("\n DOUBLY CIRCULAR LINKED LIST :\n");
	    for(p=s;p->next!=s;p=p->next);
	    {
	    	t=p;
	    	do
	    	{
	    		printf(" %d ",p->info);
	    		p=p->prev;
			}while(p!=t);
		}
	}
}
dcnode * reversdcll(dcnode *s)
{
	dcnode *c=s,*n=NULL,*temp;
	if(s==NULL || s->next==NULL)
	return s;
	else
	{
		while(c->next!=s)
		{
			s=c;
			n=c->next;
			c->next=c->prev;
		    c->prev=n;
		    c=n;
		}
	    return s;		
	}
}
