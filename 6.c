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
node * move(node *,int,int);
int size(node *s);
int search(node *,int);
node * swap(node *,int,int);
node * insertsorted(node *,int);
node * sort(node *);
void split(node *);
node * insertl(node *,int);
void main()
{
	node *s=NULL;
	int ch,p,q,x,y,pos,i,j;
	do
	{
	   printf("\n 1. CREATE \n 2. DISPLAY \n 3. DUPLICATE REMOVAL \n 4. MOVE NODE \n 5. SWAP NODE");
	   printf("\n 6. INSERT SORTED \n 7. SPLIT IN ODD AND EVEN \n 0. EXIT");
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
	   	    case 4:
	   	    	if(s!=NULL)
	   	    	{
	   	    		do
	   	    		{
	   	    			printf("\n Enter position of node to move : ");
	   	    		    scanf("%d",&p);
	   	    		    printf("\n Enter position to move node to : ");
	   	    		    scanf("%d",&q);
				    }while((p>size(s) || p<1) || (q>size(s) || q<1));
				    s=move(s,p,q);
				}
				else
				printf("\n LINKED LIST IS EMPTY");
	   	    	break;
	   	    case 5:
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
	   	    case 6:
	   	    	printf("\n Enter element to insert : ");
	   	    	scanf("%d",&x);
	   	    	s=insertsorted(s,x);
	   	    	break;
	   	    case 7:
	   	    	if(s!=NULL)
	   	    	split(s);
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
node * move(node *s,int x,int y)
{
	int pos;
	node *p,*t,*q;
	if(x==1)
	{
		t=s;
		s=s->next;
	}
	else
	{
		for(pos=1,p=s;pos<(x-1);pos++,p=p->next);
	    t=p->next;
	    p->next=t->next;
	}
	if(y==1)
	{
		t->next=s;
		s=t;
	}
	else
	{
		for(pos=1,p=s;pos<(y-1);pos++,p=p->next);
		q=p->next;
		t->next=q;
		p->next=t;
	}
	return s;
}
int size(node *s)
{
	int i;
	node *p;
	if(s==NULL)
	return 0;
	else
	{
	    for(i=1,p=s;p->next!=NULL;i++,p=p->next);
	    return i;
	}
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
void split(node *s)
{
	node *p=NULL,*q=NULL,*t;
	for(t=s;t!=NULL;t=t->next)
	{
		if(t->info%2==0)
		p=insertl(p,t->info);
		else
		q=insertl(q,t->info);
	}
	display(p);
	display(q);
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
