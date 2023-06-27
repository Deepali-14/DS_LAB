#include<stdio.h>
#define max 5
struct Q
{
	int info[max];
	int R,F;
}lq;
void init();
int overflow();
int underflow();
void display();
int size();
int peek();
void enqueue(int);
int dequeue();
void main()
{
	int ch,y,k;
	lq.F=-1;
	lq.R=-1;
	do
	{
	  printf("\n1.Initialization \n2.Enqueue \n3.Dequeue \n4.Display");
	  printf("\n5.Underflow \n6.Overflow \n7.Size \n8.Peek \n9.Exit");
	  printf("\nEnter your choice : ");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	  	case 1:
	  	        init();
	  	        break;
	  	case 2: 
	  	        printf("\nEnter the element you want to insert : ");
	  	        scanf("%d",&y);
	  	        enqueue(y);
	  	        break;
	  	case 3: 
	  	        k=dequeue();
	  	        if(k!=999)
	  	        printf("\nThe deleted element is %d",k);
	  	        else
	  	        printf("\nThere is no element for deletion");
	  	        break;
	  	case 4: 
	  	        display();
	  	        break;
	  	case 5: 
	  	        if(underflow())
	  	        printf("\nThe linear queue is underflow");
	  	        else
	  	        printf("\nThe linear queue is not underflow");
	  	        break;
	  	case 6: 
	  	        if(overflow())
	  	        printf("\nThe linear queue is overflow");
	  	        else
	  	        printf("\nThe linear queue is not overflow");
	  	        break;
	  	case 7: 
	  	        if(size())
				printf("\nThe size of linear queue is %d",size()); 
				else
				printf("\nThe size of linear queue is 0");
	  	        break;
	  	case 8: 
	  	        if(peek()!=999)
				printf("\nThe peek of linear queue is %d",peek()); 
				else
				printf("\nThe linear queue is empty");
	  	        break;
	  	case 9: 
	        	printf("\nExiting......!");
	  	        break;
	  	default:  
		        printf("\nWe are in default case");
	   }
    }while(ch!=9);	
}
void init()
{
	lq.R=lq.F=-1;
}
int underflow()
{
	if(lq.F==-1)
	return 1;
	else
	return 0;
}
int overflow()
{
	if(lq.R==max-1)
	return 1;
	else 
	return 0;
}
int size()
{
	if(lq.F==-1)
	return 0;
	else 
	return (lq.R-lq.F+1);
}
int peek()
{
	if(lq.F==-1)
	return 999;
	else
	return lq.info[lq.F];
}
void display()
{
	int i;
	if(lq.F==-1)
	printf("\nThe linear queue is empty");
	else
	{
		printf("\nThe linear queue is : \n");
		for(i=lq.F;i<=lq.R;i++)
		printf("%d\t",lq.info[i]);
	}
}
void enqueue(int x)
{
	if(lq.R==max-1)
	printf("\nThe linear queue is overflow");
	else
	{
		if(lq.R==-1)
		lq.F=lq.R=0;
		else
		lq.R++;
		lq.info[lq.R]=x;
	}
}
int dequeue()
{
	int x;
	if(lq.F==-1)
	return 999;
	else
	{
	   x=lq.info[lq.F];
	   if(lq.F==lq.R)
	   lq.F=lq.R=-1;
	   else
	   lq.F++;
	   return x;
	}
}
