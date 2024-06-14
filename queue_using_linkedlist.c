#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*rear=NULL,*front=NULL;
 void create(int d)
 {
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    front=temp;
    rear=temp;
    temp->data=d;
    temp->next=NULL;

 }

 void enqueue(int d)
 {
    if(front==NULL&&rear==NULL)
    {
        create(d);
    }
    else{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    rear->next=temp;
    rear=temp;
    
//    if(front==NULL&&rear==NULL)
//    {front=temp;
//     rear=temp;
//     }
    //  rear=temp;
    }
 }

 void dequeue()
 {
    struct node *temp;
    temp=front;
    front=front->next;
    temp->next=NULL;
    //front=temp;
    free(temp);
 }

 void display()
 {
    if(front==NULL&&rear==NULL){
        printf("The queue is empty");
    }
    else
    {   struct node *temp;
        temp=front;
        while(temp->next!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
 }
int main()
{
    enqueue(20);
    enqueue(22);
    enqueue(22);
    enqueue(22);
    dequeue();
    display();
    return 0;
}