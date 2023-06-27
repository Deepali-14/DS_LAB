#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *start=NULL,*f=NULL;
void init();
Node * createnode(int);
void insertf(int);
void insertl(int);
void insertr(int,int);
void insertm(int);
void display();
int deletef();
int deletel();
int deleter(int);
int deletem();
void delspdata(int);
void insertsorted(int);
int size();
void lsearch(int);
void reversell();
void splitll(int);
void sort();
void sortedmerge(Node *);
void dupremoval();
void main()
{
	int ch,a,b,c,d,loc,pos,r,s,t,u,key,x,y,l;
	do
	{
		printf("\n 1. Initialization \n 2. Insert First \n 3. Insert Random \n 4. Insert Middle \n 5. Insert Last \n 6. Display");
	    printf("\n 7. Delete First \n 8. Delete Random \n 9. Delete Middle \n 10. Delete Last \n 11. Delete specific data");
	    printf("\n 12. Insert in sorted linked list \n 13. Reverse linked list \n 14. Split linked list");
		printf("\n 15. Duplicate removal \n 16. Sort \n 17. Sorted merging \n 18. Size \n 19. Search \n 20. Exit");
	    printf("\n Enter your choice : ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		    case 1: 
		       init();
		       break;
	    	case 2: 
	    	   printf("\n Enter element to insert : ");
	    	   scanf("%d",&a);
	    	   insertf(a);
		       break;
	    	case 3: 
	    	   printf("\n Enter element to insert : ");
	    	   scanf("%d",&b);
	    	   printf("\n Enter position to insert : ");
	    	   scanf("%d",&loc);
	    	   insertr(b,loc);
		       break;
		    case 4:
		       printf("\n Enter element to insert : ");
	    	   scanf("%d",&c);
	    	   insertm(c);
	    	   break;
		    case 5: 
		       printf("\n Enter element to insert : ");
	    	   scanf("%d",&d);
	    	   insertl(d);
		       break;
	    	case 6: 
	    	   display();
		       break;
		    case 7: 
		       r=deletef();
		       if(r==-999)
		       printf("\n Linked list is empty");
		       else
		       printf("\n Deleted element : %d",r);
		       break;
		    case 8: 
		       printf("\n Enter position to delete : ");
		       scanf("%d",&pos);
		       s=deleter(pos);
		       if(s==-999)
		       printf("\n Linked list is empty");
		       else if(s==-9999)
		       printf("\n Deletion not possible");
		       else
		       printf("\n Deleted element : %d",s);
		       break;
		    case 9:
		       t=deletem();
		       if(t==-999)
		       printf("\n Linked list is empty");
		       else
		       printf("\n Deleted element : %d",t);
		       break;
		    case 10: 
		       u=deletel();
		       if(u==-999)
		       printf("\n Linked list is empty");
		       else
		       printf("\n Deleted element : %d",u);
		       break;
		    case 11:
		       printf("\n Enter data to be deleted : ");
		       scanf("%d",&x);
		       delspdata(x);
		       break;
		    case 12:
		    	printf("\n Enter data to be inserted : ");
		    	scanf("%d",&y);
		    	insertsorted(y);
		    	break;
		    case 13:
		    	reversell();
		    	break;
		    case 14:
		    	printf("\n Enter position to split Linked list : ");
		    	scanf("%d",&l);
		    	splitll(l);
		    	break;
		    case 15: 
		        dupremoval();
		        break;
		    case 16:
		    	sort();
		    	break;
		    case 17:
		    	sort();
		    	sortedmerge(start);
		    	break;
		    case 18: 
		       if(size())
		       printf("\n Size of Linked list : %d",size());
		       else
		       printf("\n Size of Linked list : 0");
		       break;
		    case 19:
		       printf("\n Enter element to search : ");
	           scanf("%d",&key);
		       lsearch(key);
		       break;
		    case 20: 
		       printf("\n We are exiting..Good Bye..!");
		       break;
		    default:
		       printf("\n Wrong choice entered..!");
	    }
	}while(ch!=19);
}
void init()
{
	start=NULL;
}
Node * createnode(int x)
{
	Node *temp;
	temp=(Node *)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}
