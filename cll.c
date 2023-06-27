#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node cnode;
cnode * init(cnode *);
cnode * createnode(int);
int size(cnode *);
cnode * insertf(cnode *,int);
cnode * insertl(cnode *,int);
cnode * insertr(cnode *,int,int);
cnode * deletef(cnode *);
cnode * deletel(cnode *);
cnode * deleter(cnode *,int);
void display(cnode *);
cnode * revercll(cnode *s);
void main()
{
	cnode *start=NULL;
	int ch,a,b,c,p,l,s;
	do
	{
		printf("\n1. Initialization \n2. Insert first \n3. Insert random \n4. Insert last \n5. Display");
		printf("\n6. Delete first \n7. Delete random \n8. Delete last \n9. Size \n10. Reverse \n11. Exit");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			     start=init(start); 
			     break;
			case 2: 
		    	 printf("\n Enter element to insert : ");
			     scanf("%d",&a);
		    	 start=insertf(start,a);
			     break;	
			case 3: 
			     printf("\n Enter element to insert : ");
			     scanf("%d",&b);
			     printf("\n Enter position to insert : ");
			     scanf("%d",&p);
		    	 start=insertr(start,b,p);
			     break; 
			case 4: 
			     printf("\n Enter element to insert : ");
			     scanf("%d",&c);
		    	 start=insertl(start,c);
			     break;
			case 5: 
			     display(start);
			     break;
			case 6: 
			     start=deletef(start);
			     break;
			case 7: 
			     printf("\n Enter position to delete : ");
			     scanf("%d",&l);
			     start=deleter(start,l);
			     break;
			case 8: 
			     start=deletel(start);
			     break;
			case 9: 
			     s=size(start);
			     if(s!=0)
			     printf("\n Size of circular linked list : %d",s);
			     else
			     printf("\n Size of circular linked list : 0");
			     break;
			case 10:
	   	    	 start=revercll(start);
			     break;
			case 11:
			     printf("\n Exiting"); 
			     break;    
			default:
			     printf("\n Wrong choice entered");
		}
	}while(ch!=11);
}
cnode * init(cnode *start)
{
	start=NULL;
	return start;
}
cnode * createnode(int x)
{
	cnode *temp;
	temp=(cnode *)malloc(sizeof(cnode));
	temp->data=x;
	return temp;
}
int size(cnode *start)
{
	cnode *p;
	int i;
	if(start==NULL)
	return 0;
	else
	{
		for(p=start,i=1;p->next!=start;i++,p=p->next);
    	return i;
	}
}
cnode * insertf(cnode *start,int x)
{
	cnode *temp,*p;
	temp=createnode(x);
	if(start==NULL)
	{
		start=temp;
		temp->next=start;
		return start;
	}
	else
	{
		for(p=start;p->next!=start;p=p->next);
		p->next=temp;
		temp->next=start;
		start=temp;	
		return start;
	}
}
cnode * insertl(cnode *start,int x)
{
	cnode *temp,*p;
	temp=createnode(x);
	if(start==NULL)
	{
		start=temp;
		temp->next=start;
		return start;
	}
	else
	{
		for(p=start;p->next!=start;p=p->next);
		p->next=temp;
		temp->next=start;
		return start;
	}
}
cnode * insertr(cnode *start,int x,int pos)
{
	cnode *temp,*p;
	int s=size(start),i;
	if(pos<1 || pos>s+1)
	{
		printf("\n Position not justified");
		return start;
	}
	else if(pos==1)
	{
		start=insertf(start,x);
		return start;
	}
	else if(pos==s+1)
	{
		start=insertl(start,x);
		return start;
	}
	else if(pos>1 && pos<=s)
	{
		temp=createnode(x);
	    for(p=start,i=1;i<(pos-1);i++,p=p->next);
		temp->next=p->next;
		p->next=temp;	
		return start;
	}
}
void display(cnode *start)
{
	cnode *p;
	if(start==NULL)
	printf("\n Circular linked list is empty");
	else
	{
		printf("\n Circular linked list : \n");
		for(p=start;p->next!=start;p=p->next)
		printf("%d -> ",p->data);
		printf("%d",p->data);
	}
}
cnode * deletef(cnode *start)
{
	cnode *p,*temp;
	if(start==NULL)
	printf("\n Circular linked list is empty");
	else
	{
		temp=start;
        if(start->next==start)   
		start=NULL;
        else   
		{   
		    for(p=start;p->next!=start;p=p->next);
		    start=temp->next;   
			p->next=start;  
	    }
        printf("\n Deleted element : %d",temp->data);
        free(temp);
    }
    return start;
}
cnode * deletel(cnode *start)
{
	cnode *p,*t;
	if(start==NULL)
	printf("\n Circular linked list is empty");
	else
	{
		p=start;
        if(start->next==start)   
		start=NULL;
        else   
		{   
		    for(p=start;p->next!=start;t=p,p=p->next);
		    t->next=start;
	    }
        printf("\n Deleted element : %d",p->data);
        free(p);
    }
    return start;
}
cnode * deleter(cnode *start,int pos)
{
	cnode *temp,*p,*t;
	int s=size(start),i;
	if(start==NULL)
	printf("\n Circular linked list is empty");
	else if(pos<1 || pos>s)
	printf("\n Position not justified");
	else if(pos==1)
	start=deletef(start);
	else if(pos==s)
	start=deletel(start);
	else if(pos>1 && pos<s)
	{
	    for(p=start,i=1;i<(pos-1);i++,p=p->next);
	    t=p->next;
		p->next=t->next;
		printf("\n Deleted element : %d",t->data);
        free(t);	
	}
	return start;
}
cnode * revercll(cnode *s)
{
	cnode *c=s,*p=NULL,*n=NULL,*temp;
	if(s==NULL || s->next==s)
	return s;
	else
	{
		for(c=s;c->next!=s;c=c->next);
		temp=c;
		n=s->next;
		c=s;
		while(n!=s)
		{
			if(c==s)
			{
				c->next=temp;
				p=c;
	            c=n;
			}
	        else
	        {
	        	n=n->next;
	        	c->next=p;
	            p=c;
	            c=n;
			}
		}
		s=p;
		return s;
	}
}
