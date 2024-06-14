#include <iostream>
using namespace std;
#define size 10

int top = -1;
char stk[size];

void push(char x)
{
    if (top == size - 1)
    {
        cout << "Overflow\n";
    }
    else
    {
        top = top + 1;
        stk[top] = x;
    }
}

char pop()
{
    if (top == -1)
    {
        cout << "Underflow\n";
        return '\0'; // Return a placeholder for underflow
    }
    char s = stk[top];
    top = top - 1;
    return s;
}

int isfull()
{
    return (top == size - 1);
}

int isempty()
{
    return (top == -1);
}

int main()
{
    char exp[20], ch;
    int i = 0;
    cout << "\n\t!! Parenthesis Checker..!!!!" << endl;
    cout << "\nEnter the expression to check whether it is in well form or not :  ";
    cin >> exp;
    if ((exp[0] == ')') || (exp[0] == ']') || (exp[0] == '}'))
    {
        cout << "\n Invalid Expression.....\n";
        return 0;
    }
    else
    {
        while (exp[i] != '\0')
        {
            ch = exp[i];
            switch (ch)
            {
            case '(':
            case '[':
            case '{':
                push(ch);
                break;
            case ')':
                if (isempty() || pop() != '(')
                {
                    cout << "\nSorry !!! Invalid Expression or not in well parenthesized....\n";
                    return 0;
                }
                break;
            case ']':
                if (isempty() || pop() != '[')
                {
                    cout << "\nSorry !!! Invalid Expression or not in well parenthesized....\n";
                    return 0;
                }
                break;
            case '}':
                if (isempty() || pop() != '{')
                {
                    cout << "\nSorry !!! Invalid Expression or not in well parenthesized....\n";
                    return 0;
                }
                break;
            }
            i = i + 1;
        }
    }
    if (isempty())
    {
        cout << "\nExpression is well parenthesized...\n";
    }
    else
    {
        cout << "\nSorry !!! Invalid Expression or not in well parenthesized....\n";
    }
    return 0;
}