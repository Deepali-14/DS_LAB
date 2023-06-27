//Deepali
//2016736
#include<stdio.h>
#include<malloc.h>
struct bst
{
	int data;
	struct bst *lc;
	struct bst *rc;
};
typedef struct bst BST;
BST * init(BST *);
BST * insert(BST *,int);
BST * search(BST *,int);
void inorder(BST *);
void preorder(BST *);
void main()
{
	BST *R=NULL,*t;
	int n,i=0,x,ch,op;
	printf("\n Deepali \n 2016736");
	do
	{
		printf("\n ***** RECURSIVE BST PROGRAM *****\n");
		printf("\n 1. INITIALIZATION \n 2. INSERT \n 3. DISPLAY \n 4. SEARCH \n 0. EXIT");
		printf("\n Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				R=init(R);
				break;
			case 2:
				printf("\n Enter total elements in BST : ");
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
					printf("\n 1. INORDER \n 2. PREORDER \n 0. EXIT");
				    printf("\n Enter your choice : ");
				    scanf("%d",&op);
				    switch(op)
				    {
					     case 1:
					     	if(R==NULL)
					     	printf("\n Binary tree is empty");
					     	else
					     	inorder(R);
					     	break;
					     case 2:
					     	if(R==NULL)
					     	printf("\n Binary tree is empty");
					     	else
					     	preorder(R);
					     	break;
					     case 0:
					     	break;
					     default:
					     	printf("\n Wrong choice..Try again..!");
				    }
				}while(op!=0);
				break;
			case 4:
				if(R==NULL)
				printf("\n Search not possible as binary tree is empty");
				else
				{
					printf("\n Enter element to search : ");
			    	scanf("%d",&x);
				    t=search(R,x);
				    if(t!=NULL)
				    printf("\n Information found");
				    else
				    printf("\n Information not found");
				}
				break;
			case 0:
				printf("\n Exiting..!");
				break;
			default:
				printf("\n Wrong choice..Try again..!");
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
	BST *temp;
	temp=(BST *)malloc(sizeof(BST));
	temp->data=x;
	temp->lc=temp->rc=NULL;
	if(R==NULL)
	R=temp;
	else
	{
		if(x<R->data)
		R->lc=insert(R->lc,x);
		else if(x>R->data)
		R->rc=insert(R->rc,x);
	}
	return R;
}
BST * search(BST *R,int x) 
{
    BST *t;
    t=R;
    if(t!=NULL) 
    {                
        if(x<t->data)        
	    t=search(R->lc,x);          
        else if (x>t->data)   
	    t=search(R->rc,x);   
    }
    return t;
}
void preorder(BST *R)
{
    if(R!=NULL)
    {
       printf(" %d ",R->data);
       preorder(R->lc);
       preorder(R->rc);
    }
}
void inorder(BST *R)
{
    if(R!=NULL)
    {
       inorder(R->lc);
       printf(" %d ",R->data);
       inorder(R->rc);
    }
}
