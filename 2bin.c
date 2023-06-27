#include<stdio.h>
#include<malloc.h>
#define max 100
struct bst
{
	int data;
	struct bst *lc;
	struct bst *rc;
};
typedef struct bst BST;
BST * init(BST *);
BST * insert(BST *,int);
void search(BST *,int);
void nrinorder(BST *);
void nrpreorder(BST *);
void nrpostorder(BST *);
void nrlevelorder(BST *);
BST * nrdelete(BST *,int);
void main()
{
	BST *R=NULL;
	int n,i=0,x,ch,op;
	do
	{
		printf("\n ******** NON-RECURSIVE PROGRAM ********\n");
		printf("\n 1. INITIALIZATION \n 2. INSERT \n 3. DISPLAY \n 4. DELETE \n 5. SEARCH \n 0. EXIT");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				R=init(R);
				break;
			case 2:
				printf("\n Enter total no. of elements in the binary tree : ");
	            scanf("%d",&n);
	            i=0;
	            while(i<n)
	            {
	            	i++;
		            printf("\n Enter element to insert : ");
		            scanf("%d",&x);
		            R=insert(R,x);
	            }
				break;
			case 3:
				do
				{
					printf("\n 1. INORDER DISPLAY \n 2. PREORDER DISPLAY \n 3. POSTORDER DISPLAY \n 4. LEVELORDER DISPLAY \n 0. EXIT");
				    printf("\n Enter your choice : ");
				    scanf("%d",&op);
				    switch(op)
				    {
					     case 1:
					     	if(R==NULL)
					     	printf("\n Binary tree is empty");
					     	else
					     	nrinorder(R);
					     	break;
					     case 2:
					     	if(R==NULL)
					     	printf("\n Binary tree is empty");
					     	else
					     	nrpreorder(R);
					     	break;
					     case 3:
					     	if(R==NULL)
					     	printf("\n Binary tree is empty");
					     	else
					     	nrpostorder(R);
					     	break;
					     case 4:
					     	if(R==NULL)
					     	printf("\n Binary tree is empty");
					     	else
					     	nrlevelorder(R);
					     	break;
					     case 0:
					     	break;
					     default:
					     	printf("\n Wrong choice");
				    }
				}while(op!=0);
				break;
			case 4:
			    if(R==NULL)
				printf("\n Deletion not possible as binary tree is empty");
				else
				{
					printf("\n Enter element to be deleted : ");
				    scanf("%d",&x);
				    R=nrdelete(R,x);
				}
				break;
			case 5:
				if(R==NULL)
				printf("\n Search not possible as binary tree is empty");
				else
				{
					printf("\n Enter element to search : ");
			    	scanf("%d",&x);
				    search(R,x);
				}
				break;
			case 0:
				printf("\n Exiting");
				break;
			default:
				printf("\n Wrong choice");
		}
	}while(ch!=0);
}
BST * init(BST *R)
{
	R=NULL;
	return R;
}
BST * insert(BST *R,int x)
{
	BST *temp,*p,*t;
	temp=(BST *)malloc(sizeof(BST));
	temp->data=x;
	temp->lc=temp->rc=NULL;
	if(R==NULL)
	R=temp;
	else
	{
		t=R;
		while(t!=NULL)
		{
			p=t;
			if(x<t->data)
			t=t->lc;
			else if(x>t->data)
			t=t->rc;
			else
			{
				printf("\n Duplicate information");
				return R;
			}
		}
		if(p->data>x)
	    p->lc=temp;
    	else
	    p->rc=temp;
	}
	return R;
}
void search(BST *R,int x) 
{
    BST *t;
    t=R;
    while(t!=NULL) 
    {                
        if(x<t->data)        
	    t=t->lc;                
        else if (x>t->data)   
	    t=t->rc;
        else
        {  
	        printf("\n Information found"); 
	        return;
	    } 
    }
    printf("\n Information not found");
}
void nrpreorder(BST *R)
{
   BST *stk[10],*t;
   int top=-1;
   t=R;
   do
   {
        while(t!=NULL)
        { 
            printf(" %d ",t->data);
            stk[++top]=t;
            t=t->lc;
        }
        t=stk[top--]; 
        t=t->rc;
   }while(t!=NULL || top>-1);   
}
void nrinorder(BST *R)
{
   BST *stk[10],*t;
   int top=-1;
   t=R;
   do
    {
        while(t!=NULL)
        {
            stk[++top]=t;
            t=t->lc;
        } 
        t=stk[top--];
        printf(" %d ",t->data);
        t=t->rc;
    }while(t!=NULL || top>-1);   
}
void nrlevelorder(BST *R)
{
	BST *queue[max],*t;
	int f=0,r=-1;
	t=R;
	queue[++r]=t;
	while(f<=r)
	{
		t=queue[f++];
		if(t!=NULL)
		{
			printf(" %d ",t->data);
			queue[++r]=t->lc;
			queue[++r]=t->rc;
		}
	}
}
void nrpostorder(BST *R)
{
	BST *stk1[max],*stk2[max],*t;
	int t1=-1,t2=-1;
	stk1[++t1]=R;	
	while(t1!=-1)
	{
		R=stk1[t1--];
		stk2[++t2]=R;
		if(R->lc)
		stk1[++t1]=R->lc;
		if(R->rc)
		stk1[++t1]=R->rc;	
	}
	while(t2!=-1)
	printf(" %d ",stk2[t2--]->data);
}
BST * nrdelete(BST *R, int x)
{
    BST *t,*p,*q,*t1,*t2,*t3;
    if(R==NULL)
    {
        printf("\n Deletion not possible as binary tree is empty");
        return R;
    }
    else
    {
        t=R;
        while((t!=NULL) && (x!=t->data))
        {
            p=t;
            if(x<t->data)
            t=t->lc;
            else if(x>t->data)
            t=t->rc;
        }
    }
    if(t==NULL)
    {
        printf("\n Element not found");
        return R;
    }
    else if(t==R)
    {
    	p=t1=t->lc;
    	t2=t->rc;
    	while(t1->rc!=NULL)
    	t1=t1->rc;
    	t1->rc=t2;
    	R=p;
    	free(t);
    	return R;
	}
    else
    {
        if((t->lc==NULL)&&(t->rc==NULL))
        {
            if(t->data<p->data)
            p->lc=NULL;
            else
            p->rc=NULL;
        }
        else if((t->lc!=NULL)&&(t->rc==NULL))
        {
            if(t->data<p->data)
            p->lc=t->lc;
            else
            p->rc=t->lc;
        }
        else if((t->lc==NULL)&&(t->rc!=NULL))
        {
            if(t->data<p->data)
            p->lc=t->rc;
            else
            p->rc=t->rc;
        }
        else 
        {
            t1=t->lc;
            t2=t->rc;
            while(t1->rc!=NULL)
            t1=t1->rc;
            t1->rc=t2;
            if(t->data<p->data)
            p->lc=t->lc;
            else
            p->rc=t->lc;
        }
    }
    free(t);
    return R;
}
