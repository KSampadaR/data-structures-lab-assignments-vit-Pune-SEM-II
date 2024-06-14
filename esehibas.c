#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node*next;

}; struct node *head;

void create(int data)
{ int n;
  struct node *newnode,*temp;
  head=0;
  printf("Enter the no.of data\n");
  scanf("%d",&data);

  for(int i=0;i<=n;i++);
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data");
    scanf("%d",&newnode->data);

    newnode->next=0;

     if(head==0)
     {
       head=temp=newnode;

     }
     else{
       temp->next=newnode;
       temp=newnode;

     }
  }
}

void insert_beg()
{
    int data;
    struct node *newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter data\n");
  scanf("%d",&newnode->data);
   newnode->next=head;
   head=newnode;
}
void insert_end()
{
  int data;
    struct node *newnode,*temp;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter data\n");
  scanf("%d",&newnode->data);
  temp=head;
  while(temp->next!=0)
  {
      temp=temp->next;
  }
    temp->next=newnode;
    newnode->next=0;

}
void insert_pos()
{
   int data,pos;
   int i=1;
   struct node *newnode,*temp;
   newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the position\n");
    scanf("%d",&pos);

     printf("Enter data\n");
    scanf("%d",&newnode->data);
    temp=head;
    while(i<pos)
    {
      temp=temp->next;
    }

    newnode->next=temp->next;
    temp->next=newnode;
}

void display()
{
   struct node*temp;
   temp=head;
   while(temp->next!=0)
   {
       printf("%d",temp->data);
       temp=temp->next;
   }

     printf("%d",temp->data);
}

int main()
{ void create();
  int data,choice,pos;
 while(1)
 {

 scanf("%d",&choice);
 switch(choice)
 {
 case 1 : scanf("%d",&data);
    insert_beg();
 break;
 case 2 : scanf("%d",&data);
   insert_end();
 break;
 case 3 : scanf("%d",&data);
   insert_pos();
 break;
 case 4 : display();
 break;
 case 5 : exit(0);

 }
 }

return 0;
}