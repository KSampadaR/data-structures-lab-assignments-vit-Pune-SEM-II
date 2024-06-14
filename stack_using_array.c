#include<stdio.h>
#define SIZE 5
char stack[SIZE];
int top=-1;

void push(char d)
{   
    if(top==SIZE-1)
    {
        printf("OVERflow");
    }
    else
    {
       top=top+1;
       scanf("%c \n",&d);
       stack[top]=d;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Empty\n");
    }
    else
    {
        printf("%d",stack[top]);
        top--;
    }
}

void peek()
{
  if(top==-1)
  {
    printf("Empty");
  }
  else
  {
     printf("%c",stack[top]);
  }
}

 void display()
 {  
    if(top==-1)
    {
        printf("underflow\n");
    }
    else{
        for(int i=top;i>=0;i--)
        {
            printf("%d ",stack[i]);
        }
    }
 }

//  void search(int d)
//  {
//     if(top==-1)
//     {
//         printf("Empty");
//     }
//     else
//     {   int sk;
//         scanf("%d",&sk);
//         if(d==)
//         {
//            printf("Element is found"); 
//         }
//     }
//  }
int main()
{
    push(10);
    push(20);
    push(4);
    display();
    
}