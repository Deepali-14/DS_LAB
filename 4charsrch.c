#include<stdio.h>
#include<string.h>
int main()
{
    char st[20],ch;
    int c=0,i;
    printf("\nRead string : ");
    gets(st);
    printf("\nRead character to search : ");
    scanf("%c",&ch);
    for(i=0;st[i]!='\0';i++)
      if(ch==st[i])
      {
        printf("\n%c found at position %d",ch,i+1);
        c++;
      }
    if(c!=0)
      printf("\n%c found %d times",ch,c);
    else
      printf("\ncharacter not found");
    return 0;
}
