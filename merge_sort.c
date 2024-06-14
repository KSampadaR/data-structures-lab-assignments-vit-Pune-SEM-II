#include<stdio.h>
#include<stdlib.h>
void merge(int arr[], int l, int m, int r)
{
  int i,j,k;
  int n1=m-l+1;
  int n2=r-m;
  
  int L[n1],R[n2];
  
  for(i=0;i<n1;i++)
    L[i]=arr[l+i];
  for(j=0;j<n2;j++)
    R[j]=arr[m+1+j];
  
  i=0;
  j=0;
  k=l;
  while(i<n1 && j<n2)
  {
    if(L[i]<=R[j])
      arr[k++]=L[i++];
    else
      arr[k++]=R[j++];
  }
  while(i<n1)
    arr[k++]=L[i++];
  while(j<n2)
    arr[k++]=R[j++];
}
void mergesort(int arr[], int l, int r)
{
  if(r>l)
  { 
    int m=l+(r-l)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}
void printarray(int arr[], int size)
{
  for(int i=0;i<size;i++)
    printf("%d ",arr[i]);
}
int main()
{
  int arr[50],l,r,size;
  scanf("%d",&size);
  for(int i=0;i<size;i++)
    scanf("%d",&arr[i]);
  l=0;
  r=size-1;
  mergesort(arr,l,r);
  printarray(arr,size);
  return 0;
}