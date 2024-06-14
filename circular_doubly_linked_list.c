#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *next,*prev;
}*head=NULL;
void create(int x)
{
  struct node *ptr;
  ptr=(struct node*)malloc(sizeof(struct node));
  head=ptr;
  ptr->data=x;
  ptr->next=head;
  ptr->prev=head;
}
void insert_start(int x)
{
  if(head==NULL)
    create(x);
  else
  {
    struct node *ptr, *temp;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    temp=head;
    while(temp->next!=head)
      temp=temp->next;
    ptr->next=head;
    ptr->prev=temp;
    temp->next=ptr;
    head->prev=ptr;
    head=ptr;
  }
}
void insert_end(int x)
{
  if(head==NULL)
    create(x);
  else
  {
    struct node *ptr, *temp;
    temp=head;
    while(temp->next!=head)
      temp=temp->next;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    ptr->prev=temp;
    ptr->next=head;
    temp->next=ptr;
    head->prev=ptr;
  }
}
void insert_middle(int y,int x)
{
  if(head==NULL)
    create(x);
  else
  {
    struct node *ptr, *temp;
    temp=head;
    while(temp->data!=y)
      temp=temp->next;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    ptr->prev=temp;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    temp->next=ptr;
  }
}
void display()
{
  if(head==NULL)
    printf("Empty");
  else
  {
    struct node *temp;
    temp=head;
    while(temp->next!=head)
    {
      printf("%d ",temp->data);
      temp=temp->next;
    }
    printf("%d",temp->data);
  }
}
void delete_start()
{
  if(head==NULL)
    printf("Empty");
  else
  {
    struct node *ptr, *temp;
    temp=head;
    while(temp->next!=head)
      temp=temp->next;
    ptr=head;
    head=ptr->next;
    temp->next=head;
    head->prev=temp;
    free(ptr);
  }
}
void delete_end()
{
  if(head==NULL)
    printf("Empty");
  else
  {
    struct node *ptr, *temp;
    temp=head;
    while(temp->next!=head)
    {
      ptr=temp;
      temp=temp->next;
    }
    ptr->next=head;
    head->prev=ptr;
    free(temp);
  }
}
void delete_middle(int y)
{
  if(head==NULL)
    printf("Empty");
  else
  {
    struct node *ptr, *temp;
    temp=head;
    while(temp->data!=y)
    {
      ptr=temp;
      temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);
  }
}
void search(int x)
{
  if(head==NULL)
    printf("Empty");
  else
  {
    struct node *ptr, *temp;
    int k;
    temp=head;
    while(temp->data!=x)
    {
      temp=temp->next;
      if(temp->data==x)
      {
        printf("number present");
        break;
      }
      if(temp->next==head)
      {
        printf("number absent");
        break;
      }
    }
  }
}
int main()
{
  int arr[5],count=0,i=-1;
  int x,y;
  create(10);
  insert_end(20);
  insert_end(25);
  do
  {
    scanf("%d",&arr[++i]);
    count++;
  }while(arr[i]!=9);
  
  for(int i=0; i<count; i++)
  {
    switch(arr[i])
    {
      case 1:
        x=arr[++i];
        insert_start(x);
        break;
      case 2:
        insert_end(arr[++i]);
        break;
      case 3:
        y=arr[++i];
        x=arr[++i];
        insert_middle(y,x);
        break;
      case 4:
        delete_start();
        break;
      case 5:
        delete_end();
        break;
      case 6:
        delete_middle(arr[++i]);
        break;
      case 7:
        display();
        break;
      case 8:
        search(arr[++i]);
        break;
      case 9:
        exit(0);
    }
  }
  return 0;
}


circular doublly