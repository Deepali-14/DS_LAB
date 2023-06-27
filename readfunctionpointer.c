#include<stdio.h>
#include<stdlib.h>
char * Read();
void main()
{
   printf("%s",Read());
}
char * Read()
{
   char *p;
   int n;
   printf("\nEnter the number of characters in the string : ");
   scanf("%d",&n);
   fflush(stdin);
   p=(char *)malloc(sizeof(char)*n);
   printf("\nEnter string : ");
   gets(p);
   return p;
}
