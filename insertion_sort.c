// #include<stdio.h>
// #include<stdlib.h>
// void insertion_sort(int arr[],int n)
// {
//     int i,j,temp;
//     for(i=0;i<n;i++)
//     {
//          temp=arr[i];
//          for(j=i;j>0&&temp<arr[j];j--)
//          {
//             if(arr[j]>arr[j-1])
//             {
//                  temp=arr[j];
//                 arr[j]=arr[j-1];
//                  arr[j-1]=temp;
//             }
         
//          }
//     }
// }
 

#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int arr[],int size)
{
  int i,j,k;
  for(i=1;i<size;i++)
  {
    k=arr[i];
    j=i-1;
    while(j>=0 && arr[j]>k)
    {
      arr[j+1]=arr[j];
      j=j-1;
    }
    arr[j+1]=k;
  }
}
void printarray(int arr[], int size)
{
  for(int i=0;i<size;i++)
    printf("%d ",arr[i]);
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
    insertion_sort(a,n);
    printf("The sorted array is\n");
    for(i=0;i<n;i++){
    //insertion_sort(a,n);
     printf("%d ",a[i]);
    }
   
    return 0;
}
