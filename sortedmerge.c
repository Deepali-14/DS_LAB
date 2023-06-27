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
void sortedmerge(node *,node *);
node * sort(node *);
node * insertl(node *,int);
void main()
{
	node *s=NULL,*f=NULL,*p=NULL;
	int ch;
	do
	{
	   printf("\n 1. CREATE \n 2. DISPLAY \n 3. SORTED MERGE \n 0. EXIT");
	   printf("\n Enter your choice : ");
	   scanf("%d",&ch);
	   switch(ch)
	   {
	   	    case 1:
	   	    	printf("\n ***** LINKED LIST 1 *****\n");
	   	    	s=create(s);
	   	    	printf("\n ***** LINKED LIST 2 *****\n");
	   	    	f=create(f);
	   	    	break;
	   	    case 2:
	   	    	printf("\n ***** LINKED LIST 1 *****\n");
	   	        display(s);
	   	        printf("\n ***** LINKED LIST 2 *****\n");
	   	        display(f);
	   	    	break;
	   	    case 3:
	   	    	sortedmerge(s,f);
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
void sortedmerge(node *s,node *f)
{
	node *p=NULL,*t,*u;
	if(s==NULL && f==NULL)
	{
		printf("\n Linked lists are empty");
		return;
	}
	else if(s!=NULL && f==NULL)
	{
		s=sort(s);
		display(s);
	}
	else if(s==NULL && f!=NULL)
	{
		f=sort(f);
		display(f);
	}
	else
	{
		s=sort(s);
		f=sort(f);
		t=s;
		u=f;
		while(t!=NULL && u!=NULL)
		{
			if(t->info<u->info)
			{
				p=insertl(p,t->info);
				t=t->next;
			}
			else if(u->info<t->info)
			{
				p=insertl(p,u->info);
				u=u->next;
			}
			else
			{
				p=insertl(p,t->info);
				t=t->next;
				p=insertl(p,u->info);
				u=u->next;
			}
		}
		while(t!=NULL)
		{
			p=insertl(p,t->info);
			t=t->next;
		}
		while(u!=NULL)
		{
			p=insertl(p,u->info);
			u=u->next;
		}
	    display(p);
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
node * insertl(node *s,int x)
{
	node *temp,*p;
	temp=(node *)malloc(sizeof(node));
	temp->info=x;
	temp->next=NULL;
	if(s==NULL)
	s=temp;
	else
	{
		for(p=s;p->next!=NULL;p=p->next);
	    p->next=temp;
	}
	return s;
}
