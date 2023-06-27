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
void dupremoval(node *);
void display(node *);
void main()
{
	node *s=NULL;
	int ch;
	do
	{
	   printf("\n 1. CREATE \n 2. DISPLAY \n 3. DUPLICATE REMOVAL \n 0. EXIT");
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
	   	    	dupremoval(s);
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
void dupremoval(node *s)
{
    node *p,*q,*r,*t;
    for(p=s;p!=NULL;p=p->next)
    {
      r=p;
    	q=p->next;
    	while(q!=NULL)
    	{
    		if(p->info==q->info)
    		{
    			r->next=q->next;
    			t=q;
    			q=q->next;
    			free(t);
			}
			else
			{
				r=q;
				q=q->next;
			}
		}
	}
//	for(p=s;p!=NULL;p=p->next)
//    {
//        r=p;
//    	for(q=p->next;q!=NULL;)
//    	{
//    		if(p->info==q->info)
//    		{
//    			r->next=q->next;
//    			t=q;
//    			q=q->next;
//    			free(t);
//			}
//			else
//			{
//				r=q;
//				q=q->next;
//			}
//		}
//	}
//	return s;
}
