#include<stdio.h>
int main()
{
    int n;
    do
	{
	  printf("\nEnter number : ");
      scanf("%d",&n);
      if(n<0)
        printf("\nENTER POSITIVE NUMBER\n");
    }while(n<0);
      printf("\nNumber = %d",n);
    return 0;
}
