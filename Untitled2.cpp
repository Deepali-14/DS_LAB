#include<iostream>
using namespace std;
#define max 5
int cq[mAX];
int F=-1, R=-1;
void init();
int size();
int peek();
int isFull();
int isEmpty();
void enqueue(int) ;
int dequeue();
void display();
int main()
{
	cout<<"\n ************************** CIRCULAR QUEUE *************************"<<endl;
	int ch,y,z,k;
	do
	{
		cout<<"\n 1.Initialization \n 2.Enqueue \n 3.Dequeue \n 4.Display";
		cout<<"\n 5.Isfull \n 6.Isempty \n 7.Size \n 8.Peek \n 9.Exit"<<endl;
		cout<<"\n Enter your choice : "<<endl;
		cin>>ch;
		switch(ch)
		{
		  	case 1: 
		  	        init();
		  	        break;
		  	case 2: 
		  	        cout<<"\n Enter the element you want to insert : "<<endl;
		  	        cin y;
		  	        enqueue(y);
		  	        break;
		  	case 3: 
		  	        k=dequeue();
		  	        if(k!=999)
		  	        cout<<"\n The deleted element is "<<k<<endl;
		  	        else
		  	        printf("\n There is no element for deletion");
		  	        break;
		  	case 4: 
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
	return 0;
}
void init()
{
	R=-1;
	F=-1;
}
void enqueue(int x)
{
	if(isfull)
		cout<<"\n Circular queue is full"<<endl;
	if(F==-1)
		F=0;
	R=(R+1)%max;
	cq[R]=x;
}
void dequeue()
{
	if(isempty)
		return 999;
	int m=cq[F];
	if(F==R)
		R=F=-1;
	else
		F=(F+1)%max;
	return m;
}
int isfull()
{
	if((F==0 && R==max-1) || F==R+1)
		return 1;
	else 
		return 0;
}
int isempty()
{
	if(F==-1)
		return 1;
	else
		return 0;
}
int size()
{
	if(isempty)
		return 0;
	else if(R>=F)
		return R-F+1;
	else
		return max-F+R+1;
}
int peek()
{
	if(isempty)
		return 999;
	else
		cq[F];
}
void display()
{
	if(isempty)
		cout<<"\n The circular queue is empty"<<endl;
	else 
	{
	    printf("\n Circular queue -> ");
	    for(i=F; i!=R; i=(i+1)%SIZE) 
		{
	      cout<<" "<<cq[i]<<" ";
	    }
	    cout<<" "<<cq[i]<<" ";
	}
}
