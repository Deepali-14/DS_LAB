#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct student
{
	char name[100];
	struct student *next;
};
typedef struct student student;
student *start=NULL;
void create(int);
student * createnode(char []);
void display();
void main()
{
	int n;
	printf("\n Enter number of elements in the linked list : ");
	scanf("%d",&n);
	create(n);	
	display();
}
void create(int n)
{
	student *p,*temp;
	int i;
	char name[100];
	printf("\n Enter element to insert in the linked list - \n");
	for(i=0;i<n;i++)
	{
		printf("\n Element %d : ",i+1);
		fflush(stdin);
	    gets(name);
	    temp=createnode(name);
		if(start==NULL)
		start=temp;
		else
		{
			for(p=start;p->next!=NULL;p=p->next);
			p->next=temp;
		}
	}
}
student * createnode(char name[])
{
	student *temp;
	temp=(student *)malloc(sizeof(student));
	strcpy(temp->name, name);
	temp->next=NULL;
	return temp;
}
void display()
{
	student *p;
	if(start==NULL)
		printf("\n Linked list is empty");
	else
	{
		printf("\n Linked list : \n");
		for(p=start;p->next!=NULL;p=p->next)
    	printf("%s -> ",p->name);
    	printf("%s",p->name);
	}
}
