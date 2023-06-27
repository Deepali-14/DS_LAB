#include <stdio.h>
#define SIZE 5
int cq[SIZE];
int f=-1, r=-1;
void init();
int size();
int peek();
int isFull();
int isEmpty();
void enqueue(int) ;
int dequeue();
void display();
void main()
{
	int ch,y,z,k;
	do
	{
	  printf("\n 1.Initialization \n 2.Enqueue \n 3.Dequeue \n 4.Display");
	  printf("\n 5.Isfull \n 6.Isempty \n 7.Size \n 8.Peek \n 9.Exit");
	  printf("\n Enter your choice : ");
	  scanf("%d",&ch);
	  switch(ch)
	  {
	  	case 1: printf("\n We are in case 1");
	  	        init();
	  	        break;
	  	case 2: printf("\n We are in case 2");
	  	        printf("\n Enter the element you want to insert : ");
	  	        scanf("%d",&y);
	  	        enqueue(y);
	  	        break;
	  	case 3: printf("\n We are in case 3");
	  	        k=dequeue();
	  	        if(k!=999)
	  	        printf("\n The deleted element is %d",k);
	  	        else
	  	        printf("\n There is no element for deletion");
	  	        break;
	  	case 4: printf("\n We are in case 4");
	  	        display();
	  	        break;
	  	case 5: printf("\n We are in case 5");
	  	        if(isFull())
	  	        printf("\n The circular queue is full");
	  	        else
	  	        printf("\n The circular queue is not full");
	  	        break;
	  	case 6: printf("\n We are in case 6");
	  	        if(isEmpty())
	  	        printf("\n The circular queue is empty");
	  	        else
	  	        printf("\n The circular queue is not empty");
	  	        break;
	  	case 7: printf("\n We are in case 7");
	  	        if(size())
				printf("\n The size of circular queue is %d",size()); 
				else
				printf("\n The size of circular queue is 0");
	  	        break;
	  	case 8: printf("\n  We are in case 8");
	  	        if(peek()!=999)
				printf("\n The peek of circular queue is %d",(peek())); 
				else
				printf("\n The circular queue is empty");
	  	        break;
	  	case 9: printf("\n We are in case 9");
	        	printf("\n Exiting......!"); 
	  	        break;
	  	default:  
		        printf("\n We are in default case");
	   }
    }while(ch!=9);	
}
void init()
{
	r=f=-1;
}
int size()
{
	if(f==-1)
	return 0;
	else if(r>=f)
	return (r-f+1);
	else
	return (SIZE-f+r+1);
}
int peek()
{
	if(f==-1)
	return 999;
	else
	return cq[f];
}
int isFull() 
{
  if((f==r+1)||(f==0 && r==SIZE-1)) 
  return 1;
  else
  return 0;
}
int isEmpty() 
{
  if (f==-1) 
  return 1;
  else
  return 0;
}
void enqueue(int m) 
{
  if (isFull())
    printf("\n Queue is full!! \n");
  else 
  {
    if (f==-1) 
	f=0;
    r=(r+1)%SIZE;
    cq[r]=m;
  }
}
int dequeue() 
{
  int m;
  if (isEmpty()) 
    return 999;
  else 
  {
    m=cq[f];
    if(f==r) 
	{
      f=-1;
      r=-1;
    } 
    else 
	{
      f=(f+1)%SIZE;
    }
    return(m);
  }
}
void display() 
{
  int i;
  if (isEmpty())
    printf(" \n The circular queue is empty \n");
  else 
  {
    printf("\n Front -> %d ", f);
    printf("\n Circular queue -> ");
    for(i=f; i!=r; i=(i+1)%SIZE) 
	{
      printf("%d ", cq[i]);
    }
    printf("%d ", cq[i]);
    printf("\n Rear -> %d \n", r);
  }
}


