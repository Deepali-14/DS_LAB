#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct studrecord
{
   int studid;      
   char studname[20];  
};
int Read(struct studrecord x[]);
void Print(struct studrecord y[],int n); 
void Sort(struct studrecord y[],int n);
void main()
{
   struct studrecord s[100];
   int ch,n=0;
   static int i=0;
   do
   {
      printf("\n1.Read \n2.Print \n3.Sort \n4.Exit");
      printf("\nEnter your choice : ");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1: 
        n=Read(s);
        break;
        case 2:
	    Print(s,n);
	    break;
        case 3:
	    Sort(s,n);
	    break;
        case 4:
	    printf("\nExiting.....!");
	    break;
        default:
    	printf("\nWrong choice entered!");
      }
    }while(ch!=4);
}
int Read(struct studrecord x[])
{
    static int i=0;
    printf("\nRecord %d\n",i+1);
    printf("ID : ");
    scanf("%d",&x[i].studid);
    fflush(stdin);
    printf("NAME : ");
    gets(x[i].studname);
    return (++i);
}
void Print(struct studrecord y[],int n)   
{
	int j;
	if(n==0)
	{
		printf("\n......NO DETAIL FOUND...... \n");
	}
	else
	{
	printf("\n......DETAILS......\n");
	for(j=0;j<n;j++)
	{
	  printf("Record no. %d\n",j+1);
      printf("ID : %d\n",y[j].studid);
      printf("NAME : %s\n",y[j].studname);
      printf("\n");
    }
    } 
}
void Sort(struct studrecord y[],int n)
{
    struct studrecord t;
    int j,k,ch;
    if(n==0)
	{
		printf("\n......NO DETAIL FOUND FOR SORTING...... \n");
	}
	else
	{
	do
    {
    printf("\n1.Sort on name \n2.Sort on id");
    printf("\nEnter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
    for(j=0;j<n;j++)
    for(k=j+1;k<n;k++)
    if (strcmp(y[j].studname,y[k].studname)>0)
    {
       t=y[j];
       y[j]=y[k];
       y[k]=t;
    }
    Print(y,n);
    break;
    case 2:
    for(j=0;j<n;j++)
    for(k=j+1;k<n;k++)
    if (y[j].studid>y[k].studid)
    {
      t=y[j];
      y[j]=y[k];
      y[k]=t;
    }
    Print(y,n);
    break;
    default :
    printf("\nWrong choice entered!");
    }
    }while((ch!=1)&&(ch!=2));
    }
}
