#include<stdio.h>
int main()
{
    double a[20];
    int i,num;
    printf("\nEnter number of elements in the array : ");
    scanf("%d",&num);
    printf("\n*****Enter elements*****\n");
    for(i=0;i<num;i++)
    scanf("%lf",&a[i]);
    printf("\n*****Entered elements*****\n");
    for(i=0;i<num;i++)
    printf("%lf\t",a[i]);
    return 0;
}
