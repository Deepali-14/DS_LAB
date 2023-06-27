#include<stdio.h>
void main()
{
	int A[20],B[20],C[40],n=0,i,j,x,pos,ch,t,found=0,m;
	do
	{
		printf("\n1.Insert first, \n2.Insert last, \n3.Insert random");
		printf("\n4.Delete first, \n5.Delete last, \n6.Delete random");
		printf("\n7.Display, \n8.Exit, \n9.Search, \n10.Insertion sort");
		printf("\n11.Splitting, \n12.Direct Merging");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nWe are in case 1");
				printf("\nRead the value to insert : ");
		    	scanf("%d",&x);
				for(i=n;i>0;i--)
				{
					A[i]=A[i-1];
				}
				A[0]=x;
				n++;
				break;
		    case 2:
		    	printf("\nWe are in case 2");
		    	printf("\nRead the value to insert : ");
		    	scanf("%d",&x);
		    	A[n++]=x;
				break;
			case 3:
				printf("\nWe are in case 3");
				printf("\nRead the value to insert : ");
		    	scanf("%d",&x);
				printf("\nRead the position to insert : ");
		    	scanf("%d",&pos);	
				for(i=n;i>(pos-1);i--)
				    A[i]=A[i-1];
				A[pos-1]=x;
				n++;
				break;
			case 4:
				printf("\nWe are in case 4");
				x=A[0];
		    	for(i=0;i<(n-1);i++)
		    	    A[i]=A[i+1];
		        printf("\ndeleted element is %d",x);
		    	n--;
				break;
			case 5:
				printf("\nWe are in case 5");
				x=A[n-1];
		        printf("\ndeleted element is %d",x);
		    	n--;
				break;
			case 6:
				printf("\nWe are in case 6");
				printf("\nRead the position to delete : ");
		    	scanf("%d",&pos);	
				for(i=pos-1;i<n-1;i++)
				{
					x=A[pos-1];
					A[i]=A[i+1];
				}
		        printf("\ndeleted element is %d",x);
				n--;
				break;
			case 7:
				printf("\nWe are in case 7\n");
				if(n==0)
				   printf("\nNo element to display");
			    else
			   	printf("Elements are : ");
			       for(i=0;i<n;i++)
			    	  printf("%d ",A[i]);
			    printf("\n");
				break;
			case 8:
				printf("\nWe are in case 8");
				break;
			case 9:
				printf("\nWe are in case 9");
				printf("\nEnter element to search : ");
				scanf("%d",&x);
				for(i=0;i<n;i++)
			    {
			    	if(A[i]==x)
			    	{
			    	  printf("\nElement found at location %d",++i);
			    	  found=1;
			        }
	     		}
			   	if(found==0)
			    	printf("\nElement not found");
				break;
			case 10:
				printf("\nWe are in case 10");
				for(i=1;i<n;i++)
				{
					t=A[i];
					j=i-1;
					while((j>=0)&&(A[j]>t))
					{
						A[j+1]=A[j];
						j--;
					}
					A[j+1]=t;
				}
				break;
			case 11:
				printf("\nWe are in case 11");
				printf("\nRead position to split : ");
				scanf("%d",&x);
				for(i=0;i<x;i++)
				    B[i]=A[i];
				for(i=x;i<n;i++)
				    C[i]=A[i];
				printf("\nAfter splitting : ");
				printf("\nArray 1 : ");
				for(i=0;i<x;i++)
				    printf("%d ",B[i]);
				printf("\nArray 2 : ");
			    for(i=x;i<n;i++)
				    printf("%d ",C[i]);
				break;
			case 12:
				printf("\nWe are in case 12");
				printf("\nEnter size of array : ");
				scanf("%d",&m);
				printf("\nEnter elements : ");
				for(i=0;i<m;i++)
			    	scanf("%d",&B[i]);
			    for(i=0;i<n;i++)
			        C[i]=A[i];
			   	for(i=n,j=0;i<(m+n);i++,j++)
			   	    C[i]=B[j];
			   	printf("\nMerged array becomes : ");
			    for(i=0;i<(m+n);i++)
			    	printf("%d ",C[i]);
				break;
			default:
				printf("\nIt is a default case");
		}
    }while(ch!=8);
}
