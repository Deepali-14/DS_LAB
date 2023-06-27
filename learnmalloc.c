#include<stdio.h>
#include<malloc.h>
void main()
{
   int *p;
   int n,i;
   printf("\n Read size of array : ");
   scanf("%d",&n);
   p=(int *)malloc(sizeof(int)*n);
   if(p==NULL)
   printf("\n Memory not available");
   else
   {
      printf("\n Read %d array elements\n",n);
      for(i=0;i<n;i++)
      scanf("%d",(p+i));
      printf("\n Print %d array elements\n",n);
      for(i=0;i<n;i++)
      printf("%d\t",*(p+i));
   }
}
