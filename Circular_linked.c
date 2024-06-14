#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head;

 void create(int d){
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    temp->data=d;
    temp->next=head;
}

// void insert_start(int d)
// {   if(head==NULL)
// {
//     create(d);
// }
//     struct node *temp;
//     temp=(struct node*)malloc(sizeof(struct node));
//     temp->data=d;
//     temp->next=head;
//     temp=head;
// }


void insert_start(int v)
{
    struct node *temp,*q;
    temp=malloc(sizeof(struct node));
    temp->data=v;
    if(head==NULL)
    {
        head=temp;
        head->next=head;
    }

    else
    {
        q=head;
        while(q->next!=head)
        {
            q=q->next;
        }
        q->next=temp;
        temp->next=head;
        

    }
}

void insert_end(int d)
{   
    if(head==NULL)
{
    create(d);
}
else{
    struct node *temp,*q;
    temp=malloc(sizeof(struct node));
    temp->data=d;
    q=head;
    while(q->next!=head)
    {
        q=q->next;
    }
    q->next=temp;
    temp->next=head;
}
    
}
void display()
{    struct node *temp;
     temp=head;
    if(head==NULL)
    {
        printf("Empty");
    }
    else
    {
        
        //temp=(struct node*)malloc(sizeof(struct node));
        while(temp->next!=head)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d", temp->data);
        
    }
}

void insert_middle(int d, int v)
{
    if(head==NULL)
    {
        create(d);
    }
    else{
    struct node *temp,*q;
    temp=malloc(sizeof (struct node ));
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

void delete_start()
{
    struct node *temp,*q;
    temp=head;
   while(temp->next!=head)
   {
    temp=temp->next;
   }
   q=head;
   head=head->next;
   temp->next=head;
   q->next=NULL;
   free(q);

}
void delete_end()
{
    struct node *temp,*q;
    temp=head;
    while((temp->next)->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head;
    free(q);
}

void delete_middel(int d)
{
    struct node *temp,*q;
    temp=head;
    while(temp->next!=d)
    {
        temp=temp->next;
    }
    q=head;
    temp->next=q;
    q->next=temp->next;
    q->next=NULL;
    temp->next=head;
    free(q);
}
int main()
{
    head=NULL;
    insert_start(20);
    insert_start(25);
    insert_start(30);
    delete_end();
    display();
    insert_end(24);
    printf("\n");
    display();
    insert_middle(25,25);
    printf("\n");
    display();
    delete_start();
    printf("\n");
    display();
    printf("\n");
    insert_start(22);
    insert_start(32);
    insert_start(25);
    insert_start(30);
    delete_middel(32);
    display();

    return 0;
}