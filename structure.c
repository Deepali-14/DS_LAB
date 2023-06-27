#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
struct customer
{
	int id, walletamt;
	char name[20];
};
int read (struct customer c[]);
void display(struct customer c[], int);
void sort(struct customer c[], int);
int search(struct customer c[], int, char s[]);
void update(struct customer c[], int);
int sumwalamt(struct customer c[], int);
void main()
{
	struct customer c[max];
	int n=0,res,ans,ch,sum;
	char s[50],r[50];
	do
	{
       printf("\n 1. READ\n 2. DISPLAY\n 3. SORT\n 4. SEARCH\n 5. UPDATE\n 6. SUM OF WALLET AMOUNT\n 7. EXIT\n");
	   printf("\nEnter your choice : ");
	   scanf("%d",&ch);
	   switch(ch)
	   {
	       case 1: printf("\nWe are in case 1");
		           n=read(c);
		           break;
		   case 2: printf("\nWe are in case 2");   
		           display(c,n);
		           break;
		   case 3: printf("\nWe are in case 3");   
	               sort(c,n);
	               break;
	       case 4: printf("\nWe are in case 4");   
	               if(n==0)
                   printf("\n*********NO DETAIL FOR SEARCHING*********");
	               else
	               {
	               printf("\nEnter customer to search : ");
	               fflush(stdin);
	               gets(s);
	               res=search(c,n,s);
	               if(res==0)
	               printf("\nThe customer to search is not found");
                   else
	               printf("\nThe customer is found at location %d",res);
	               }
	               break;
	       case 5: printf("\nWe are in case 5");    
		           if(n==0)
	               printf("\n*********NO DETAIL FOR UPDATION*********");
	               else
	               {
	               printf("\nEnter customer to update : ");
	               fflush(stdin);
	               gets(r);
	               ans=search(c,n,r);
	               if(ans==0)
	               printf("\nThe customer to update is not found");
	               else
	               update(c,ans-1);
	               }
	               break;
	       case 6: printf("\nWe are in case 6");
	               if(n==0)
	               printf("\n*********NO DETAIL FOUND FOR SUM*********");
	               else
	               {
	               sum=sumwalamt(c,n);
	               if(sum==0)
	               printf("\nThe sum of the wallet amount is 0");
	               else 
	               printf("\nThe sum of the wallet amount is %d",sum);
	               }
	               break;
	       case 7: printf("\nExiting.....!"); 
	               break;
	       default : printf("\nWrong choice entered!");
	    }
	}while(ch!=7);
}
int read(struct customer c[])
{
	int i,n;
	printf("\nEnter total number of customers : ");
	scanf("%d",&n);
	printf("\n*********ENTER DETAILS*********\n");
	for(i=0;i<n;i++)
	{
		printf("\nRecord %d : \n",i+1);
		printf("ID : ");
		scanf("%d",&c[i].id);
		printf("NAME : ");
		fflush(stdin);
		gets(c[i].name);
		printf("WALLET AMOUNT : ");
		scanf("%d",&c[i].walletamt);
	}
	return n;
}
void display(struct customer c[], int n)
{
	int i;
	if(n==0)
	printf("\n*********NO DETAIL FOUND*********\n");
	else
	{
		printf("\n*********ENTERED DETAILS*********\n");
	    for(i=0;i<n;i++)
	    {
		   printf("\nRecord %d : ",i+1);
		   printf("\nID : ");
		   printf("%d",c[i].id);
		   printf("\nNAME : ");
		   puts(c[i].name);
		   printf("WALLET AMOUNT : ");
		   printf("%d\n",c[i].walletamt);
     	}
	}
}
void sort(struct customer c[], int n)
{
	struct customer key;
	int ch,i,j;
	if(n==0)
	printf("\n*********NO DETAIL FOR SORTING*********");
	else
	do
	{
	printf("\n 1. Sort on Id \n 2. Sort on Name \n 3. Sort on Wallet amount\n");
	printf("\nEnter your choice : ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: 
		    printf("\nWe are in case 1");
		    for(i=1;i<n;i++)
		    {
		    	key=c[i];
		    	for(j=i-1;(j>-1) && (c[j].id>key.id);j--)
		    	c[j+1]=c[j];
		    	c[j+1]=key;
			}
			break;
		case 2: 
		    printf("\nWe are in case 2");
		    for(i=1;i<n;i++)
		    {
		    	key=c[i];
		    	for(j=i-1;(j>-1) && (strcmp(c[j].name,key.name)>0);j--)
		    	c[j+1]=c[j];
		    	c[j+1]=key;
			}
			break;
		case 3: 
		    printf("\nWe are in case 3");
		    for(i=1;i<n;i++)
		    {
		    	key=c[i];
		    	for(j=i-1;(j>-1) && (c[j].walletamt>key.walletamt);j--)
		    	c[j+1]=c[j];
		    	c[j+1]=key;
			}
			break;
		default:
			printf("\nWrong choice entered\n");
	}
    }while((ch!=1)&&(ch!=2)&&(ch!=3));
}
int search(struct customer c[], int n, char s[])
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(c[i].name,s)==0)
		return (i+1);
	}
	return 0;	
}
void update(struct customer c[], int ans)
{
	printf("\nOld Id : ");
	printf("%d",c[ans].id);
	printf("\nNew Id : ");
	scanf("%d",&c[ans].id);
	printf("\nOld Name : ");
	puts(c[ans].name);
	printf("New Name : ");
	fflush(stdin);
	gets(c[ans].name);
	printf("\nOld Wallet Amount : ");
	printf("%d",c[ans].walletamt);
	printf("\nNew Wallet Amount : ");
	scanf("%d",&c[ans].walletamt);
}
int sumwalamt(struct customer c[], int n)
{
	int count=0,i;
	for(i=0;i<n;i++)
	count=count+c[i].walletamt;
	return count;
}
