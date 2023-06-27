//Program to find middle element
#include<stdio.h>

#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node node;

node * init(node *);

node * createnode(int);

node * create(node *);

void display(node *);

int midpos(node *);

void middle(node *,int);

int main()
{
	node *s=NULL;
	int ch,n,pos;
	
    do
    {
    	printf("\n 1. Initialization \n 2. Create \n 3. Display \n 4. Middle element \n 0. Exit");
    	
		printf("\n Enter coice : ");
    	scanf("%d",&ch);
    	
		switch(ch)
    	{
    		case 1:
    			s=init(s);
    			break;
    			
    		case 2:
    			printf("\n Enter number of nodes in the linked list : ");
    			scanf("%d",&n);
    			while(n!=0)
    			{
    				s=create(s);
    				n--;
				}
    			break;
    			
    		case 3:
    			display(s);
    			break;
    		
   		    case 4:
   		    	if(s==NULL)
   		    	printf("\n Linked list is empty \n");
   		    	
   		    	else
   		    	{
   		    		pos=midpos(s);
   			        middle(s,pos);
				}
    			break;
    			
    		case 0:
    			printf("\n Exiting :)");
    			break;
    			
    		default:
    		    printf("\n Wrong choice entered \n");
		}
	}while(ch!=0);
}

node * init(node *s)
{
	s=NULL;
	
	return s;
}

node * createnode(int x)
{
	node *temp;
	
	temp=(node *)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	
	return temp;
}

node * create(node *s)
{
	
	int n;
	node *temp,*p;
	
	printf("\n Enter data : ");
	scanf("%d",&n);
	
	temp=createnode(n);
	
	if(s==NULL)
	s=temp;
	
	else
	{
		for(p=s;p->next!=NULL;p=p->next);
		p->next=temp;
	}
	
	return s;
}

void display(node *s)
{
	node *p;
	
	if(s==NULL)
	{
		printf("\n Linked list is empty \n");
		return;
	}
	
	else
	{
		for(p=s;p!=NULL;p=p->next)
		printf(" %d ",p->data);
		printf("\n");
	}
}

int midpos(node *s)
{
	int i;
	node *p;
	
	for(p=s;p!=NULL;p=p->next)
	    i++;
	
    if(i%2!=0)
	    i=i/2+1;
	
    else
	    i=i/2;
	            
	return i;
}

void middle(node *s,int pos)
{
	int i;
	node *p;
	
	for(i=0,p=s;i<pos-1;i++,p=p->next);
	printf("\n Middle node value = %d \n Middle node position = %d\n",p->data,pos);
	
}
