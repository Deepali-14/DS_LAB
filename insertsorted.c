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
void display(node *);
node * insertsorted(node *,int);
node * sort(node *);
void main()
{
	node *s=NULL;
	int ch,x;
	do
	{
	   printf("\n 1. CREATE \n 2. DISPLAY \n 3. INSERT SORTED \n 0. EXIT");
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
	   	    	printf("\n Enter element to insert : ");
	   	    	scanf("%d",&x);
	   	    	s=insertsorted(s,x);
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
	printf("\n Linked list is empty");
	else
	{
		printf("\n LINKED LIST :\n");
	    for(p=s;p!=NULL;p=p->next)
	    printf(" %d ",p->info);
	}
}
node * sort(node *s)
{
	node *c=s,*n=NULL;
	int temp;
	if(s==NULL || s->next==NULL)
	return s;
	else
	{
		while(c!=NULL)
		{
			n=c->next;
			while(n!=NULL)
			{
				if(c->info>n->info)
				{
					temp=c->info;
					c->info=n->info;
					n->info=temp;
				}
				n=n->next;
			}
			c=c->next;
		}
		return s;
	}
}
node * insertsorted(node *s,int x)
{
	node *p,*temp,*r=NULL;
	temp=createnode(x);
	if(s==NULL)
	{
		s=temp;
		return s;
	}
	else
	{
		s=sort(s);	   
        for(p=s;p!=NULL;r=p,p=p->next)
        {
        	if(p->info>temp->info || p->info==temp->info)
        	{
        		if(p==s)
        		{
        			temp->next=s;
        			s=temp;
        			return s;
				}
				else 
				{
					temp->next=r->next;
					r->next=temp;
					return s;
				}
			}
			else
			continue;
		}
	    for(p=s;p->next!=NULL;p=p->next);
		p->next=temp;
		return s;
	}
}
