#include<stdio.h>
#include<stdlib.h>
void selection_sort(int arr[],int n)
{
    int temp,i,j,min;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
              min=j;
        }
           temp=arr[i];
           arr[i]=arr[min];
           arr[min]=temp;
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
    selection_sort(a,n);
    printf("%d ",a[i]);
    }
    return 0;
}
