#include<stdio.h>
int main()
{
    int i=1,j,a[20],n=10,c=0,flag=0;
    printf("\nEnter first element : ");
    scanf("%d",&a[0]);
    while(c<n-1)
    {
      printf("\nEnter element : ");
      scanf("%d",&a[i]);
      for(j=i-1;j>=0;j--)
      {
        if(a[i]==a[j])
        {
           flag=1;
           printf("\nENTER DIFFERENT ELEMENT");
           break;
        }
        else
           flag=0;
      }
      if(flag!=1)
      {
        c++;
        i++;
      }
    }
    printf("\nUnique 10 elements array : \n");
    for(i=0;i<n;i++)
      printf("%d ",a[i]);
    return 0;
}
