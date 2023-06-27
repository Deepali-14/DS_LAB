#include<stdio.h>
#define max 20
void main()
{
   int A[max],n=0,i=0,x,pos,ch;
   do
   {
      printf("\n1.INITIALIZATION \n\tINSERTION \n2.Insert first \n3.Insert last \n4.Insert random");
	  printf("\n\tDELETION \n5.Delete first \n6.Delete last \n7.Delete random \n8.DISPLAY \n9.EXIT");
      printf("\nEnter your choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
      	case 1:	
        printf("\nWe are in case 1");
        n=0;
        break;
        
        case 2:
        printf("\nWe are in case 2");
        printf("\nRead the value to insert : ");
        scanf("%d",&x);
        for(i=n;i>0;i--)
           A[i]=A[i-1];
        A[0]=x;
        n++;
        break;
        
        case 3:
        printf("\nWe are in case 3");
        printf("\nRead the value to insert : ");
        scanf("%d",&x);
        A[n++]=x;
        break;
        
        case 4:
        printf("\nWe are in case 4");
        printf("\nRead the value to insert : ");
        scanf("%d",&x);
        printf("\nRead the position to insert : ");
        scanf("%d",&pos);
        for(i=n;i>(pos-1);i--)
        A[i]=A[i-1];
        A[pos-1]=x;
        n++;
        break;
        
        case 5:
        printf("\nWe are in case 5");
        if(n!=0)
        {
        x=A[0];
        for(i=0;i<(n-1);i++)
        A[i]=A[i+1];
        printf("\nDeleted element is %d",x);
        n--;
        }
        else
        printf("\nNo element for deletion");
        break;
        
        case 6:
        printf("\nWe are in case 6");
        if(n!=0)
        {
        x=A[n-1];
        printf("\nDeleted element is %d",x);
        n--;
        }
        else
        printf("\nNo element for deletion");
        break;
        
        case 7:
        printf("\nWe are in case 7");
        if(n!=0)
		{
        printf("\nRead the position to delete : ");
        scanf("%d",&pos);
        for(i=pos-1;i<n-1;i++)
          A[i]=A[i+1];
        x=A[pos-1];
        printf("\nDeleted element is %d",x);
        n--;
        }
        else
        printf("\nNo element for deletion");
        break;
        
        case 8:
        printf("\nWe are in case 8\n");
        if(n==0)
        printf("\nNo element to display");
        else
        for(i=0;i<n;i++)
        printf("%d ",A[i]);
        break;
        
        case 9:
        printf("\nWe are in case 9");
        break;
        
        default:
        printf("\nIt is a default case\n");
      }
   }while(ch!=0);
}
