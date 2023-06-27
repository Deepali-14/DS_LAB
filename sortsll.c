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
node * sort(node *);
void lsearch(node *,int);
void main()
{
	node *s=NULL;
	int ch,key;
	do
	{
	   printf("\n 1. CREATE \n 2. DISPLAY \n 3. SEARCH \n 4. SORT \n 0. EXIT");
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
	   	        printf("\n Enter element to search : ");
	            scanf("%d",&key);
		        lsearch(s,key);
	   	    	break;
	   	    case 4:
	   	    	s=sort(s);
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
void lsearch(node *s,int y)
{
	node *p;
	int c=0,i;
	if(s==NULL)
	printf("\n Linked list is empty");
	else
	{
		for(p=s,i=1;p!=NULL;i++,p=p->next)
		{
			if(y==p->info)
			{
			    printf("\n %d found at %d position",y,i);
			    c++;
			}
		}
		if(c==0)
		printf("\n %d not found",y);
		else
		printf("\n %d found %d times",y,c);
	}
}
