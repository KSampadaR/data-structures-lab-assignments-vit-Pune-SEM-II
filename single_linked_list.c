#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;

void create(int d)
{   
    struct node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    head=temp;
   
}
void insert_begin(int d)
{   if(head==NULL)
{
     create(d);
}
    else
    {

    struct node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=head;
    head=temp;
    }
}
void insert_end(int d)
{   if(head==NULL)
{
    create(d);
}   
    else{
    struct node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=NULL;
    q=head;
    while(q->next!=NULL)
    {
       q=q->next;
    }
    q->next=temp;
    }
}

void insert_middle(int d, int v)
{
  if(head==NULL)
  {
    create(d);
  }
  else
  {
    struct node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    q=head;
    while(q->data!=v)
    {
        q=q->next;
    }
     temp->next=q->next;
     q->next=temp;
  }
}

void display()
{
    struct node *q,*temp;
    if(head==NULL)
    {
        printf("Empty");
    }
    else
    { temp=head;
      while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
      }
        printf("%d \n",temp->data);
    }
}

void delete_begin()
    {
        
        if(head==NULL)
        {
           printf("empty");
        }
        else
        {
            struct node *q,*temp;
           temp=head;
           head=temp->next;
           free(temp);
        }
    }

void delete_end()
{
    if(head==NULL)
    {
        printf("Empty");
    }
    else{
        struct node *q,*temp;
        temp=head;
        q=head;
        while(temp->next!=NULL)
        {   
            q=temp;
            temp=temp->next;
        }
        q->next=NULL;
        free(temp);
    }
}

void delete_middle(int v)
{  
    if(head==NULL)
    {
        printf("empty");
    }
    else{
        struct node *q,*temp;
        temp=head;
        q=head;
        while(temp->data!=v)
        {    
            q=temp;
            temp=temp->next;
        }
        q->next=temp->next;
        free(temp);
    }
}
int main()
{
   insert_begin(5);
   insert_middle(10,5);
   display();
   insert_middle(15,10);
   display();
   insert_end(50);
   display();  
   delete_begin();
   display();
   delete_middle(10);
   display();
   delete_end();
   display();
   
   return 0;
}