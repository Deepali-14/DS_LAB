#include<stdio.h>
#include<stdlib.h>
struct poly
{
	int co;
	int ex;
	struct poly *next;
};
typedef struct poly poly;
poly * create(poly *);
poly * addnode(poly *,int,int);
poly * addpoly(poly *,poly *, poly *);
poly * subpoly(poly *,poly *, poly *);
poly * mulpoly(poly *,poly *, poly *);
void display(poly *);
void main()
{
	int ch;
	poly *p1=NULL, *p2=NULL, *add=NULL, *sub=NULL, *mul=NULL;
	do
	{
		printf("\n 1. Creation \n 2. Addition \n 3. Subtraction \n 4. Multiplication \n 5. Exit");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n ***** CREATING POLYNOMIAL 1 ***** : \n");
				p1=create(p1);
				display(p1);
				printf("\n ***** CREATING POLYNOMIAL 2 ***** : \n");
	            p2=create(p2);
	            display(p2);
				break;
			case 2:
				add=addpoly(add,p1,p2);
				display(add);
				break;
			case 3:
				sub=subpoly(sub,p1,p2);
				display(sub);
				break;
			case 4: 
			    mul=mulpoly(mul,p1,p2);
			    display(mul);
			    break;
			case 5:
				printf("\n Exiting");
				break;
			default:
				printf("\n Wrong choice");
		}
	}while(ch!=5);
}
poly * addnode(poly *p, int co, int ex)
{
	poly *temp,*q;
	temp=(poly *)malloc(sizeof(poly));
	temp->co=co;
	temp->ex=ex;
	temp->next=NULL;
	if(p==NULL)
	p=temp;
	else
	{
	    for(q=p;q->next!=NULL;q=q->next);
		q->next=temp;	
	}
	return p;
}
poly * create(poly *p)
{
	int ex,co;
	do
	{
		printf("\n Enter coeffecient and exponent of polynomial : ");
		scanf("%d %d",&co,&ex);
		p=addnode(p,co,ex);	
	}while(ex!=0);	
	return p;
}
poly * addpoly(poly *add, poly *p1, poly *p2)
{
	poly *p,*q;
	p=p1;
	q=p2;
	while(p!=NULL && q!=NULL)
	{
		if(p->ex > q->ex)
		{
			add=addnode(add,p->co,p->ex);
			p=p->next;
		}
		else if(q->ex > p->ex)
		{
			add=addnode(add,q->co,q->ex);
			q=q->next;
		}
		else
		{
			add=addnode(add,(p->co + q->co),p->ex);
			p=p->next;
			q=q->next;
		}
	}
	while(p!=NULL)
	{
		add=addnode(add,p->co,p->ex);
		p=p->next;
	}
	while(q!=NULL)
	{
		add=addnode(add,q->co,q->ex);
		q=q->next;
	}
	return add;
}
poly * subpoly(poly *sub, poly *p1, poly *p2)
{
	poly *p,*q;
	p=p1;
	q=p2;
	while(p!=NULL && q!=NULL)
	{
		if(p->ex > q->ex)
		{
			sub=addnode(sub,p->co,p->ex);
			p=p->next;
		}
		else if(q->ex > p->ex)
		{
			sub=addnode(sub,-(q->co),q->ex);
			q=q->next;
		}
		else
		{
			sub=addnode(sub,(p->co - q->co),p->ex);
			p=p->next;
			q=q->next;
		}
	}
	while(p!=NULL)
	{
		sub=addnode(sub,p->co,p->ex);
		p=p->next;
	}
	while(q!=NULL)
	{
		sub=addnode(sub,q->co,q->ex);
		q=q->next;
	}
	return sub;
}
poly * mulpoly(poly *mul, poly *p1, poly *p2)
{
	poly *p,*q;
	for(p=p1;p!=NULL;p=p->next)
	for(q=p2;q!=NULL;q=q->next)
	mul=addnode(mul,(p->co * q->co),(p->ex + q->ex));
	return mul;
}
void display(poly *p)
{
   poly *t;
   if(p==NULL)
   printf("\n Polynomial is empty");
   else
   {
   	    printf("\n Required Polynomial : \n");
        for(t=p;t->next!=NULL;t=t->next)
        printf(" (%d x^%d) + ",t->co,t->ex);
        printf(" (%d x^%d) ",t->co,t->ex);
   }
}
