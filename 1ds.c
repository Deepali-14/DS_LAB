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
BST * nrdelete(BST *,int);
int height_of_tree(BST *);
int count_total(BST *);
int count_term(BST *);
int count_non_term(BST *);
int mindata(BST *);
int maxdata(BST *);
void mirror(BST *);
void cleartree(BST *);
void main()
{
	BST *R=NULL;
	int n,i=0,x,ch,op;
	do
	{
		printf("\n 1. INITIALIZATION \n 2. INSERT \n 3. DISPLAY \n 4. DELETE \n 5. HEIGHT \n 6. SEARCH");
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
					printf("\n 1. INORDER DISPLAY \n 2. PREORDER DISPLAY \n 3. POSTORDER DISPLAY \n 0. EXIT");
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
				printf("\n Height or Max depth of tree : %d",height_of_tree(R));
				break;
			case 6:
				if(R==NULL)
				printf("\n Search not possible as binary tree is empty");
				else
				{
					printf("\n Enter element to search : ");
			    	scanf("%d",&x);
				    search(R,x);
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
int count_total(BST *R)
{
   int c=0;
   BST *stk[10],*t;
   int top=-1;
   t=R;
   if(R==NULL)
   return c;
   else
   {
   	    do
        {     
            while(t!=NULL)
            {
                stk[++top]=t;
                t=t->lc;
            } 
            t=stk[top--];
            c++;
            t=t->rc;
        }while(t!=NULL || top>-1); 
		return c;  
   }
}
int count_term(BST *R)
{
   int tc=0;
   BST *stk[10],*t;
   int top=-1;
   t=R;
   if(R==NULL)
   return tc;
   else
   {
   	    do
        {     
            while(t!=NULL)
            {
                stk[++top]=t;
                t=t->lc;
            } 
            t=stk[top--];
            if(t->lc==NULL && t->rc==NULL)
            tc++;
            t=t->rc;
        }while(t!=NULL || top>-1); 
		return tc;  
   }
}
int count_non_term(BST *R)
{
   int ntc=0;
   BST *stk[10],*t;
   int top=-1;
   t=R;
   if(R==NULL)
   return ntc;
   else
   {
   	    do
        {     
            while(t!=NULL)
            {
                stk[++top]=t;
                t=t->lc;
            } 
            t=stk[top--];
            if(t->lc==NULL && t->rc==NULL)
            ntc++;
            t=t->rc;
        }while(t!=NULL || top>-1); 
		return ntc;  
   }
}
int mindata(BST *R)
{
	while(R->lc!=NULL)
	R=R->lc;
	return R->data;
}
int maxdata(BST *R)
{
	while(R->rc!=NULL)
	R=R->rc;
	return R->data;
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
