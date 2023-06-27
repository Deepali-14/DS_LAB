#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 100
int R=-1,F=-1;
char LQ[max][max];
void Enqueue(char []) ;
char * Dequeue();
int SizeLQ();
void Display();
int main()
{
int ch;
char *e;
char st[20];
do
    {
        printf("\n1.Enqueue \n2.Dequeue \n3.Size \n4.Display \n5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter element to be inserted : ");    
                   fflush(stdin);
                   gets(st);
                   Enqueue(st); 
                   break;
			case 2:e=Dequeue();
                   printf("\nThe deleted element is : %s\n",e);
                   break;
            case 3:printf("\nSize of Linear Queue  is : %d\n",SizeLQ());
                   break;
            case 4:printf("\nLinear Queue now is: ");
                   Display();
                   break;
            case 5:printf("\nExiting....!");
                   break; 
			default:
			      printf("\nWrong choice entered!\n");                         
        }
    } while (ch!=5);
    return 0;
}
void Enqueue(char st[])   
{
if (R==(max-1))
printf("\nLinear Queue Overflow");
else 
{
if(R==-1) 
F=R=0;
else 
R++;
strcpy(LQ[R],st); 
}
}
char * Dequeue()
{
	char *x;
    x=(char *) malloc(sizeof(char)*max);
    if(F==-1)
    {
        printf("\nLinear Queue underflow");
        strcpy(x,"No Element");  
    }
else
{
strcpy(x,LQ[F]);   
if (F==R) F=R=-1;
else F++;
}
return x;
}
int SizeLQ()
{
if (F==-1) return 0;
else  return(R-F+1);
}
void Display()
{
int i;
if (F==-1)
printf("\nQueue Empty");
else
{
for(i=F;i<=R;i++)
printf("\n%s",LQ[i]);  
}
}

