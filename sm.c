#include<stdio.h>
void main()
{
    int i,j,m[10][10],r,c,count=0,size=0,l;
    printf("\n Enter number of rows in matrix : ");
    scanf("%d",&r);
    printf("\n Enter number of columns in matrix : ");
    scanf("%d",&c);
    do
    {
        count=0;
        printf("\n ******* Enter elements of matrix ******* \n");
        for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        scanf("%d",&m[i][j]);
        for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        {
            if(m[i][j]==0)
            count++;
        }
    }while(count<=((r*c))/2);
    printf("\n ******* Display elements of matrix ******* \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        printf(" %d ",m[i][j]);
        printf("\n");
    }
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    {
        if(m[i][j]!=0)
        size++;
    }
    int k=0,sm[3][size];
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    {
        if(m[i][j]!=0)
        {
            sm[0][k]=i;
            sm[1][k]=j;
            sm[2][k]=m[i][j];
            k++;
        }
    }
    printf("\n ******* Displaying elements of sparse matrix in the form of array ******* \n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<size;j++)
        printf(" %d ",sm[i][j]);
        printf("\n");
    }
    printf("\n ******* Displaying elements of sparse matrix in the form of full array ******* \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            {
            	if(m[i][j]==sm[k][l])
            	printf(" %d ",sm[i][j]);
			}
            printf(" 0 ");
		}
       	printf("\n");
	}
}
