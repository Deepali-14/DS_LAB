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
void split(node *,int);
int size(node *s);
void main()
{
	node *s=NULL;
	int ch,pos;
	do
	{
	   printf("\n 1. CREATE \n 2. DISPLAY \n 3. SPLIT \n 0. EXIT");
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
	   	    	printf("\n Enter position to split from : ");
	   	    	scanf("%d",&pos);
	   	    	split(s,pos);
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
int size(node *s)
{
	node *p;
	int i=0;
	if(s==NULL)
	return i;
	else
	{
	    for(p=s,i=1;p->next!=NULL;i++,p=p->next);
	    return i;
	}
}
void split(node *s,int pos)
{
	node *p=s,*q=NULL;
	int l=size(s),i;
	if(l==0)
		return ;
	else if(pos<2 || pos>l)
    {
    	printf("\n Invalid position for splitting");
    	return ;
	}
	else 
	{
		for(p=s,i=1;i<(pos-1);i++,p=p->next);
		q=p->next;
	    p->next=NULL;
		p=s;
		display(p);
		display(q);
		return;
	}		
}
