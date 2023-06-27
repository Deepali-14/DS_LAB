#include<stdio.h>
#define max 5
void init(int *, int *);
int underflow(int *, int *);
int underflow(int *, int *);
void display(int [],int *,int *);
int size(int *, int *);
int peek(int [],int *, int *);
void enqueue(int [],int *, int *, int);
int dequeue(int [],int *, int *);
void main()
{
	int ch,LQ[max],R=-1,F=-1,y,z,k;
	do
	{
	  printf("\n1.Initialization \n2.Enqueue \n3.Dequeue \n4.Display");
	  printf("\n5.Underflow \n6.Overflow \n7.Size \n8.Peek \n9.Exit");
	  printf("\nEnter your choice : ");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	  	case 1: printf("\nWe are in case 1");
	  	        init(&R,&F);
	  	        break;
	  	case 2: printf("\nWe are in case 2");
	  	        printf("\nEnter the element you want to insert : ");
	  	        scanf("%d",&y);
	  	        enqueue(LQ,&R,&F,y);
	  	        break;
	  	case 3: printf("\nWe are in case 3");
	  	        k=dequeue(LQ,&R,&F);
	  	        if(k!=999)
	  	        printf("\nThe deleted element is %d",k);
	  	        else
	  	        printf("\nThere is no element for deletion");
	  	        break;
	  	case 4: printf("\nWe are in case 4");
	  	        display(LQ,&R,&F);
	  	        break;
	  	case 5: printf("\nWe are in case 5");
	  	        if(underflow(&R,&F))
	  	        printf("\nThe linear queue is underflow");
	  	        else
	  	        printf("\nThe linear queue is not underflow");
	  	        break;
	  	case 6: printf("\nWe are in case 6");
	  	        if(overflow(&R,&F))
	  	        printf("\nThe linear queue is overflow");
	  	        else
	  	        printf("\nThe linear queue is not overflow");
	  	        break;
	  	case 7: printf("\nWe are in case 7");
	  	        if(size(&R,&F))
				printf("\nThe size of linear queue is %d",size(&R,&F)); 
				else
				printf("\nThe size of linear queue is 0");
	  	        break;
	  	case 8: printf("\nWe are in case 8");
	  	        if(peek(LQ,&R,&F)!=999)
				printf("\nThe peek of linear queue is %d",(peek(LQ,&R,&F))); 
				else
				printf("\nThe linear queue is empty");
	  	        break;
	  	case 9: printf("\nWe are in case 9");
	        	printf("\nExiting......!");
	  	        break;
	  	default:  
		        printf("\nWe are in default case");
	   }
    }while(ch!=9);	
}
void init(int *R, int *F)
{
	*R=*F=-1;
}
int underflow(int *R, int *F)
{
	if(*F==-1)
	return 1;
	else
	return 0;
}
int overflow(int *R,int *F)
{
	if(*R==max-1)
	return 1;
	else 
	return 0;
}
int size(int *R, int *F)
{
	if(*F==-1)
	return 0;
	else 
	return (*R-*F+1);
}
int peek(int Q[], int *R, int *F)
{
	if(*F==-1)
	return 999;
	else
	return Q[*F];
}
void display(int Q[], int *R, int *F)
{
	int i;
	if(*F==-1)
	printf("\nThe linear queue is empty");
	else
	{
		printf("\nThe linear queue is : \n");
		for(i=*F;i<=*R;i++)
		printf("%d\t",Q[i]);
	}
}
void enqueue (int Q[],int *R,int *F,int x)
{
	if(*R==max-1)
	printf("\nThe linear queue is overflow");
	else
	{
		if(*R==-1)
		*F=*R=0;
		else
		(*R)++;
		Q[*R]=x;
	}
}
int dequeue(int Q[],int *R,int *F)
{
	int x;
	if(*F==-1)
	return 999;
	else
	{
	   x=Q[*F];
	   if(*F==*R)
	   *F=*R=-1;
	   else
	   (*F)++;
	   return x;
	}
}
