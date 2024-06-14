#include<iostream>
using namespace std;
#define size 10

class stack
{
 private:
 int top;
 char stk[size];
 public:
stack()
{
 top=-1;
}

void push(char);
char pop();
char gettop();
int isfull();
int isempty();

};

void stack::push(char a)
{
 top=top+1;
 stk[top]=a;
}

char stack::pop()
{
 char s;
 s=stk[top];
 top=top-1;
 return s;
}

char stack::gettop()
{
 return stk[top];
}

int stack::isfull()
{
 if(top==size-1)
 return 1;
 else
 return 0;
}

int stack::isempty()
{
 if(top==-1)
 return 1;
 else
 return 0;
}

int prec(char ch)
{
 if(ch=='/'||ch=='*')
 return 2;
 else if(ch=='+'||ch=='-')
 return 1;
 else
 return 0;
}

string infixToPostfix(string s)
{
stack st;
string ans="";
for(int i=0;i<s.length();i++)
{
char ch=s[i];
if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9'))
{
ans += ch;
}

else if(ch=='(')
st.push('(');

else if(ch==')')
{
while(st.gettop()!='(')
{
ans += st.gettop();
st.pop();
}
st.pop();
}
else
{
while(!st.isempty() && prec(s[i]) <= prec(st.gettop()))
{
ans += st.gettop();
st.pop();
}
st.push(ch);
}
}

while(!st.isempty())
{
ans += st.gettop();
st.pop();
}

return ans;
}

int evalpostexp(string exp)
{
stack st;
for(int i=0;i<exp.length();i++)
{
char c = exp[i];

if(c>='0' && c<='9')
{
int temp = (int)(c - '0');
st.push(temp);
}
else
{
int op1 = st.pop();
int op2 = st.pop();

switch(c)
{
case '+':
st.push(op2 + op1);
break;

case '-':
st.push(op2 + op1);
break;

case '*':
st.push(op2 + op1);
break;
}
}
}
return st.gettop();
}

int main()
{
string s;
string postfix;
cout<<"Enter Infix Expression:";
cin>>s;
postfix=infixToPostfix(s);
cout<<"\n Postfix exprssion is:"<<postfix;
cout<<"\n Postfix Expression Evaluation:"<<evalpostexp(postfix);
return 0;
}
