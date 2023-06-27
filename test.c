//Deepali
//2016736
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
Node * init(Node *);
Node * createnode(int);
Node * insert(Node *, int);
void display(Node *);
Node * delspdata(Node *, int);
void main()
{
	Node *s=NULL;
	int ch,a,n,i;
	printf("\n Deepali \n 2016736 \n");
	do
	{
		printf("\n ******** DELETE SPECIFIC DATA AND DISPLAY ******** \n");
		printf("\n 1. Initialization \n 2. Insert \n 3. Display \n 4. Delete specific data \n 0. Exit");
	    printf("\n Enter your choice : ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		    case 1: 
		       s=init(s);
		       break;
		    case 2: 
		       printf("\n Enter number of data : ");
		       scanf("%d",&n);
		       i=1;
		       while(i<=n)
		       {
		       	    printf("\n Enter data %d : ",i);
	    	        scanf("%d",&a);
		       	    s=insert(s,a);
		       	    i++;
			   }
		       break;
	    	case 3: 
	    	   display(s);
		       break;
            case 4:
		       if(s!=NULL)
		       {
		       	    printf("\n Enter data to be deleted : ");
		            scanf("%d",&a);
		            s=delspdata(s,a);
			   }
			   else
			   printf("\n Linked list is empty");
		       break;
		    case 0: 
		       printf("\n We are exiting..Good Bye..:)!");
		       break;
		    default:
		       printf("\n Wrong choice entered..!");
	    }
	}while(ch!=0);
}
Node * init(Node *s)
{
	s=NULL;
	return s;
}
Node * createnode(int x)
{
	Node *temp;
	temp=(Node *)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
Node * insert(Node *s, int x)
{
	Node *temp,*p;
	temp=createnode(x);
	if(s==NULL)
	s=temp;
	else
	{
		for(p=s;p->next!=NULL;p=p->next);
		p->next=temp;
	}
	return s;
}
Node * delspdata(Node *s, int x)
{
	Node *p=s,*t;
	int flag=0;
	while(p!=NULL)
    {
		if(p==s)
		{
			if(s->data==x)
			{
				flag++;
				s=s->next;
				p=s;
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
	if(flag==0)
		printf("\n Element not found");
	return s;
}
void display(Node *s)
{
	Node *p,*t;
	if(s==NULL)
	{
		printf("\n Linked list is empty");
	}
	else
	{
		printf("\n Linked list : \n");
		for(p=s;p!=NULL;p=p->next)
    	printf("%d\t",p->data);
	}
}
