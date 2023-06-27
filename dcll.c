#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
typedef struct node dcnode;
void fdisplay(dcnode *);
void bdisplay(dcnode *);
int size(dcnode *);
dcnode * init(dcnode *);
dcnode * insertf(dcnode *,int);
dcnode * insertl(dcnode *,int);
dcnode * insertr(dcnode *,int,int);
dcnode * deletef(dcnode *);
dcnode * deletel(dcnode *);
dcnode * deleter(dcnode *,int);
dcnode * createnode(int);
void main()
{
    dcnode *s=NULL;
	int ch,a,p;
	do
	{
		printf("\n1. Initialization \n2. Insert first \n3. Insert random \n4. Insert last \n5. Display");
		printf("\n6. Delete first \n7. Delete random \n8. Delete last \n9. Size \n10. Exit");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			     s=init(s); 
			     break;
			case 2: 
		    	 printf("\n Enter element to insert : ");
			     scanf("%d",&a);
		    	 s=insertf(s,a);
			     break;	
			case 3: 
			     printf("\n Enter element to insert : ");
			     scanf("%d",&a);
			     printf("\n Enter position to insert : ");
			     scanf("%d",&p);
		    	 s=insertr(s,a,p);
			     break; 
			case 4: 
			     printf("\n Enter element to insert : ");
			     scanf("%d",&a);
		    	 s=insertl(s,a);
			     break;
			case 5: 
			     printf("\n 1. Forward display \n 2. Backward display");
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
			case 6: 
			     s=deletef(s);
			     break;
			case 7: 
			     printf("\n Enter position to delete : ");
			     scanf("%d",&p);
			     s=deleter(s,p);
			     break;
			case 8: 
			     s=deletel(s);
			     break;
			case 9: 
			     if(size(s))
			     printf("\n Size of doubly circular linked list : %d",size(s));
			     else
			     printf("\n Size of doubly circular linked list : 0");
			     break;
			case 10:
			     printf("\n Exiting :)"); 
			     break;    
			default:
			     printf("\n Wrong choice entered");
		}
	}while(ch!=10);
}
dcnode * init(dcnode *s)
{
	s=NULL;
	return s;
}
dcnode * createnode(int x)
{
	dcnode *temp;
	temp=(dcnode *)malloc(sizeof(dcnode));
	temp->data=x;
	return temp;
}
int size(dcnode *s)
{
	dcnode *p;
	int i;
	if(s==NULL)
		return 0;
	else
	{ 
		for(i=1,p=s;p->next!=s;i++,p=p->next);
		return i;
	}
}
void fdisplay(dcnode *s)
{
	dcnode *p,*t;
	if(s==NULL)
	printf("\n ******** Doubly circular linked list is empty ********\n ");
	else
	{
		printf("\n ******** Doubly circular linked list ********\n ");
	    for(p=s;p->next!=s;p=p->next)
		printf(" %d ",p->data);
		printf(" %d ",p->data);
	}
}
void bdisplay(dcnode *s)
{
	dcnode *p,*t;
	if(s==NULL)
	printf("\n ******** Doubly circular linked list is empty ********\n ");
	else
	{
		printf("\n ******** Doubly circular linked list ********\n ");
		for(p=s;p->next!=s;p=p->next);
		{
			t=p;
			for(;p->prev!=t;p=p->prev)
		    printf(" %d ",p->data);
		    printf(" %d ",p->data);
		}
	}
}
dcnode * insertf(dcnode *s,int x)
{
	dcnode *p,*temp;
	temp=createnode(x);
    if(s==NULL)
	{
		s=temp;
		temp->prev=s;
		temp->next=s;
		return s;
	}	
	else
	{
		for(p=s;p->next!=s;p=p->next);
		p->next=temp;
		temp->prev=p;
		temp->next=s;
		s->prev=temp;
		s=temp;
		return s;
	}
}
dcnode * insertl(dcnode *s,int x)
{
	dcnode *p,*temp;
	temp=createnode(x);
    if(s==NULL)
	{
		s=temp;
		temp->prev=s;
		temp->next=s;
		return s;
	}	
	else
	{
		for(p=s;p->next!=s;p=p->next);
		p->next=temp;
		temp->prev=p;
		s->prev=temp;
		temp->next=s;
		return s;
	}
}
dcnode * insertr(dcnode *s,int x,int pos)
{
	dcnode *p,*t,*temp;
	int i,l=size(s);
	if(pos<1 || pos>(l+1))
	{
		printf("\n Invalid position");
		return s;
	}
	else if(pos==1)
	{
		s=insertf(s,x);
		return s;
	}
	else if(pos==(l+1))
	{
		s=insertl(s,x);
		return s;
	}
	else
	{
		temp=createnode(x);
		for(i=1,p=s;i<pos;i++,t=p,p=p->next);
	    t->next=temp;
		temp->prev=t;
		temp->next=p;
		p->prev=temp;
		return s;
	}
}
dcnode * deletef(dcnode *s)
{
	dcnode *p,*t,*temp;
	if(s==NULL)
	{
		printf("\n Deletion not possible as it is empty");
		return s;
	}
	else if(s->next==s)
	{
		printf("\n Deleted element : %d",s->data);
		s=NULL;
		free(s);
		return s;
	}
	else
	{
		p=s;   
        while(p->next!=s)  
        {  
           p=p->next;  
        }  
        p->next=s->next;  
        s->next->prev=p;  
        printf("\n Deleted element : %d",s->data);
        free(s);  
        s=p->next;  
		return s;
	}
}
dcnode * deletel(dcnode *s)
{
	dcnode *p,*t;
	if(s==NULL)
	{
		printf("\n Deletion not possible as it is empty");
		return s;
	}
	else if(s->next==s)
	{
		printf("\n Deleted element : %d",s->data);
		s=NULL;
		free(s);
		return s;
	}
	else
	{
		for(p=s;p->next!=s;t=p,p=p->next);
		t->next=s;
		printf("\n Deleted element : %d",p->data);
		free(p);
		s->prev=t;
		return s;
	}
}
dcnode * deleter(dcnode *s,int pos)
{
	dcnode *p,*t,*temp;
	int i;
	int l=size(s);
	if(s==NULL)
	{
		printf("\n Deletion not possible as it is empty");
		return s;
	}
	else if(pos<1 || pos>l)
	{
		printf("\n Invalid position");
		return s;
	}
	else if(pos==1)
	{
		s=deletef(s);
		return s;
	}
	else if(pos==l)
	{
		s=deletel(s);
		return s;
	}
	else
	{
		for(p=s,i=1;i<pos;i++,t=p,p=p->next);
		temp=p->next;
		t->next=temp;
		temp->prev=t;
		printf("\n Deleted element : %d",p->data);
		free(p);
		return s;
	}
}
