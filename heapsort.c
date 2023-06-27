#include<stdio.h>
#define max 20
void heapSort(int [], int);
void heapify(int [], int, int);
void printArray(int [], int);
void swap(int *, int *);
void main() 
{
	int a[max];
	int n,i;
    printf("\n Enter number of elements in array : ");
    scanf("%d",&n);
    printf("\n Enter elements : ");
    for (i=0;i<n;i++)
      scanf("%d",&a[i]);
    printf("\n Original array : \n");
    for (i=0;i<n;i++) 
      printf(" %d ",a[i]);
    heapSort(a,n);
    printf("\n Sorted array : \n");
    printArray(a,n);
}
void swap(int *a, int *b) 
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[], int n, int i) 
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<n && arr[left]>arr[largest])
        largest=left;
    if (right<n && arr[right]>arr[largest])
        largest=right;
    if (largest!=i) 
	{
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[], int n) 
{
	int i;
    for(i=n/2-1;i>=0;i--)
    heapify(arr,n,i);
    for(i=n-1;i>=0;i--) 
	{
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}
void printArray(int arr[], int n) 
{
	int i;
    for(i=0;i<n;++i)
    printf(" %d ",arr[i]);
}
