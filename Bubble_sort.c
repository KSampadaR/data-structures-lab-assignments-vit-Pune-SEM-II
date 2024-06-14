#include<stdio.h>
#include<stdlib.h>
 
 void bubble_sort(int arr[],int n)
 {
    int i,j,temp;
    for(i=0;i<n-2;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
 }
int main()
{
    int i,j,a[20],n;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the elments to swap\n");
    for(i=0;i<n;i++)
    {
        scanf("%d ",&a[i]);
    }
    printf("The sorted array is\n");
    for(i=0;i<n;i++){
    bubble_sort(a,n);
    printf("%d ",a[i]);
    }
    return 0;
}
