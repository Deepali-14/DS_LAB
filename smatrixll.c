#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct smatrix 
{
	int r;
	int c;
	int v;
	struct smatrix *next;
};
typedef struct smatrix smatrix;
smatrix * addnode(smatrix *,int,int,int);
void display(smatrix *);
void main()
{
	smatrix *sm=NULL;
	int i,j,m[10][10],r,c,count=0;
	printf("\n Enter number of rows in matrix : ");
	scanf("%d",&r);
	printf("\n Enter number of columns in matrix : ");
	scanf("%d",&c);
	do
	{
		count=0;
		printf("\n ******* Enter elements of matrix ******* \n");
    	for(i=0;i<r;i++)
	    for(j=0;j<c;j++)
	    scanf("%d",&m[i][j]);
	    for(i=0;i<r;i++)
	    for(j=0;j<c;j++)
	    {
		   if(m[i][j]==0)
		   count++;
    	}
	}while(count<=((r*c))/2);
	printf("\n ******* Display elements of matrix ******* \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		printf(" %d ",m[i][j]);
		printf("\n");
	}
    for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	{
		if(m[i][j]!=0)
		sm=addnode(sm,i,j,m[i][j]);
	}
	display(sm);
}
smatrix * addnode(smatrix *sm,int x,int y,int z)
{
	smatrix *temp;
	smatrix *p;
	temp=(smatrix *)malloc(sizeof(smatrix));
	temp->r=x;
	temp->c=y;
	temp->v=z;
	temp->next=NULL;
	if(sm==NULL)
	sm=temp;
	else
	{
		for(p=sm;p->next!=NULL;p=p->next);
		p->next=temp;
	}
	return sm;
}
void display(smatrix *sm)
{
	smatrix *p;
	if(sm==NULL)
	printf("\n ******* Sparse matrix is empty *******");
	else
	{
		printf("\n ******* Sparse matrix in linked list form *******\n In the format row no. col no. value -> is given below\n");
		for(p=sm;p->next!=NULL;p=p->next)
		printf(" %d %d %d ->",p->r,p->c,p->v);
		printf(" %d %d %d ",p->r,p->c,p->v);
	}
}
