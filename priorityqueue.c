#include<stdio.h>
#define max 5
int D[max],P[max];
int R=-1,F=-1;
void init();
void desarr();
void display();
void enqueue(int,int);
void dequeue();
int underflow();
int overflow();
int size();
int peek();
int main()
{
	int ch,n,data,p,i;
	do
	{
		printf("\n 1. Initialization \n 2. Enqueue \n 3. Display \n 4. Dequeue");
		printf("\n 5. Size \n 6. Peek \n 7. Underflow \n 8. Overflow \n 9. Exit");
		printf("\n Enter Your Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				init();
				break;
			case 2:
				if(R<max-1)
				{
			    	printf("\n Enter the number of data : ");
			    	scanf("%d",&n);
			    	printf("\n Enter your data and priority of data : ");
			    	for(i=0;i<n;i++)
			 	    {
				    	if(R==max-1)
				    	printf("\n The priority queue is full");
				    	else
				    	{
				    	   printf("\n Insert %d : ",i+1);
					       printf("\n Data : ");
					       scanf("%d",&data);
				    	   printf(" Priority : ");
				    	   scanf("%d",&p);
					       enqueue(data,p);
				        }
			     	}
			    }
			    else
			    printf("\n The priority queue is full");
				break;
			case 3:
				desarr();
				display();
				break;
			case 4:
				dequeue();
				break;
			case 5:
				if(size())
				printf("\n The size of priority queue is %d",size()); 
				else
				printf("\n The size of priority queue is 0");
				break;
			case 6:
				if(peek()!=-999)
				printf("\n The peek of priority queue is %d",peek()); 
				else
				printf("\n The priority queue is empty");
	  	        break;
			case 7:
				if(underflow())
	  	        printf("\n The priority queue is empty");
	  	        else
	  	        printf("\n The priority queue is not empty");
	  	        break;
			case 8:
				if(overflow())
	  	        printf("\n The priority queue is full");
	  	        else
	  	        printf("\n The priority queue is not full");
	  	        break;
			case 9:
				printf("\n We are exiting...!");
				break;
			default:
				printf("\n Incorrect choice");
		}
	}while(ch!=9);
    return 0;
}
void init()
{
	R=F=-1;
}
int underflow()
{
	if(F==-1)
	return 1;
	else
	return 0;
}
int overflow()
{
	if(R==max-1)
	return 1;
	else 
	return 0;
}
int size()
{
	if(F==-1)
	return 0;
	else 
	return (R-F+1);
}
int peek()
{
	if(F==-1)
	return -999;
	else
	return D[F];
}
void display()
{
    int i;
    if(F==-1)
	printf("\n The priority queue is empty");	
	else
	for(i=F;i<=R;i++)
	printf("\n Element = %d\tPriority = %d",D[i],P[i]);
}
void enqueue(int d,int p)
{
    if(F==-1)
	{
		F=R=0;
		D[R]=d;
		P[R]=p;
	}
	else
	{
		R++;
		D[R]=d;
		P[R]=p;
	}
}
void desarr()
{
	int i,j,t,m;
	for(i=F;i<=R-1;i++)
	{
		m=i;
		for(j=i+1;j<=R;j++)
		  if(P[m]<P[j])
		    m=j;
		t=P[i];
		P[i]=P[m];
		P[m]=t;
		t=D[i];
		D[i]=D[m];
		D[m]=t;
	}
}
void dequeue()
{
	if(F==-1)
	printf("\n The priority queue is empty");	
	else
	{
		printf("\n Deleted element = %d\tPriority = %d",D[F],P[F]);
		if(F==R)
		F=R=-1;
		else
		F++;
	}
}
