#include<stdio.h>
#define N 4
int Q[N],P[N];
int r=-1,f=-1;
void init();
void display();
void enqueue(int,int);
void dequeue();
int isempty();
int isfull();
int size();
int peek();
int main()
{
	int ch,data,p,i,n;
	do
	{
		printf("\n 1. Initializtion \n 2. Enqueue \n 3. Display \n 4. Dequeue");
		printf("\n 5. Size \n 6. Peek \n 7. Isempty \n 8. Isfull \n 9. Exit");
		printf("\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				init();
				break;
			case 2:
				printf("\n Enter the number of data : ");
				scanf("%d",&n);
				printf("\n Enter your data and priority of data : ");
				i=0;
				while(i<n)
				{
					printf("\n Insert %d : ",i+1);
					scanf("%d %d",&data,&p);
					enqueue(data,p);
					i++;
				}
				break;
			case 3:
				display();
				break;
			case 4:
				dequeue();
				break;
			case 5:
				if(size())
				printf("\nThe size of priority queue is %d",size()); 
				else
				printf("\nThe size of priority queue is 0");
				break;
			case 6:
				if(peek()!=999)
				printf("\nThe peek of priority queue is %d",peek()); 
				else
				printf("\nThe priority queue is empty");
	  	        break;
			case 7:
				if(isempty())
	  	        printf("\nThe priority queue is empty");
	  	        else
	  	        printf("\nThe priority queue is not empty");
	  	        break;
			case 8:
				if(isfull())
	  	        printf("\nThe priority queue is full");
	  	        else
	  	        printf("\nThe priority queue is not full");
	  	        break;
			case 9:
				printf("\nWe are exiting...!");
				break;
			default:
				printf("\nIncorrect Choice");
		}
	}while(ch!=9);
    return 0;
}
void init()
{
	r=f=-1;
}
int isempty()
{
	if(f==-1)
	return 1;
	else
	return 0;
}
int isfull()
{
	if(r==N-1)
	return 1;
	else 
	return 0;
}
int size()
{
	if(f==-1)
	return 0;
	else 
	return (r-f+1);
}
int peek()
{
	if(f==-1)
	return 999;
	else
	return Q[f];
}
void enqueue(int d,int p)
{
	int i;
	if((f==0)&&(r==N-1)) 
	printf("\nQueue is full");
	else
	{
		if(f==-1)
		{
			f=r=0;
			Q[r]=d;
			P[r]=p;
		}
		else if(r==N-1)
		{
			for(i=f;i<=r;i++) 
			{ 
			    printf("\n%d",i);
			    printf("\n%d",f);
			    printf("\n%d",r);
			    Q[i-f]=Q[i]; 
				P[i-f]=P[i]; 
				r=r-f; 
				f=0; 
				for(i=r;i>f;i--)
				{
					if(p>P[i])
					{
						Q[i+1]=Q[i];
						P[i+1]=P[i];
					}
					else
					break;
					Q[i+1]=d;
					P[i+1]=p;
					r++;
				}
			}
		}
		else
		{
			for(i=r;i>=f;i--)
			{
				if(p>P[i])
				{
					Q[i+1]=Q[i];
					P[i+1]=P[i];	
				}
				else
				break;
			}
			Q[i+1]=d;
			P[i+1]=p;
			r++;
		}	
	}
}
void display()
{
    int i;
    if(f==-1)
	printf("\nQueue is Empty");	
	else
	for(i=f;i<=r;i++)
	printf("\nElement = %d\tPriority = %d",Q[i],P[i]);
}
void dequeue() 
{
	if(f==-1)
	printf("\nQueue is Empty");	
	else
	{
		printf("\nDeleted Element = %d\tPriority = %d",Q[f],P[f]);
		if(f==r)
		f=r=-1;
		else
		f++;
	}
}
