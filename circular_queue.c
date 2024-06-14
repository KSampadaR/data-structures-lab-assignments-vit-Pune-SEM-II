#include<stdio.h>
#define SIZE 10
int f=-1;
int r=-1;
int queue[SIZE]; 
void enequeue(int d)
{ 
    if(f==0 &&r==SIZE-1){
        printf("the queue is full0");
    }
    else{
        r=(r+1)%SIZE;
        printf("%d ",d);
        queue[r]=d;
    }
}
void dequeue()
{
    if(r==f)
    {
        printf("empty");
    }
    // else if
    // {
    //     printf("%d",queue[f]);
    //     f=(f+1)%SIZE;
    // }
    else{
        printf("%d ",queue[r]);
        f--;
    }
}
int main(){
    enequeue(20);
    enequeue(34);
    dequeue();
    return 0;
}