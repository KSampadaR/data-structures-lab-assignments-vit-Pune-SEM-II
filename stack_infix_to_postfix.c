#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct node {
    int data;
    struct node *next;
} *top;

void create(int x) {
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = x;
    ptr->next = NULL;
    top = ptr;
}

void push(int d) {
    struct node *temp;

    if (top == NULL) {
        create(d);
    } else {
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = d;
        temp->next = top;
        top = temp;
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct node *temp;
        temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int pop() {
    if (top == NULL) {
        printf("Empty\n");
        return -1;  // Indicate an error condition
    } else {
        struct node *temp;
        int poppedValue;
        temp = top;
        top = top->next;
        poppedValue = temp->data;
        free(temp);
        return poppedValue;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;  // Assuming all other characters are operands
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != NULL && top->data != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop '('
        } else if (isOperator(ch)) {
            while (top != NULL && precedence(top->data) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while (top != NULL) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

int main() {
    char infix[50];
    char postfix[50];

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Enter Infix Expression\n");
        printf("2. Convert to Postfix and Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Infix Expression: ");
                scanf("%s", infix);
                break;

            case 2:
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
