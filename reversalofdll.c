#include<stdio.h>
#include<stdlib.h>
struct dnode
{
	int info;
	struct dnode *next;
	struct dnode *prev;
};
typedef struct dnode dnode;
dnode * createnode(int);
dnode * create(dnode *);
void fdisplay(dnode *);
void bdisplay(dnode *);
dnode * reversdll(dnode *);
void main()
{
	dnode *s=NULL;
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
	   	    	s=reversdll(s);
	   	    	break;
	   	    case 0:
	   	    	printf("\n Exiting");
	   	    	break;
	   	    default:
	   	    	printf("\n Wrong choice");
	   }
	}while(ch!=0);
}
dnode * createnode(int x)
{
	dnode *temp;
	temp=(dnode *)malloc(sizeof(dnode));
	temp->info=x;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
dnode * create(dnode *s)
{
	dnode *temp,*p;
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
		    temp->prev=p;
		}
	}
	return s;
}
void fdisplay(dnode *s)
{
	dnode *p;
	if(s==NULL)
	printf("\n EMPTY DOUBLY LINKED LIST");
	else
	{
		printf("\n DOUBLY LINKED LIST :\n");
	    for(p=s;p!=NULL;p=p->next)
	    printf(" %d ",p->info);
	}
}
void bdisplay(dnode *s)
{
	dnode *p;
	if(s==NULL)
	printf("\n EMPTY DOUBLY LINKED LIST");
	else
	{
		printf("\n DOUBLY LINKED LIST :\n");
	    for(p=s;p->next!=NULL;p=p->next);
	    for( ;p!=NULL;p=p->prev)
        printf(" %d ",p->info);
	}
}
dnode * reversdll(dnode *s)
{
	dnode *cn=s,*nn;
	if(s==NULL || s->next==NULL)
		return s;
    else
    {
        while(cn!=NULL)	
        {
        	s=cn;
        	nn=cn->next;
        	cn->next=cn->prev;
        	cn->prev=nn;
        	cn=nn;
		}
		return s;
	}
}
