#include<stdio.h>
#include<stdlib.h>
struct node
{
	void *data;
	struct node *next;
	int type;
};
typedef struct node node;
node *s=NULL;
void init();
void insertf();
void insertl();
void insertr(int);
void deletef();
void deletel();
void deleter(int);
void display();
int size();
void main()
{
	int ch,p,l;
	do
	{
		printf("\n 1. Initialization \n 2. Insert first \n 3. Insert last \n 4. Insert random \n 5. Delete first");
		printf("\n 6. Delete last \n 7. Delete random \n 8. Display \n 9. Size \n 10. Exit");
		printf("\n Enter choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				init();
				break;
			case 2:
				insertf();
				break;
			case 3:
				insertl();
				break;
			case 4:
				printf("\n Enter position to insert : ");
				scanf("%d",&p);
				insertr(p);
				break;
			case 5:
				deletef();
				break;
			case 6:
				deletel();
				break;
			case 7:
			    printf("\n Enter position to delete : ");
				scanf("%d",&l); 
			    deleter(l);
			    break;
			case 8:
				display();
				break;
			case 9:
				if(size())
				printf("\n Size of generic linked list : %d",size());
				else
				printf("\n Size of generic linked list : 0");
				break;
			case 10:
				printf("\n Exiting");
				break;
			default:
				printf("\n Wrong choice");
		}
	}while(ch!=10);
}
void init()
{
	s=NULL;
}
int size()
{
	node *p=s,*temp;
	int i=0;
	if(s==NULL)
	return i;
	else
	{
		while(p!=NULL)
	    {
		i++;
		p=p->next;
	    }
	    return i;
	}
}
void insertf()
{
	int type,x;
	char y;
	float z;
	node *temp;
	printf("\n 1. Integer \n 2. Character \n 3. Float");
	printf("\n Choose type of data you want to insert : ");
	scanf("%d",&type);
	temp=(node *)malloc(sizeof(node));
	temp->type=type;
	temp->next=NULL;
	switch(type)
	{
		case 1:
			scanf("%d",&x);
			temp->data=malloc(sizeof(int));
			*(int *)temp->data=x;
			break;
		case 2:
			fflush(stdin);
			scanf("%c",&y);
			temp->data=malloc(sizeof(char));
			*(char *)temp->data=y;
			break;
		case 3:
			scanf("%f",&z);
			temp->data=malloc(sizeof(float));
			*(float *)temp->data=z;
			break;
		default:
			printf("\n Wrong choice");
	}
	if(s==NULL)
	s=temp;
	else
	{
		temp->next=s;
		s=temp;
	}
}
void insertl()
{
	int type,x;
	char y;
	float z;
	node *temp,*p;
	printf("\n 1. Integer \n 2. Character \n 3. Float");
	printf("\n Choose type of data you want to insert : ");
	scanf("%d",&type);
	temp=(node *)malloc(sizeof(node));
	temp->type=type;
	temp->next=NULL;
	switch(type)
	{
		case 1:
			scanf("%d",&x);
			temp->data=malloc(sizeof(int));
			*(int *)temp->data=x;
			break;
		case 2:
			fflush(stdin);
			scanf("%c",&y);
			temp->data=malloc(sizeof(char));
			*(char *)temp->data=y;
			break;
		case 3:
			scanf("%f",&z);
			temp->data=malloc(sizeof(float));
			*(float *)temp->data=z;
			break;
		default:
			printf("\n Wrong choice");
	}
	if(s==NULL)
	s=temp;
	else
	{
		for(p=s;p->next!=NULL;p=p->next);
		p->next=temp;
	}
}
void insertr(int pos)
{
	int type,x,i,l=size();
	char y;
	float z;
	node *temp,*p;
	if(pos<1 || pos>(l+1))
	printf("\n Invalid position");
	if(s==NULL)
	s=temp;
    else if(pos==1)
	{
		insertf();
		return;
	}
	else if(pos==l+1)
	{
		insertl();
		return;
	}
	else
	{
		printf("\n 1. Integer \n 2. Character \n 3. Float");
     	printf("\n Choose type of data you want to insert : ");
	    scanf("%d",&type);
	    temp=(node *)malloc(sizeof(node));
	    temp->type=type;
    	temp->next=NULL;
	    switch(type)
	    {
		    case 1:
			scanf("%d",&x);
			temp->data=malloc(sizeof(int));
			*(int *)temp->data=x;
			break;
	     	case 2:
			fflush(stdin);
			scanf("%c",&y);
			temp->data=malloc(sizeof(char));
			*(char *)temp->data=y;
			break;
	    	case 3:
			scanf("%f",&z);
			temp->data=malloc(sizeof(float));
			*(float *)temp->data=z;
			break;
		    default:
			printf("\n Wrong choice");
	    }
	    for(p=s,i=1;i<(pos-1);i++,p=p->next);
	    temp->next=p->next;
	    p->next=temp;
	}
}
void display()
{
	node *p;
	if(s==NULL)
	printf("\n Generic linked list is empty");
	else
	{
		for(p=s;p!=NULL;p=p->next)
		{
			if(p->type==1)
			printf(" %d ",*(int *)p->data);
			else if(p->type==2)
			printf(" %c ",*(char *)p->data);
		    else
			printf(" %f ",*(float *)p->data);
		}
	}
}
void deletef()
{
	node *p=s;
	if(s==NULL)
	printf("\n Generic linked list is empty");
	else
	{
		s=s->next;
		if(p->type==1)	
		printf("\n Deleted element : %d",*(int *)p->data);
		else if(p->type==2)	
		printf("\n Deleted element : %c",*(char *)p->data);
	    else
		printf("\n Deleted element : %f",*(float *)p->data);
		free(p);
	}
}
void deletel()
{
	node *p=s,*t;
	if(s==NULL)
	printf("\n Generic linked list is empty");
	else if(size()==1)
	{
		deletef();
		return;
	}
	else
	{
		for(p=s;p->next!=NULL;t=p,p=p->next);
		t->next=NULL;
		if(p->type==1)	
		printf("\n Deleted element : %d",*(int *)p->data);
		else if(p->type==2)	
		printf("\n Deleted element : %c",*(char *)p->data);
	    else
		printf("\n Deleted element : %f",*(float *)p->data);
		free(p);
	}
}
void deleter(int pos)
{
	node *p=s,*t;
	int l=size(),i;
	if(s==NULL)
	printf("\n Generic linked list is empty");
	else if(pos<1 || pos>l)
	printf("\n Invalid position");
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
		for(p=s,i=1;i<(pos-1);i++,p=p->next);
		t=p->next;
		p->next=t->next;
		if(t->type==1)	
		printf("\n Deleted element : %d",*(int *)t->data);
		else if(t->type==2)	
		printf("\n Deleted element : %c",*(char *)t->data);
	    else
		printf("\n Deleted element : %f",*(float *)t->data);
		free(t);
	}
}
