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
void postorder(BST *);
void levelorder(BST *);
BST * rdelete(BST *,int);
BST * MinValueNode(BST *);
int height_of_tree(BST *);
void currentlevel(BST *,int);
int count_total(BST *);
int count_term(BST *);
int count_non_term(BST *);
int mindata(BST *);
int maxdata(BST *);
void mirror(BST *);
void cleartree(BST *);
void main()
{
	BST *R=NULL,*t;
	int n,i=0,x,ch,op;
	do
	{
		printf("\n ******** RECURSIVE PROGRAM ********\n");
		printf("\n 1. INITIALIZATION \n 2. INSERT \n 3. DISPLAY \n 4. DELETE \n 5. HEIGHT OR MAX DEPTH \n 6. SEARCH");
		printf("\n 7. COUNT NODES \n 8. MINIMUM DATA \n 9. MAXIMUM DATA \n 10. MIRROR \n 11. CLEAR TREE \n 0. EXIT");
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
					     	inorder(R);
					     	break;
					     case 2:
					     	if(R==NULL)
					     	printf("\n Binary tree is empty");
					     	else
					     	preorder(R);
					     	break;
					     case 3:
					     	if(R==NULL)
					     	printf("\n Binary tree is empty");
					     	else
					     	postorder(R);
					     	break;
					    case 4:
					     	if(R==NULL)
					     	printf("\n Binary tree is empty");
					     	else
					     	levelorder(R);
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
				    R=rdelete(R,x);
				}
				break;
			case 5:
				printf("\n Height or Max depth of tree : %d",height_of_tree(R));
				break;
			case 6:
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
			case 7:
				do
				{
					printf("\n 1. TOTAL NODES \n 2. TERMINAL NODES \n 3. NON-TERMINAL NODES \n 0. EXIT");
				    printf("\n Enter your choice : ");
				    scanf("%d",&op);
				    switch(op)
				    {
					    case 1:
						    i=count_total(R);
						    printf("\n Total no. of nodes : %d",i);
						    break;
					    case 2:
						    i=count_term(R);
						    printf("\n Total no. of terminal nodes : %d",i);
						    break;
				        case 3:
				    	    i=count_non_term(R);
				    	    printf("\n Total no. of non-terminal nodes : %d",i);
				    	    break;
				        case 0:
				    	    break;
				   	    default:
					        printf("\n Wrong choice");
				    }
				}while(op!=0);
				break;
		    case 8:
				if(R==NULL)
				printf("\n Binary tree is empty");
				else
				{
					i=mindata(R);
				    printf("\n Minimum data : %d",i);
				}
				break;
			case 9:
				if(R==NULL)
				printf("\n Binary tree is empty");
				else
				{
					i=maxdata(R);
				    printf("\n Maximum data : %d",i);
				}
				break;
			case 10:
				if(R==NULL)
				printf("\n Binary tree is empty");
				else
				mirror(R);
				break;
			case 11:
				if(R==NULL)
				printf("\n Binary tree is empty");
				else
				cleartree(R);
				R=NULL;
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
void postorder(BST *R)
{
	if(R!=NULL)
    {
       postorder(R->lc);
       postorder(R->rc);
       printf(" %d ",R->data);
    }
}
void levelorder(BST *R)
{
	int h=height_of_tree(R);
	int i;
	for(i=1;i<=h;i++)
	currentlevel(R,i);
}
void currentlevel(BST *R,int l)
{
	if(R==NULL)
	return;
	else if(l==1)
	printf(" %d ",R->data);
	else
	{
		currentlevel(R->lc,l-1);
		currentlevel(R->rc,l-1);
	}
}
int height_of_tree(BST *R)
{
	int lh,rh;
	if(R==NULL)
	return 0;
	else
	{
		lh=height_of_tree(R->lc);
		rh=height_of_tree(R->rc);
		if(lh>rh)
		return(lh+1);
		else
		return(rh+1);
	}
}
int count_total(BST *R)
{
	if(R==NULL)
	return 0;
	else
		return(1+ count_total(R->lc) + count_total(R->rc));
}
int count_term(BST *R)
{
	if(R==NULL)
	return 0;
	else if(R->rc==NULL && R->lc==NULL)
	return 1;
	else
	return(count_term(R->lc)+count_term(R->rc));
}
int count_non_term(BST *R)
{
	if(R==NULL || R->rc==NULL && R->lc==NULL)
	return 0;
	else
	{
		if(R->lc!=NULL || R->rc!=NULL)
			return(1+ count_non_term(R->lc) + count_non_term(R->rc));
	}
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
void mirror(BST *R)
{
	BST *temp;
	if(R==NULL)
	return;
	else
	{
		mirror(R->lc);
		mirror(R->rc);
		temp=R->lc;
		R->lc=R->rc;
		R->rc=temp;
	}
}
void cleartree(BST *R)
{
	if(R!=NULL)
	{
		cleartree(R->lc);
		cleartree(R->rc);
		free(R);
	}
}
BST * MinValueNode(BST *R)
{
    BST *c=R;
    while(c && c->lc!=NULL)
        c=c->lc;
	return c;
}
BST * rdelete(BST *R,int x)
{
	BST *temp;
    if(R==NULL)
        return R;
    if(x<R->data)
        R->lc= rdelete(R->lc,x);
    else if(x>R->data)
        R->rc= rdelete(R->rc,x);
    else 
	{
        if(R->lc==NULL && R->rc==NULL)
            return NULL;
        else if(R->lc==NULL) 
		{
            temp=R->rc;
            free(R);
            return temp;
        }
        else if(R->rc==NULL) 
		{
            temp=R->lc;
            free(R);
            return temp;
        }
        temp=MinValueNode(R->rc);
        R->data=temp->data;
        R->rc=rdelete(R->rc,temp->data);
    }
    return R;
}
