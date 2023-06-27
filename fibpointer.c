#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int * Fibo(int n);
void main()
{
   int n,i;
   int *q;
   printf("\nEnter the number of elements : ");
   scanf("%d",&n);
   q=Fibo(n);
   printf("\nThe Fibonacci series is : \n");
   for(i=0;i<n;i++)
   printf("%d ",*(q+i));
}
int * Fibo(int n)
{
   int *p,i,A,B,C;
   p=(int *)malloc(sizeof(int)*n);
   for(i=0,A=0,B=1;i<n;i++)
   {
     *(p+i)=A;
      C=A+B;
      A=B;
      B=C;
   }
   return p;
}
