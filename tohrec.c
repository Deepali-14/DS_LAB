#include<stdio.h>
void toh(int, char, char, char);
int main()
{
    int n;
    printf("\n Enter number of disks : ");
    scanf("%d",&n);
    printf("\n The moves involved are : ");
    toh(n,'A','C','B');
    return 0;
}
void toh(int n, char fp, char tp , char ap)
{
    if(n==1)
    {
       printf("\n Move disk 1 from %c to %c",fp,tp);
       return ;
    }
    toh(n-1,fp,ap,tp);
    printf("\n Move disk %d from %c to %c",n,fp,tp);
    toh(n-1,ap,tp,fp);
    return ;
}
