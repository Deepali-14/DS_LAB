//Deepali
//2016736
#include<stdio.h>
#define max 5
int LQ[max];
int R=-1,F=-1;
void Init();
int Isempty();
int Isfull();
void Display();
int Size();
void Enqueue(int);
void main()
{
	int ch,x;
	printf("\n Deepali \n 2016736");
	do
	{
	  printf("\n ****** Linear Queue Program ******\n");
	  printf("\n 1. Initialization \n 2. Enqueue \n 3. Display");
	  printf("\n 4. Isempty \n 5. Isfull \n 6. Size \n 0. Exit");
	  printf("\n Enter your choice : ");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	  	case 1: 
	  	        Init();
	  	        break;
	  	case 2: 
	  	        if(R!=max-1)
	  	        {
	  	       	    printf("\n Enter the element you want to insert : ");
	  	            scanf("%d",&x);
	  	            Enqueue(x);
				}
				else
				printf("\n The linear queue is full");
				break;
	  	case 3:
	  	        Display();
	  	        break;
	  	case 4: 
	  	        if(Isempty())
	  	        printf("\n The linear queue is empty");
	  	        else
	  	        printf("\n The linear queue is not empty");
	  	        break;
	  	case 5:
	  	        if(Isfull())
	  	        printf("\n The linear queue is full");
	  	        else
	  	        printf("\n The linear queue is not full");
	  	        break;
	  	case 6:
	  	        if(Size())
				printf("\n Size of linear queue : %d",Size()); 
				else
				printf("\n Size of linear queue : 0");
	  	        break;
	  	case 0: 
	        	printf("\n Exiting..!");
	  	        break;
	  	default:  
		        printf("\n Wrong choice..Try again..!");
	   }
    }while(ch!=0);	
}
void Init()
{
	R=F=-1;
}
int Isempty()
{
	if(F==-1)
	return 1;
	else
	return 0;
}
int Isfull()
{
	if(R==max-1)
	return 1;
	else 
	return 0;
}
int Size()
{
	if(F==-1)
	return 0;
	else 
	return (R-F+1);
}
void Display()
{
	int i;
	if(F==-1)
	printf("\n The linear queue is empty");
	else
	{
		printf("\n The linear queue is : \n");
		for(i=F;i<=R;i++)
		printf("%d\t",LQ[i]);
	}
}
void Enqueue(int x)
{
	if(R==max-1)
	printf("\n The linear queue is full");
	else
	{
		if(R==-1)
		F=R=0;
		else
		(R)++;
		LQ[R]=x;
	}
}
