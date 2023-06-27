#include<stdio.h>
#include<malloc.h>
struct dnode
{
	int data;
	struct dnode *next;
	struct dnode *prev;
};
typedef struct dnode dnode;
dnode * createnode(int);
dnode * init(dnode *);
dnode * insertf(dnode *,int);
dnode * insertl(dnode *,int);
dnode * insertp(dnode *,int,int);
dnode * deletef(dnode *);
dnode * deletel(dnode *);
dnode * deletep(dnode *,int);
void fdisplay(dnode *);
void bdisplay(dnode *);
int size(dnode *);
dnode * reversdll(dnode *);
void main()
{
	dnode *start=NULL;
	int ch,a,b,c,pos,p;
	do
	{
		printf("\n 1. Initialization \n 2. Insert first \n 3. Insert by position \n 4. Insert last \n 5. Forward display");
		printf("\n 6. Backward display \n 7. Delete first \n 8. Delete by position \n 9. Delete last \n 10. Size \n 11. Reverse\n 12. Exit");
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
				start=insertp(start,b,p);
				break;
			case 4:
				printf("\n Enter element to insert : ");
				scanf("%d",&c);
				start=insertl(start,c);
				break;
			case 5:
				fdisplay(start);
				break;
			case 6:
				bdisplay(start);
				break;
			case 7:
				start=deletef(start);
				break;
			case 8:
				printf("\n Enter position to delete : ");
				scanf("%d",&pos);
				start=deletep(start,pos);
				break;
			case 9:
				start=deletel(start);
				break;
			case 10:
				if(size(start)==0)
				printf("\n Size of doubly linked list : 0");
				else
				printf("\n Size of doubly linked list : %d",size(start));
				break;
			case 11:
				start=reversdll(start);
				break;
			case 12:
				printf("\n Exiting...!");
				break;
			default:
				printf("\n Wrong choice entered");
		}
	}while(ch!=12);
}
dnode * createnode(int x)
{
	dnode *temp;
	temp=(dnode *)malloc(sizeof(dnode));
	temp->data=x;
	temp->prev=NULL;
	temp->next=NULL;
	return temp;
}
dnode * init(dnode *start)
{
	start=NULL;
	return start;
}
dnode * insertf(dnode *start,int x)
{
	dnode *temp;
	temp=createnode(x);
	if(start==NULL)
	{
		start=temp;
		return start;
	}
	else
	{
		temp->next=start;
		start->prev=temp;
		start=temp;
		return start;
	}
}
dnode * insertl(dnode *start,int x)
{
	dnode *temp,*p;
	temp=createnode(x);
	if(start==NULL)
	{
		start=insertf(start,x);
		return start;
	}
	else
	{
		for(p=start;p->next!=NULL;p=p->next);
		{
			p->next=temp;
			temp->prev=p;
			return start;
		}
	}
}
dnode * insertp(dnode *start,int x, int pos)
{
	int s=size(start),i;
	dnode *temp,*p=start,*t;
	if(pos<1 || pos>(s+1))
	{
		printf("\n Insertion not possible due to invalid position");
		return start;
	}
	else if(pos==1)
	{
		start=insertf(start,x);
		return start;
	}
	else if(pos==(s+1))
	{
		start=insertl(start,x);
		return start;
	}
	else
	{
		temp=createnode(x);
		for(i=1,p=start;i<pos;i++,p=p->next);
		t=p->prev;
		t->next=temp;
		temp->prev=t;
		temp->next=p;
		p->prev=temp;
		return start;
	}
}
dnode * deletef(dnode *start)
{
	dnode *p;
	if(start==NULL)
	{
		printf("\n Deletion not possible as doubly linked list is empty");
		return start;
	}
	else if(start->next==NULL)
	{
		printf("\n %d deleted",start->data);
		free(start);
		start=NULL;
		return start;
	}
	else
	{
		p=start;
		start=start->next;
		start->prev=NULL;
		printf("\n %d deleted",p->data);
		free(p);
		return start;
	}
}
dnode * deletel(dnode *start)
{
	dnode *t,*p;
	if(start==NULL)
	{
		printf("\n Deletion not possible as doubly linked list is empty");
		return start;
	}
	else if(start->next==NULL)
	{
		printf("\n %d deleted",start->data);
		free(start);
		start=NULL;
		return start;
	}
	else
	{
		for(p=start;p->next!=NULL;p=p->next);
		{
			t=p->prev;
			t->next=NULL;
			printf("\n %d deleted",p->data);
		    free(p);
			return start;
		}
	}
}
dnode * deletep(dnode *start,int pos)
{
	int s=size(start),i;
	dnode *p=start,*t,*temp;
	if(start==NULL)
	{
		printf("\n Deletion not possible as doubly linked list is empty");
		return start;
	}
	else if(pos<1 || pos>s)
	{
		printf("\n Deletion not possible due to invalid position");
		return start;
	}
	else if(pos==1)
	{
		start=deletef(start);
		return start;
	}
	else if(pos==s)
	{
		start=deletel(start);
		return start;
	}
	else
	{
		for(i=1,p=start;i<pos;i++,p=p->next);
		t=p->prev;
		temp=p->next;
		t->next=temp;
		temp->prev=t;
		printf("\n %d deleted",p->data);
		free(p);
		return start;
	}
}
int size(dnode *start)
{
	int i;
	dnode *p;
	if(start==NULL)
	return 0;
	else
	{
		for(i=1,p=start;p->next!=NULL;i++,p=p->next);
	    return i;
	}
}
void fdisplay(dnode *start)
{
	dnode *p;
	if(start==NULL)
    printf("\n Doubly linked list is empty");
    else
    {
    	printf("\n Doubly linked list : \n");
        for(p=start;p!=NULL;p=p->next)	
        printf("%d\t",p->data);
	}
}
void bdisplay(dnode *start)
{
	dnode *p;
	if(start==NULL)
    printf("\n Doubly linked list is empty");
    else
    {
    	printf("\n Doubly linked list : \n");
    	for(p=start;p->next!=NULL;p=p->next);
	    for( ;p!=NULL;p=p->prev)
        printf("%d\t",p->data);
	}
}
dnode * reversdll(dnode *start)
{
	dnode *cn=start,*nn;
	if(start==NULL || start->next==NULL)
		return start;
    else
    {
        while(cn!=NULL)	
        {
        	start=cn;
        	nn=cn->next;
        	cn->next=cn->prev;
        	cn->prev=nn;
        	cn=nn;
		}
		return start;
	}
}
