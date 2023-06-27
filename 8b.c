#include<stdio.h>
#include<malloc.h>
#define max 10
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
int mindata(BST *);
int maxdata(BST *);
void main()
{
	BST *R=NULL;
	int n,i=0,x,ch,op;
	do
	{
		printf("\n 1. INITIALIZATION \n 2. INSERT \n 3. SEARCH \n 4. MINIMUM ELEMENT \n 5. MAXIMUM ELEMENT \n 0. EXIT");
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
				if(R==NULL)
				printf("\n Search is not possible as binary tree is empty");
				else
				{
					printf("\n Enter element to search : ");
			    	scanf("%d",&x);
				    search(R,x);
				}
				break;
			 case 4:
				if(R==NULL)
				printf("\n Binary tree is empty");
				else
				{
					i=mindata(R);
				    printf("\n Minimum data : %d",i);
				}
				break;
			case 5:
				if(R==NULL)
				printf("\n Binary tree is empty");
				else
				{
					i=maxdata(R);
				    printf("\n Maximum data : %d",i);
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
int mindata(BST *R)
{
	if(R->lc==NULL)
	return R->data;
	else
	return(mindata(R->lc));
}
int maxdata(BST *R)
{
	if(R->rc==NULL)
	return R->data;
	else
	return(maxdata(R->rc));
}
