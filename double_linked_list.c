#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
}*head;
void create(int d)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    head=temp;
    temp->prev=NULL;
    temp->data=d;
    temp->next=NULL;
}
void insert_start(int d)
{
    if(head==NULL)
    {
        create(d);
    }
    else
    {
        struct node *temp;
        temp=malloc(sizeof(struct node));
        temp->data=d;
        temp->next=head;
        head->prev=temp;
        temp=head;
    }
}

void insert_end(int d)
{
    if(head==NULL)
    {
        create(d);
    }else{
    struct node *temp,*q;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    q=head;
    while(q->next!=NULL){
        q=q->next;
    }
       temp->prev=q->next;
       q->next=temp;
    }
}

void insert_middel(int d,int v)
{
    if(head==NULL)
    {
        create(d);
    }
    else
    {
     struct node *temp,*q;
     temp=(struct node*)malloc(sizeof(struct node));
     temp->data=d;
     temp->next=NULL;
     q=head;
     while (q->data!=v)
     {
      q=q->next;
     }
      temp->next=q->next;
      q->next->prev=temp;
      q->next=temp;
      temp->prev=q;
    }
}

void delete_begin()
{   
    struct node *q,*temp;
    temp=head;
    temp->next=head;
    head->prev=NULL;
    free(temp);
}

void delete_end()
{
    struct node *temp;
}
void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("\nThe list is Empty");
    }
    else{
         temp=head;
        while(temp->next!=NULL)
        {  
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
       
}
int main()
{
    
  insert_start(20);
  insert_end(30);
  insert_middel(22,20);
  display();
  insert_end(33);
  insert_start(24);
  insert_start(25);
  printf("\n");
  insert_middel(24,20);
  display();

  return 0;
}