void insertf(int x)
{
	Node *temp;
	temp=createnode(x);
	if(start==NULL)
	start=temp;
	else
	{
		temp->next=start;
		start=temp;
	}
}
void insertl(int x)
{
	Node *temp,*p;
	temp=createnode(x);
	if(start==NULL)
	start=temp;
	else
	{
		for(p=start;p->next!=NULL;p=p->next);
		p->next=temp;
	}
}
void insertr(int x,int pos)
{
	Node *temp,*p;
	int i,l=size();
	if(start==NULL)
	printf("\n Linked list is empty");
	else if(pos<1 || pos>(l+1))
	{
		printf("\n Insertion not possible");
		return;
	}
	else if(pos==1)
	{
		insertf(x);
		return;
	}
	else if(pos==(l+1))
	{
		insertl(x);
		return;
	}
	else 
	{
		temp=createnode(x);
		for(p=start,i=1;i<pos-1;i++,p=p->next);
		temp->next=p->next;
		p->next=temp;
		return;
	}
}
void insertm(int x)
{
	Node *temp,*p;
    int i;
    if(start==NULL)
    {
    	temp=createnode(x);
    	start=temp;
	}
    else
	{
		temp=createnode(x);
		for(p=start,i=1;i<(size()/2);i++,p=p->next);
		temp->next=p->next;
		p->next=temp;
	}
}
int size()
{
	Node *p;
	int c;
	if(start==NULL)
	return 0;
	else
	{
		for(p=start,c=0;p!=NULL;c++,p=p->next);
	    return c;
	}
}
int deletef()
{
	Node *p;
	int x;
	if(start==NULL)
	return -999;
	else
	{
	   	p=start;
	   	start=p->next;
	   	x=p->data;
	   	free(p);
	   	return x;
	}
}
int deletel()
{
	Node *p,*t;
	int i,x;
	if(start==NULL)
	return -999;
	else if(size()==1)
	{
		deletef();
		return;
	}
	else
	for(p=start,i=1;i<(size()-1);i++,p=p->next);
	t=p->next;
	p->next=NULL;
	x=t->data;
	free(t);
	return x;
}
int deleter(int pos)
{
	Node *p,*t;
	int l=size(),x,i;
	if(start==NULL)
	return -999;
	else 
	{
		if(pos<1 || pos>l)
		return -9999;
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
			for(p=start,i=1;i<(pos-1);i++,p=p->next);
			t=p->next;
			p->next=t->next;
			x=t->data;
			free(t);
			return x;
		}
	}
}
int deletem()
{
	Node *p,*t;
	int x,i;
	if(start==NULL)
	return -999;
	else if(size()==1)
	{
		t=start;
		start=NULL;
		x=t->data;
		free(t);
		return x;
	}
	else
	{
		for(p=start,i=1;i<(size()/2);i++,p=p->next);
		t=p->next;
		p->next=t->next;
		x=t->data;
		free(t);
		return x;
	}
}
void delspdata(int x)
{
	Node *p=start,*t;
	int flag=0;
	while(p!=NULL)
	{
		if(p==start)
		{
			if(start->data==x)
			{
				flag++;
				start=start->next;
				p=start;
			}
			else
			{
				t=p;
				p=p->next;
			}
		}
		else if(p->data==x)
		{
			flag++;
			t->next=p->next;
			p=t->next;
		}
		else
		{
			t=p;
			p=p->next;
		}
	}
	if(flag==0)
		printf("\n Element not found");
}
void display()
{
	Node *p,*t;
	if(start==NULL)
	{
		printf("\n Linked list is empty");
	}
	else
	{
		printf("\n Linked list : \n");
		for(p=start;p!=NULL;p=p->next)
    	printf("%d\t",p->data);
	}
	if(f==NULL)
	{
	    return;
	}
	else
	{
		printf("\n Linked list : \n");
		for(t=f;t!=NULL;t=t->next)
    	printf("%d\t",t->data);
    	return;
	}
}
void lsearch(int y)
{
	Node *p;
	int c=0,i;
	if(start==NULL)
	printf("\n Linked list is empty");
	else
	{
		for(p=start,i=1;p!=NULL;i++,p=p->next)
		{
			if(y==p->data)
			{
			    printf("\n %d found at %d position",y,i);
			    c++;
			}
		}
		if(c==0)
		printf("\n %d not found",y);
		else
		printf("\n %d found %d times",y,c);
	}
}
void insertsorted(int y)
{
	Node *p,*t,*temp;
	temp=createnode(y);
	if(start==NULL)
	{
		start=temp;
		return;
	}
	else
	{
	    p=start;
	    while(p!=NULL)
	    {
		    if(p==start)
		    {
			   if(temp->data<start->data)
			   {
				   temp->next=start;
				   start=temp;
				   p=start;
				   return;
			   }
			   else
			    {
				   t=p;
				   p=p->next;
			    }
		    }
		    else if(temp->data<p->data)
		    {
			    temp->next=t->next;
			    t->next=temp;
			    p=temp->next;
			    return;
		    }
		    else if(p->next==NULL && temp->data>p->data)
		    {
		    	p->next=temp;
		    	return;
			}
		    else
		    {
			    t=p;
			    p=p->next;
		    }
	    }
    }
}
void reversell()
{
	Node *p=NULL,*n,*c;
	n=c=start;
	if(start==NULL || start->next==NULL)
	{
		return;
	}
	else
	{
		while(n!=NULL)
	    {
		   n=n->next;
		   c->next=p;
		   p=c;
		   c=n;
	    }
	    start=p;
	    return;
	}
}
void splitll(int y)
{
	int i;
	Node *f,*p;
	if(start==NULL || y>size() || y<size())
	{
		return;
	}
	else
	for(p=start;i=1,i<(y-1);i++,p=p->next);
	{
		f=p->next;
        p->next=NULL;
        return;
	}
}
void sort()
{
    Node *p,*t,*f=NULL;
    p=t=start;
    if(start==NULL || start->next==NULL)
    return;
    else
    { 
        for(p=start;p!=NULL;p=p->next)
        {
        	for(t=p->next;t!=NULL;t=t->next)
        	{
        		if(t->data>p->data)
        		{
        			if(p==start)
        			{
        				p->next=t->next;
        				start=t;
        				t->next=p;
					}
					else if(t!=start)
                    {
                       f->next=t->next;
                       t->next=p->next;
                       p->next=f->next;
                    }     
                    else
                    {
                       f=t;
                       t=p;
                    }
				}
				else
				continue;
			}
        }
        return;
    }
}
void sortedmerge(Node * start)
{
	Node *p,  *temp, *q;
	int num, i, n;
	printf("\n Enter the number of nodes in the linked list : ");
	scanf("%d",&num);
	while(i<num)
	{
		printf("\n Enter data : ");
		scanf("%d",&n);
		temp=createnode(n);
		if(start==NULL)
		start=temp;
		else
		{
			for(f=start;f->next!=NULL;f=f->next);
			f->next=temp;
		}
		i++;
	}
	if(start==NULL && f==NULL)
	return;
	else if(start!=NULL && f==NULL)
	return;
	else
	{
		p=start;
		q=f;
		while(start!=NULL && f!=NULL)
		{
			if(p->data<q->data)
			{
				insertl(p->data);
				p=p->next;
			}
			else if(q->data<p->data)
			{
				insertl(q->data);
				q=q->next;
			}
			else
			{
				insertl(p->data);
				insertl(q->data);
				p=p->next;
				q=q->next;
			}
		}
		while(p!=NULL)
		{
			insertl(p->data);
			p=p->next;
		}
		while(q!=NULL)
		{
			insertl(q->data);
			q=q->next;
		}
	}
}
void dupremoval()
{
	Node *p=start,*t,*q; 
	if(start==NULL)
	{
		return;
	}
	else
	{
		while(p!=NULL)
		{
			if(p==start)
	        {
		       q=start->next;
		       if(p->data==q->data)
		       {
		     	   start=q;
		     	   p=start;
		       }
		       else
		       {
		       		t=p;
		    		p=p->next;
			   }
        	}
        	else
        	{
        		if(t->data==p->data)
			    {
				   q=p->next;
				   t->next=q;
				   p=q;
			    }
			    else
			    {
			    	t=p;
			    	p=p->next;
				}
			}
		}
	}
}
