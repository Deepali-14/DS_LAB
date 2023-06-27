#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *start=NULL;
void init();
Node * createnode(int);
void insertf(int);
void insertl(int);
void insertr(int,int);
void insertm(int);
void display();
int deletef();
int deletel();
int deleter(int);
int deletem();
void delspdata(int);
int size();
void lsearch(int);
void main()
{
	int ch,a,loc,key,u;
	do
	{
		printf("\n 1. Initialization \n 2. Insert First \n 3. Insert Random \n 4. Insert Middle \n 5. Insert Last \n 6. Display");
	    printf("\n 7. Delete First \n 8. Delete Random \n 9. Delete Middle \n 10. Delete Last \n 11. Delete specific data");
	    printf("\n 12. Size \n 13. Exit");
	    printf("\n Enter your choice : ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		    case 1: 
		       init();
		       break;
	    	case 2: 
	    	   printf("\n Enter element to insert : ");
	    	   scanf("%d",&a);
	    	   insertf(a);
		       break;
	    	case 3: 
	    	   printf("\n Enter element to insert : ");
	    	   scanf("%d",&a);
	    	   printf("\n Enter position to insert : ");
	    	   scanf("%d",&loc);
	    	   insertr(a,loc);
		       break;
		    case 4:
		       printf("\n Enter element to insert : ");
	    	   scanf("%d",&a);
	    	   insertm(a);
	    	   break;
		    case 5: 
		       printf("\n Enter element to insert : ");
	    	   scanf("%d",&a);
	    	   insertl(a);
		       break;
	    	case 6: 
	    	   display();
		       break;
		    case 7: 
		       u=deletef();
		       if(u==-999)
		       printf("\n Linked list is empty");
		       else
		       printf("\n Deleted element : %d",u);
		       break;
		    case 8: 
		       printf("\n Enter position to delete : ");
		       scanf("%d",&loc);
		       u=deleter(loc);
		       if(u==-999)
		       printf("\n Linked list is empty");
		       else if(u==-9999)
		       printf("\n Deletion not possible");
		       else
		       printf("\n Deleted element : %d",u);
		       break;
		    case 9:
		       u=deletem();
		       if(u==-999)
		       printf("\n Linked list is empty");
		       else
		       printf("\n Deleted element : %d",u);
		       break;
		    case 10: 
		       u=deletel();
		       if(u==-999)
		       printf("\n Linked list is empty");
		       else
		       printf("\n Deleted element : %d",u);
		       break;
		    case 11:
		       printf("\n Enter data to be deleted : ");
		       scanf("%d",&a);
		       delspdata(a);
		       break;
		    case 12: 
		       if(size())
		       printf("\n Size of Linked list : %d",size());
		       else
		       printf("\n Size of Linked list : 0");
		       break;
		    case 13: 
		       printf("\n We are exiting..Good Bye..!");
		       break;
		    default:
		       printf("\n Wrong choice entered..!");
	    }
	}while(ch!=13);
}
void init()
{
	start=NULL;
}
Node * createnode(int x)
{
	Node *temp;
	temp=(Node *)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void insertf(int x)
{
	Node *temp;
	temp=createnode(x);
	if(start==NULL)
	start=temp;
	else
	{
		temp->next=start;
		start=temp;
	}
}
void insertl(int x)
{
	Node *temp,*p;
	temp=createnode(x);
	if(start==NULL)
	start=temp;
	else
	{
		for(p=start;p->next!=NULL;p=p->next);
		p->next=temp;
	}
}
void insertr(int x,int pos)
{
	Node *temp,*p;
	int i,l=size();
	if(start==NULL)
	printf("\n Linked list is empty");
	else if(pos<1 || pos>(l+1))
	{
		printf("\n Insertion not possible");
		return;
	}
	else if(pos==1)
	{
		insertf(x);
		return;
	}
	else if(pos==(l+1))
	{
		insertl(x);
		return;
	}
	else 
	{
		temp=createnode(x);
		for(p=start,i=1;i<pos-1;i++,p=p->next);
		temp->next=p->next;
		p->next=temp;
		return;
	}
}
void insertm(int x)
{
	Node *temp,*p;
    int i;
    if(start==NULL)
    {
    	temp=createnode(x);
    	start=temp;
	}
    else
	{
		temp=createnode(x);
		for(p=start,i=1;i<(size()/2);i++,p=p->next);
		temp->next=p->next;
		p->next=temp;
	}
}
int size()
{
	Node *p;
	int c;
	if(start==NULL)
	return 0;
	else
	{
		for(p=start,c=0;p!=NULL;c++,p=p->next);
	    return c;
	}
}
int deletef()
{
	Node *p;
	int x;
	if(start==NULL)
	return -999;
	else
	{
	   	p=start;
	   	start=p->next;
	   	x=p->data;
	   	free(p);
	   	return x;
	}
}
int deletel()
{
	Node *p,*t;
	int i,x;
	if(start==NULL)
	return -999;
	else if(size()==1)
	{
		deletef();
		return;
	}
	else
	for(p=start,i=1;i<(size()-1);i++,p=p->next);
	t=p->next;
	p->next=NULL;
	x=t->data;
	free(t);
	return x;
}
int deleter(int pos)
{
	Node *p,*t;
	int l=size(),x,i;
	if(start==NULL)
	return -999;
	else 
	{
		if(pos<1 || pos>l)
		return -9999;
		else if(pos==1)
		{
			deletef();
			return;
		}
		else if(pos==l)
		{
			deletel();
			return;
		}
		else
		{
			for(p=start,i=1;i<(pos-1);i++,p=p->next);
			t=p->next;
			p->next=t->next;
			x=t->data;
			free(t);
			return x;
		}
	}
}
int deletem()
{
	Node *p,*t;
	int x,i;
	if(start==NULL)
	return -999;
	else if(size()==1)
	{
		t=start;
		start=NULL;
		x=t->data;
		free(t);
		return x;
	}
	else
	{
		for(p=start,i=1;i<(size()/2);i++,p=p->next);
		t=p->next;
		p->next=t->next;
		x=t->data;
		free(t);
		return x;
	}
}
void delspdata(int x)
{
	Node *p=start,*t;
	int flag=0;
	if(start==NULL)
	{
		printf("\n Linked list is empty");
		return;
	}
	else
	{
		while(p!=NULL)
    	{
		    if(p==start)
		    {
			    if(start->data==x)
			    {
				    flag++;
				    start=start->next;
				    p=start;
			    }
			    else
			    {
				    t=p;
				    p=p->next;
			    }
		    }
		    else if(p->data==x)
		    {
			    flag++;
			    t->next=p->next;
			    p=t->next;
		    }
	    	else
	    	{
			    t=p;
			    p=p->next;
		    }
	    }
    }
	if(flag==0)
		printf("\n Element not found");
}
void display()
{
	Node *p,*t;
	if(start==NULL)
	{
		printf("\n Linked list is empty");
	}
	else
	{
		printf("\n Linked list : \n");
		for(p=start;p!=NULL;p=p->next)
    	printf("%d\t",p->data);
	}
}
