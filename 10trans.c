#include<stdio.h>    
int main()
{  
   int a[5][5],trans[5][5],i,j,c,r,sor;    
   printf("Enter number of row : ");    
   scanf("%d",&r);    
   printf("Enter number of column : ");    
   scanf("%d",&c);    
   printf("Enter the matrix element : \n");    
   for(i=0;i<r;i++)    
   {    
       for(j=0;j<c;j++)    
       {    
           scanf("%d",&a[i][j]);
       }    
   }  
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++)  
       {
           printf("%d\t",a[i][j]);
       } 
       printf("\n");   
   }
   for(i=0;i<r;i++)
   {
       for(j=0;j<c;j++) 
       {
          trans[j][i]=a[i][j];
       }
   }
   printf("Transpose of the matrix :\n");
   for(i=0;i<c;i++)
   {
       for(j=0;j<r;j++) 
       {
          printf("%d\t",trans[i][j]);
       }
       printf("\n");
   }
   return 0;
}
