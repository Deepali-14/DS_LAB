#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
char stack[max][max];  
int top=-1;
int overflow();
int underflow();
void push(char []) ; 
char * pop();
void display();
void main()
{
    int ch;
    char *t;
    char st[20];
    do
    {
        printf("\n1.Push \n2.Pop \n3.Display \n4.Underflow \n5.Overflow \n6.Exit \n");
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter subject : ");
                   fflush(stdin);
                   gets(st);   
                   push(st);
                   break;
            case 2: t=pop();
                   printf("\nThe deleted element is : %s \n",t);
                   break;
            case 3:if(underflow()==1)
                   printf("\nNO SUBJECTS FOR DISPLAY\n");
                   else
                   {
			       printf("\nTHE SUBJECTS ARE :");
                   display();
                   }
                   break;
            case 4:if(underflow()==1)
                   printf("\nStack underflow\n");
                   else
                   printf("\nStack is not underflow\n");  
                   break;      
            case 5:if(overflow()==1)
                   printf("\nStack overflow\n");
                   else
                   printf("\nStack is not overflow\n");  
                   break;
            case 6:printf("\nExiting....!");
                   break;  
			default: printf("\nWrong choice entered!\n");                     
        }
    }while (ch!=6);
}
int overflow()
{
    if(top==(max-1))
    return 1;
    else
    return 0;
}
int underflow()
{
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(char st[])  
{
    if(overflow()==1)
         printf("Stack overflow");
    else
    {
        top++;
        strcpy(stack[top],st); 
    }
}
char * pop()
{
    char *x;
    x=(char *) malloc(sizeof(char)*max);
    
    if(underflow()==1)
    {
        printf("Stack underflow");
        strcpy(x,"No Element");  
    }
    else
    {
        strcpy(x,stack[top]);   
        top--;
    }
    return x;
}
void display()
{
	int j;
    for (j=top;j>=0;j--)
    printf("\n%s",stack[j]);  
}

