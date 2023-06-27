#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct book
{
	int bid;
	char bnm[20];
};
void lsearch(struct book b[], char s[], int);
void read(struct book b[],int);
void print(struct book b[],int);
int main()
{
	int n;
	struct book B[100];
	printf("\nEnter number of books : ");
	scanf("%d",&n);
	read(B,n);
	return 0;
}
void read(struct book b[],int n)
{
	int i;
	char k[20];
	for(i=0;i<n;i++)
	{
		printf("\nBook no. %d",i+1);
		printf("\nBOOK ID : ");
		scanf("%d",&b[i].bid);
		fflush(stdin);
		printf("\nBOOK NAME : ");
		gets(b[i].bnm);
	}
	print(b,n);
	printf("\nEnter book to search : ");
	gets(k);
	lsearch(b,k,n);
}
void print(struct book b[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nBook no. %d",i+1);
		printf("\nBOOK ID : ");
		printf("%d",b[i].bid);
		printf("\nBOOK NAME : ");
		puts(b[i].bnm);
	}
}
void lsearch(struct book b[], char s[], int n)
{
	int i,c=0;
	for(i=0;i<n;i++)
	{
		if(strcmp(b[i].bnm,s)==0)
		{
			printf("\nThe book is found at %d location",i+1);
			c++;
		}
	}
	printf("\nThe book found %d times",c);	
}
