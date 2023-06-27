#include<stdio.h>
#include<malloc.h>
void main()
{
   int *p;
   int n,m,i,j;
   printf("\n Read Row Size and Column Size : ");
   scanf("%d %d",&m,&n);   
   p=(int *)malloc(sizeof(int)*m*n);    
   if (p==NULL)
   printf("\n Memory not available");
   else
   {
      printf("\n Read array elements\n",n);
      for(i=0;i<m;i++) 
      for (j=0;j<n;j++)   
      scanf("%d",(p+n*i+j)); 
      printf("\n Print array elements\n",n);
      for(i=0;i<m;i++)
      for (j=0;j<n;j++)   
      {
          printf("\t%d",*(p+n*i+j)); 
          printf("\t%p\n",(p+n*i+j));
      }
   }
}
