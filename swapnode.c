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
int search(node *,int);
node * swap(node *,int,int);
void main()
{
	node *s=NULL;
	int i,x,j,y,ch;
	do
	{
	   printf("\n 1. CREATE \n 2. DISPLAY \n 3. SWAP \n 0. EXIT");
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
	   	    		printf("\n Enter element to search : ");
            	    scanf("%d",&x);
            	    i=search(s,x);
             	    printf("\n Enter element to search : ");
            	    scanf("%d",&y);
             	    j=search(s,y);
             	    s=swap(s,i,j);
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
node * swap(node *s,int i,int j)
{
	int pos;
	node *temp,*p,*t=NULL,*prevx,*px,*prevy,*py;
	for(p=s,pos=1;pos<i;pos++,t=p,p=p->next);
	prevx=t;
	px=p;
	for(p=s,pos=1;pos<j;pos++,t=p,p=p->next);
	prevy=t;
	py=p;
	//This is main swap function
	temp=py->next;
	py->next=px->next;
	px->next=temp;
	if(prevx==NULL)
	{
		s=py;
		prevy->next=px;
	}
	if(prevy==NULL)
	{
		s=px;
		prevx->next=py;
	}
	if(prevx!=NULL && prevy!=NULL)
	{
		prevx->next=py;
		prevy->next=px;
	}
	return s;
}
