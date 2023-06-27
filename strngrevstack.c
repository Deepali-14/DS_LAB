#include<stdio.h>  
#include<string.h>    
#define MAX 50
void push(char);
void pop();
int top;
char stack[MAX];  
int main()  
{  
   char str[MAX];
   printf("\nEnter the string : ");
   gets(str);  
   int len=strlen(str);  
   int i;  
   for(i=0;i<len;i++)  
    push(str[i]);  
   for(i=0;i<len;i++)  
    pop(); 
   return 0; 
}  
void push(char x)
{    
      if(top==MAX-1) 
          printf("\nStack overflow");   
	  else  
          stack[++top]=x;  
}  
void pop()
{  
      printf("%c",stack[top--]);  
}  
