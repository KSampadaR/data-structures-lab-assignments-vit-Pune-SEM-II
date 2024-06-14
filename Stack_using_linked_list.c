 #include<stdio.h>
 #include<stdlib.h>
 struct node
 {
     int data;
     struct node *next;
 }*top;
 void create(int x)
 {
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    ptr->next=NULL;
    top=ptr;
 }
 void push(int d)
 {  struct node *temp;
    
    if(top==NULL)
    {
        create(d);
    }
    else{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=d;
    temp->next=top;
    top=temp;
    }
 }
 void display()
 {
    if(top==NULL)
    {
        printf("Stack is empty\n");
    }
    else{
        struct node *temp;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
       printf("%d ",temp->data);
    }
 }
 void pop()
 {
    if(top==NULL)
    {
       printf("Empty");
    }
    else
    {
      struct node *temp;
      temp=top;
      top=top->next;
      //temp->next=NULL;
      free(temp);
    }
 }
 int main()
 {
    push(20);
    push(2);
    push(40);
    push(220);
    display();
    pop();
    display();
    return 0;
 }