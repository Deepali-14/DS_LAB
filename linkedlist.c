#include<stdio.h>
#include<malloc.h>
struct node
{
  int info;
  struct node *next;
};
typedef struct node NODE;
NODE *S;
void Init();
NODE * Createnode(int);
void InsertF(int);
void InsertL(int);
void Insertsp(int, int);
int size();
int DeleteF();
int DeleteL();
int Deletesp(int);
void Display();
void main()
{
	int ch,n,pos;
	int r,s,t;
	do
	{
	  printf("\n 1. Initialization\n 2. Insert First\n 3. Insert Random\n 4. Insert Last");
	  printf("\n 5. Delete First\n 6. Delete Random\n 7. Delete Last\n 8. Display\n 9. Size\n 10. Exit");
      printf("\n Enter your choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
      	case 1:
      		     printf("\nWe are in case 1");
      		     Init();
      	 	     break;
      	case 2:
      		     printf("\nWe are in case 2");
      		     printf("\nEnter the element you want to insert : ");
      		     scanf("%d",&n);
      		     InsertF(n);
      	 	     break;
      	case 3:  
		         printf("\nWe are in case 3");
		         printf("\nEnter the element you want to insert : ");
      		     scanf("%d",&n);
      		     InsertL(n);
      	 	     break;
      	case 4:
      		     printf("\nWe are in case 4");
      		     printf("\nEnter the element you want to insert : ");
      		     scanf("%d",&n);
      		     printf("\nEnter the position where you want to insert : ");
      		     scanf("%d",&pos);
      		     Insertsp(n,pos);
      	 	     break;
      	case 5:
      		     printf("\nWe are in case 5");
      		     r=DeleteF();
      		     if(r==0)
      		     printf("\nLinked list empty");
      		     else 
      		     printf("\nDeleted element is %d",r);
      	 	     break;
      	case 6:  
      	         printf("\nWe are in case 6");
      	         printf("\nEnter the position where you want to insert : ");
      		     scanf("%d",&pos);
      		     s=Deletesp(pos);
      		     if(s==0)
      	         printf("Invalid position unable to delete"); 
      	         else 
      		     printf("\nDeleted element is %d",s);
      	 	     break;
      	case 7:
      		     printf("\nWe are in case 7");
      		     t=DeleteL();
      		     if(t==0)
      		     printf("\nLinked list empty");
      		     else 
      		     printf("\nDeleted element is %d",t);
      	 	     break;
      	case 8:
      		     Display();
      	 	     break;
      	case 9:
      		     if(size())
      		     printf("\nThe size of the linked list is %d",size());
      		     else
      		     printf("\nLinked list empty");
      	 	     break;
      	case 10:
      	         printf("\nWe are exiting....GOOD BYE:)");
      	 	     break;
      	default:
      		     printf("\nWrong choice entered....!");
	  }
    }while(ch!=10);
}
void Init()
{
  S=NULL;
}
NODE * Createnode(int x)
{
  NODE *TEMP;
  TEMP=(NODE *)malloc(sizeof(NODE));
  TEMP->info = x;
  TEMP->next =NULL;
  return (TEMP);
}
void InsertF(int x)
{
  NODE *temp;
  temp = Createnode(x);
  if (S==NULL)
  S=temp;
  else 
  {
    temp->next=S;
    S=temp;
  }
}
void InsertL(int x)
{
  NODE *temp,*p;
  temp = Createnode(x);
  if (S==NULL)
  S=temp;
  else 
  {
    for(p=S;p->next!=NULL;p=p->next);
    p->next=temp;
  }
}
void Insertsp(int x,int pos)
{
  NODE *p;
  int i,l;
  l=size(); 
  if (pos <0 || pos > (l+1))
  {
    printf("\nInsertion not possible");
    return ;
  }
  if (pos==1)
  {
    InsertF(x);
    return ;
  }
  if (pos==(l+1))
  {
    InsertL(x);
    return ;
  }
  if (pos >1 && pos <=l)
  {
    NODE *temp;
    temp = Createnode(x);
    for (p=S,i=1;i<(pos-1);i++,p=p->next);
    temp->next=p->next;
    p->next=temp;
  }
}
int size()
{
  NODE *p;
  int i;
  if (S==NULL)
  return 0;
  else
  {
  	for(p=S,i=0; p!=NULL; i++,p=p->next);
    return (i);
  }
}
int DeleteF()
{
 if (S==NULL)
 return 0;
 else
 {
    NODE *p;
	int x;
	p=S;
	S=p->next;
	x=p->info;
	free(p);
	return (x);
 }	
}
int DeleteL()
{
 if (S==NULL)
 return 0;
 else if (size()==1)   
 return(DeleteF());	
 else
 {
   NODE *p,*t;
   int x;
   int i;
   for(p=S,i=1;i<(size()-1);i++,p=p->next);
   t=p->next;
   p->next=NULL;
   x=t->info;
   free(t);
   return (x);
 }
}
int Deletesp(int pos)
{
 if (S==NULL)
 return 0;
 else
 {
	int l=size();
	if (pos <0 || pos > l)	
	   return 0; 
	else if (pos==1)
	   return(DeleteF());	
	else if (pos==l)   
 	   return(DeleteL());	
 	else  
 	{
 		NODE *p,*t;
		int x,i; 	
		for (p=S,i=1;i<(pos-1);i++,p=p->next);
		t=p->next;
		p->next=t->next;
		x=t->info;
		free(t);
		return (x);
	 }
  }
}
void Display()
{
 if (S==NULL)
 printf("\nLinked list empty");	
 else
 {
	NODE *p;
	for(p=S;p!=NULL;p=p->next)  
	printf("%d\t",p->info);  
 }
} 
