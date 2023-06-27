#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * next;
};
struct head
{
	int hdata;
	struct node *next;
};
typedef struct node node;
typedef struct head head;
head * init(head *);
node * createnode(int);
int size(head *);
head * insertf(head *,int);
head * insertl(head *,int);
head * insertr(head *,int,int);
head * deletef(head *);
head * deletel(head *);
head * deleter(head *,int);
void display(head *);
void main()
{
	head *h;
	int ch,a,b,c,p,l;
	h=(head *)malloc(sizeof(head));
	h->hdata=0;
	h->next=NULL;
	do
	{
		printf("\n 1. Initialization \n 2. Insert first \n 3. Insert random \n 4. Insert last \n 5. Display");
		printf("\n 6. Delete first \n 7. Delete random \n 8. Delete last \n 9. Size \n 10. Exit");
		printf("\n Enter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				h=init(h);
				break;
			case 2:
				printf("\n Enter element to insert : ");
				scanf("%d",&a);
				h=insertf(h,a);
				break;
			case 3: 
			    printf("\n Enter element to insert : ");
				scanf("%d",&b);
				printf("\n Enter position to insert at : ");
				scanf("%d",&p);
				h=insertr(h,b,p);
			    break;
			case 4: 
			    printf("\n Enter element to insert : ");
				scanf("%d",&c);
				h=insertl(h,c);
			    break;
			case 5: 
			    display(h);
			    break;
			case 6: 
			    h=deletef(h);
			    break;
			case 7: 
			    printf("\n Enter position to delete from : ");
				scanf("%d",&l);
				h=deleter(h,l);
			    break;
			case 8: 
			    h=deletel(h);
			    break;
		    case 9: 
		        printf("\n Size of linked list : %d",h->hdata);
			    break;
			case 10: 
			    printf("\n Exiting");
			    break;
			default:
				printf("\n Wrong choice");
			
		}
	}while(ch!=10);
}
head * init(head * h)
{
	h->next=NULL;
	h->hdata=0;
	return h;
}
node * createnode(int x)
{
	node *temp;
	temp=(node *)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
head * insertf(head *h,int x)
{
	node *temp;
	temp=createnode(x);
	h->hdata++;
	if(h->next==NULL)
	h->next=temp;
	else
	{
		temp->next=h->next;
	    h->next=temp;
	}
	return h;
}
head * insertl(head *h,int x)
{
	node *temp,*p;
	temp=createnode(x);
	h->hdata++;
	if(h->next==NULL)
	h->next=temp;
	else
	{
		for(p=h->next;p->next!=NULL;p=p->next);
	    p->next=temp;
	}
	return h;
}
head * insertr(head *h,int x,int pos)
{
	int s=h->hdata;
	node *temp,*p;
	int i;
	if(pos<1 || pos>(s+1))
	{
		printf("\n Invalid position");
		return h;
	}
	else if(pos==1)
	{
		h=insertf(h,x);
		return h;
	}
	else if(pos==(s+1))
	{
		h=insertl(h,x);
		return h;
	}
	else
	{
		h->hdata++;
		temp=createnode(x);
		for(i=1,p=h->next;i<(pos-1);i++,p=p->next);
		temp->next=p->next;
		p->next=temp;
		return h;
	}
}
head * deletef(head *h)
{
	node *p;
	if(h->next==NULL)
	{
		printf("\n Linked list is empty");
		return h;
	}
	else
	{
	    h->hdata--;
	    p=h->next;
	    h->next=p->next;
	    printf("\n Deleted element = %d",p->data);
	    free(p);
		return h;	
    }
}
head * deletel(head *h)
{
	int s=h->hdata;
	node *p,*t;
	if(h->next==NULL)
	{
		printf("\n Linked list is empty");
		return h;
	}
	else if(s==1)
	{
		h=deletef(h);
		return h;
	}
	else
	{
	    h->hdata--;
	    for(p=h->next;p->next!=NULL;t=p,p=p->next);
		t->next=NULL;
	    printf("\n Deleted element = %d",p->data);
	    free(p);
		return h;	
    }
}
head * deleter(head *h,int pos)
{
	int s=h->hdata;
	node *t,*p;
	int i;
	if(h->next==NULL)
	{
		printf("\n Linked list is empty");
		return h;
	}
	else if(pos<1 || pos>s)
	{
		printf("\n Invalid position");
		return h;
	}
	else if(pos==1)
	{
		h=deletef(h);
		return h;
	}
	else if(pos==s)
	{
		h=deletel(h);
		return h;
	}
	else
	{
		h->hdata--;
		for(p=h->next,i=1;i<(pos-1);i++,p=p->next);
		t=p->next;
		p->next=t->next;
		printf("\n Deleted element = %d",t->data);
		free(t);
		return h;
	}
}
void display(head *h)
{
	node *p;
	if(h->next==NULL)
	printf("\n Linked list is empty");
	else
	{
		printf("\n Linked list : \n");
		for(p=h->next;p!=NULL;p=p->next)
		printf(" %d ",p->data);
	}
}
