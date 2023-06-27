#include<stdio.h>
#define max 7
int deq[max];
int R=-1,F=-1;
void init();
int underflow();
int overflow();
void enqueue_rear(int);
void dequeue_front();
void dequeue_rear();
void get_front();
void get_rear();
void display();
void main()
{
	int ch,a;
	do
	{
		printf("\n1.Initialization \n2.Insert from rear \n3.Delete from front \n4.Delete from rear");
		printf("\n5.Display \n6.Underflow \n7.Overflow \n8.Get front \n9.Get rear \n10.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				init();
				break;
			case 2:
				printf("\nEnter element to insert : ");
				scanf("%d",&a);
				enqueue_rear(a);
				break;
			case 3:
				dequeue_front();
				break;
			case 4:
				dequeue_rear();
				break;
			case 5:
				display();
				break;
			case 6:
				if(underflow())
				printf("\nDeque is empty");
				else
				printf("\nDeque is not empty");
				break;
			case 7:
				if(overflow())
				printf("\nDeque is full");
				else
				printf("\nDeque is not full");
				break;
			case 8:
				get_front();
				break;
			case 9:
				get_rear();
				break;
			case 10:
				printf("\nWe are exiting!!!!");
				break;
			default:
				printf("\nWrong choice eneterd");
		}
		
	}while(ch!=11);
}
void init()
{
	R=F=-1;
}
void enqueue_rear(int x)
{
	if((F==0 && R==max-1)|| (F==R+1))
	{
		printf("\nDeque is full");
	}
	else if(F==-1 && R==-1)
	{
		F=R=0;
		deq[R]=x;
	}
	else if(R==max-1)
	{
		R=0;
		deq[R]=x;
	}
	else
	{
		R++;
		deq[R]=x;
	}
}
void display()
{
	int i=F; 
	if(F==-1 && R==-1) 
	printf("\nDeque is empty");
	else
	{
		printf("\nElements : \n");  
        while(i!=R)  
        {  
           printf("%d ",deq[i]);  
           i=(i+1)%max;  
        }  
        printf("%d",deq[R]);  
	}
}
void dequeue_front()
{
	if(F==-1 && R==-1)
	{
		printf("\nDeque is empty");
	}
	else if(F==R)
	{
		printf("\nDeleted element : %d",deq[F]);
		F=R=-1;
	}
	else if(F==max-1)
	{
		printf("\nDeleted element : %d",deq[F]);
		F=0;
	}
	else
	{
		printf("\nDeleted element : %d",deq[F]);
		F++;
	}
}
void dequeue_rear()
{
	if(F==-1 && R==-1)
	{
		printf("\nDeque is empty");
	}
	else if(F==R)
	{
		printf("\nDeleted element : %d",deq[R]);
		F=R=-1;
	}
	else if(R==0)
	{
		printf("\nDeleted element : %d",deq[R]);
		R=max-1;
	}
	else
	{
		printf("\nDeleted element : %d",deq[R]);
		R--;
	}
}
void get_front()
{
	if(F==-1 && R==-1)
	printf("\nDeque is empty");
	else
	printf("\nValue at front : %d",deq[F]);
}
void get_rear()
{
	if(F==-1 && R==-1)
	printf("\nDeque is empty");
	else
	printf("\nValue at rear : %d",deq[R]);
}
int underflow()
{
	if(F==-1 && R==-1)
	return 1;
	else
	return 0;
}
int overflow()
{
	if((F==0 && R==max-1)|| (F==R+1))
	return 1;
	else
	return 0;
}
