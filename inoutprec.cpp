#include<iostream>
using namespace std;

char stack[1000];
int top=-1;

int isEmpty()
{
    if(top==-1)
    return 1;
    else return 0;
}

void push(char x)
{
    stack[top+1]=x;
    top=top+1;
}

char pop()
{
    if(!isEmpty())
    {
        top=top-1;
        return stack[top+1];
    }
}

char peek()
{
    return stack[top];
}

int isOperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')')
    return 1;
    else 
    return 0;
}

int inStackPrecedence(char x)
{
    if(x=='+'||x=='-')
    return 2;
    else if(x=='*' || x=='/')
    return 4;
    else if(x=='^')
    return 5;
    else if(x=='(')
    return 0;
}

int outStackPrecedence(char x)
{
    if(x=='+'||x=='-')
    return 1;
    else if(x=='*' || x=='/')
    return 3;
    else if(x=='^')
    return 6;
    else if(x=='(')
    return 7;
    else if(x==')')
    return 0;
}

int main()
{
    string infix;
    cout<<"Enter the infix expression : ";
    cin>>infix;

    char postfix[infix.length()+1];

    int i=0,j=0;
    while(i<infix.length())
    {
        char ch=infix[i];
        if(isOperator(ch))
        {
            if(isEmpty())//when it is the first operator or when the stack is empty
            {
                push(ch);
                i++;
            }
            else
            {
                if(inStackPrecedence(peek())>=outStackPrecedence(ch) && peek()!='(')
                postfix[j++]=pop();
                else if(inStackPrecedence(peek())<outStackPrecedence(ch))
                {
                    push(ch);
                    i++;
                }
                else
                {
                    pop();
                    i++;
                }
            }

        }
        else
        postfix[j++]=infix[i++];
    }
    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j++]='\0';
    cout<<"\nPostfix : "<<postfix<<endl;
}
