//Deepali
//2016736
#include<stdio.h>
#include<stdlib.h>
#define max 5
int R=-1,F=-1;
int cq[max];
void init();
int overflow();
int underflow();
void enqueue(int);
void dequeue();
void display();
int size();
int peek();
void main()
{
	int ch;
	char y,k;
	printf("\n Deepali \n 2016736 \n");
	do
	{
	  printf("\n ******** CIRCULAR QUEUE WITH CHARACTER DATA TYPE ******** \n");
	  printf("\n 1.Initialization \n 2.Enqueue \n 3.Dequeue \n 4.Display");
	  printf("\n 5.Underflow \n 6.Overflow \n 7.Size \n 8.Peek \n 9.Exit");
	  printf("\n Enter your choice : ");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	  	case 1:
	  		init();
	  		break;
	  	case 2:
	  		printf("\n Enter the element you want to insert : ");
	  		fflush(stdin);
	  	    scanf("%c",&y);
	  	    enqueue(y);
	  		break;
	  	case 3:
	  		dequeue();
	  		break;
	  	case 4:
	  		display();
	  		break;
	  	case 5:
	  		if(underflow())
	  		printf("\n The Circular queue is empty");
	  		else
	  		printf("\n The Circular queue is not empty");
	  		break;
	  	case 6:
	  		if(overflow())
	  		printf("\n The Circular queue is full");
	  		else
	  		printf("\n The Circular queue is not full");
	  		break;
	  	case 7:
	  		printf("\n The size of the Circular queue is %d",size());
	  		break;
	  	case 8:
	  		k=peek();
	  		if(k==0)
	  		printf("\n The Circular queue is empty");
	  		else
	  		printf("\nThe peek of the Circular queue is %c",k);
	  		break;
	  	case 9:
	  		printf("\n We are exiting!!!");
	  		printf("\n Thankyou :)");
	  		break;
	  	default:
	  	    printf("\n Wrong choice entered!!!");
	  }
    }while(ch!=9);
}
void init()
{
	R=F=-1;
}
int overflow()
{
	if(F==R+1 || F==0 && R==max-1)
	return 1;
	else 
	return 0;
}
int underflow()
{
	if(F==-1)
	return 1;
	else
	return 0;
}
void enqueue(int y)
{
	if(overflow())
	printf("\n The Circular queue is full");
	else
	{
		if(F==-1)
		R=F=0;
		else if(R==max-1)
		R=0;
		else
		R++;
		cq[R]=y;	
	}
}
void dequeue()
{
	int x;
	if(underflow())
	printf("\n The Circular queue is empty");
	else
	{
		x=cq[F];
		if(F==R)
		F=R=-1;
		else if(F==max-1)
		F=0;
		else
		F++;	
		printf("\n The deleted element is %c",x);
	}
}
void display()
{
	int i;
	if(underflow())
	printf("\n The Circular queue is empty");
	else
	{
		if(R>=F)
		for(i=F;i<=R;i++)
		printf("%c ",cq[i]);
		else
		{
			for(i=F;i<max;i++)
			printf("%c ",cq[i]);
			for(i=0;i<=R;i++)
			printf("%c ",cq[i]);
		}
	}
}
int size()
{
	if(F==-1)
	return 0;
	else if(R>=F)
	return(R-F+1);
	else
	return(max-F+R+1);
}
int peek()
{
	if(F==-1)
	return 0;
	else
	return cq[F];
}
