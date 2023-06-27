#include<stdio.h>
#include<stdlib.h>
struct cnode 
{
	int info;
	struct cnode *next;
};
typedef struct cnode cnode;
cnode * createnode(int);
cnode * create(cnode *s);
void display(cnode *s);
cnode * revercll(cnode *s);
void main()
{
	cnode *s=NULL;
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
	   	        display(s);
	   	    	break;
	   	    case 3:
	   	    	s=revercll(s);
	   	    	break;
	   	    case 0:
	   	    	printf("\n Exiting");
	   	    	break;
	   	    default:
	   	    	printf("\n Wrong choice");
	   }
	}while(ch!=0);
}
cnode * createnode(int x)
{
	cnode *temp;
	temp=(cnode *)malloc(sizeof(cnode));
	temp->info=x;
	return temp;
}
cnode * create(cnode *s)
{
	cnode *temp,*p;
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
		}
		else
		{
			for(p=s;p->next!=s;p=p->next);
		    p->next=temp;
		    temp->next=s;
		}
	}
	return s;
}
void display(cnode *s)
{
	cnode *p;
	if(s==NULL)
	printf("\n Linked list is empty");
	else
	{
		printf("\n LINKED LIST :\n");
		p=s;
	    do
	    {
	    	printf(" %d ",p->info);
	    	p=p->next;
		}while(p!=s);	   
	}
}
cnode * revercll(cnode *s)
{
	cnode *c=s,*p=NULL,*n=NULL,*temp;
	if(s==NULL || s->next==s)
	return s;
	else
	{
		for(c=s;c->next!=s;c=c->next);
		temp=c;
		n=s->next;
		c=s;
		while(n!=s)
		{
			if(c==s)
			{
				c->next=temp;
				p=c;
	            c=n;
			}
	        else
	        {
	        	n=n->next;
	        	c->next=p;
	            p=c;
	            c=n;
			}
		}
		s=p;
		return s;
	}
}
