#include<stdio.h>
#include<malloc.h>
#include<string.h>
union dat
{
    int a;  
    float f;  
    char c; 
    char s[10];  
};
struct node
{
    union dat info;
    struct node *next;
    int type;
};
typedef struct node NODE;
NODE *S=NULL;
void init();
void insertf();
void insertr(int);
void insertl();
void deletef();
void deleter(int);
void deletel();
int size();
void display();
void main()
{
    int ch,op,pos;
    do
    {
        printf("\n 1. Initialisation \n 2. Insertion \n 3. Deletion \n 4. Display \n 5. Size \n 0. Exit");
        printf("\n Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                init();
                break;
            case 2:
            	do
            	{
            		printf("\n 1. Insert First \n 2. Insert Random \n 3. Insert Last \n 0. Exit");
            	    printf("\n Enter your choice : ");
            	    scanf("%d",&op);
            	    switch(op)
            	    {
            		    case 1:
            			    insertf();
            			    break;
            		    case 2:
            		    	printf("\n Enter position to enter at : ");
            		    	scanf("%d",&pos);
            			    insertr(pos);
            			    break;
            		    case 3:
            			    insertl();
            			    break;
            		    case 0:
            		    	break;
            		    default:
            		    	printf("\n Wrong choice");
				    }
				}while(op!=0);
                break;
            case 3:
            	do
            	{
            	 	printf("\n 1. Delete First \n 2. Delete Random \n 3. Delete Last \n 0. Exit");
                	printf("\n Enter your choice : ");
            	    scanf("%d",&op);
            	    switch(op)
            	    {
            		    case 1:
            			    deletef();
            			    break;
            		    case 2:
            			    if(S!=NULL)
            			    {
            			    	printf("\n Enter position to delete from : ");
            		    	    scanf("%d",&pos);
            			        deleter(pos);
							}
							else
							printf("\n Linked list is empty");
            			    break;
            		    case 3:
            			    deletel();
            			    break;
            		    case 0:
            			    break;
            		    default:
            			    printf("\n Wrong choice");
				    }
				}while(op!=0);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\n Size of Linked List : %d",size());
                break;
            case 0:
            	printf("\n Exiting:)");
                break;
            default:
			    printf("\n Wrong choice");
        }
    }while(ch!=0);
}
void init()
{
    S=NULL;
}
void insertf()
{
    int type,x;
    char y;
    float z;
    char st[20];
    NODE *temp;
    printf("\n 1. Integer \t 2. Float \t 3. Character \t 4. String");
    printf("\n Enter type of data you want to insert : ");
    scanf("%d",&type);
    temp=(NODE *)malloc(sizeof(NODE));
    temp->type=type;
    temp->next=NULL;
    switch(type)
    {
        case 1:
        	printf("\n Read Integer : ");
            scanf("%d",&x);
            temp->info.a=x;
            break;
        case 2:
        	printf("\n Read Float : ");
            scanf("%f",&z);
            temp->info.f=z;
            break;
        case 3:
        	printf("\n Read Character : ");
            fflush(stdin);
            scanf("%c",&y);
            temp->info.c=y;
            break;
        case 4:    
            printf("\n Read String : ");
            fflush(stdin);
            gets(st);
            strcpy(temp->info.s,st);
            break;
        default:
        	printf("\n Wrong choice entered");
    }
    if(S==NULL)
        S=temp;
    else
    {
        temp->next=S;
        S=temp;
    }
}
void insertr(int pos)
{
    int type,x,i;
    char y;
    float z;
    char st[20];
    NODE *temp,*p;
    if(pos<1 || pos>(size()+1))
    {
    	printf("\n Wrong position for insertion");
    	return;
	}
    else if(pos==1)
    {
    	insertf();
        return;
	}
	else if(pos==(size()+1))
	{
		insertl();
	    return;
	}
	else
	{
		printf("\n 1. Integer \t 2. Float \t 3. Character \t 4. String: ");
        printf("\n Enter type of data you want to insert : ");
        scanf("%d",&type);
        temp=(NODE *)malloc(sizeof(NODE));
        temp->type=type;
        temp->next=NULL;
        switch(type)
        {
            case 1:
            	printf("\n Read Integer : ");
                scanf("%d",&x);
                temp->info.a=x;
                break;
            case 2:
            	printf("\n Read Float : ");
                scanf("%f",&z);
                temp->info.f=z;
                break;
            case 3:
            	printf("\n Read Character : ");
                fflush(stdin);
                scanf("%c",&y);
                temp->info.c=y;
                break;
            case 4:    
                printf("\n Read String : ");
                fflush(stdin);
                gets(st);
                strcpy(temp->info.s,st);
                break;
            default:
        	    printf("\n Wrong choice entered");
        }
	}
    if(S==NULL)
        S=temp;
    else
    {
    	for(p=S,i=1;i<(pos-1);i++,p=p->next);
    	temp->next=p->next;
    	p->next=temp;
	}
}
void insertl()
{
    int type,x;
    char y;
    float z;
    char st[20];
    NODE *temp,*p;
    printf("\n 1. Integer \t 2. Float \t 3. Character \t 4. String");
    printf("\n Enter type of data you want to insert : ");
    scanf("%d",&type);
    temp=(NODE *)malloc(sizeof(NODE));
    temp->type=type;
    temp->next=NULL;
    switch(type)
    {
        case 1:
        	printf("\n Read Integer : ");
            scanf("%d",&x);
            temp->info.a=x;
            break;
        case 2:
        	printf("\n Read Float : ");
            scanf("%f",&z);
            temp->info.f=z;
            break;
        case 3:
        	printf("\n Read Character : ");
            fflush(stdin);
            scanf("%c",&y);
            temp->info.c=y;
            break;
        case 4:    
            printf("\n Read String : ");
            fflush(stdin);
            gets(st);
            strcpy(temp->info.s,st);
            break;
        default:
        	printf("\n Wrong choice entered");
    }
    if(S==NULL)
        S=temp;
    else
    {
        for(p=S;p->next!=NULL;p=p->next);
        p->next=temp;
    }
}
void deletef()
{
	NODE *p;
	if(S==NULL)
	{
		printf("\n Linked list is empty");
		return;
	}
	else
	{
		p=S;
		S=S->next;
		if(p->type==1)	
		printf("\n Deleted element : %d",p->info.a);
		else if(p->type==2)
		printf("\n Deleted element : %f",p->info.f);
		else if(p->type==3)	
		printf("\n Deleted element : %c",p->info.c);
		else
		{
			printf("\n Deleted element : ");
			puts(p->info.s);
		}
		free(p);	
	}
}
void deleter(int pos)
{
	NODE *p,*t;
	int i;
	if(pos<1 || pos>size())
	{
		printf("\n Wrong position for deletion");
		return;
	}
	else if(pos==1)
	{
		deletef();
		return;
	}
	else if(pos==size())
	{
		deletel();
		return;
	}
    else
	{
		for(p=S,i=1;i<(pos-1);i++,p=p->next);
		t=p->next->next;
		p->next=t;
		if(p->type==1)	
		printf("\n Deleted element : %d",p->info.a);
		else if(p->type==2)
		printf("\n Deleted element : %f",p->info.f);
		else if(p->type==3)	
		printf("\n Deleted element : %c",p->info.c);
		else
		{
			printf("\n Deleted element : ");
			puts(p->info.s);
		}
		free(p);	
	}
}
void deletel()
{
	NODE *p,*t;
	if(S==NULL)
	{
		printf("\n Linked list is empty");
		return;
	}
	else
	{
		for(p=S;p->next!=NULL;t=p,p=p->next);
		t->next=NULL;
		if(p->type==1)	
		printf("\n Deleted element : %d",p->info.a);
		else if(p->type==2)
		printf("\n Deleted element : %f",p->info.f);
		else if(p->type==3)	
		printf("\n Deleted element : %c",p->info.c);
		else
		{
			printf("\n Deleted element : ");
			puts(p->info.s);
		}
		free(p);	
	}
}
int size()
{
    NODE *p=S,*temp;
    int i=0;
    while(p!=NULL)
    {
        i++;
        p=p->next;
    }
    return i;
}
void display()
{
	NODE *p;
    if(S==NULL)
        printf("\n Linked list is empty\n");
    else
    {
    	printf("\n Elements : \n");
        for(p=S;p!=NULL;p=p->next)
        {
            if(p->type==1)
                printf("\t%d",p->info.a);
            else if(p->type==2)
                printf("\t%f",p->info.f);
            else if(p->type==3)
                printf("\t%c",p->info.c);
            else
                printf("\t%s",p->info.s);
        }
    }
}
