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
void merge(node *,node *);
void main()
{
	node *s=NULL,*f=NULL;
	int ch;
	do
	{
	   printf("\n 1. CREATE \n 2. DISPLAY \n 3. MERGE \n 0. EXIT");
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
	   	    	merge(s,f);
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
void merge(node *s,node *f)
{
	node *r,*p;
	if(s==NULL)
	display(f);
	else if(f==NULL)
	display(s);
	else
	{
		r=s;
	    for(p=r;p->next!=NULL;p=p->next);
	    p->next=f;
	    p=r;
	    display(p);
	}
}
