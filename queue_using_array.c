#include<stdio.h>
#define  SIZE 5
int queue[SIZE];
int f=-1;
int r=-1;
void enqueue(int v){
    if(r==SIZE-1)
    {
        printf("FULL");
    }
    else{
        r=r+1;
        printf("%d\n",v);
        //scanf("%d",&v);
        queue[r]=v;
    }
     //printf("%d \n",queue[r]);
}  
void dequeue()
{
    if(f==-1&&r==-1)
    {
        printf("The queue is empty");
    }
    else{
        printf("%d ",queue[r]);
        r--;
    }
}   
int main()
{
   enqueue(20);
   enqueue(34);
   dequeue();
   dequeue();
   dequeue();
   return 0;
}