#include<iostream>
#include<cstring>
using namespace std;
template <typename T>

class Stack
{
    public:
        int size=0;
        int top = -1;
        T *A;
        char *postfix;

        Stack(int size)
        {
            this->size = size;
            A = new T[size];
        }

        char* convert(char *infix, int len);
        int isOperand(char x);
        int InPre(char x);
        int OutPre(char x);
        T push(T e);
        T pop();
        int isEmpty();

};

T Stack :: push(T e)
{
    if(top == size-1)
        cout<<"\nStack_Overflow.";

    else
    {
        top++;
        A[top] = e;
    }
    return 0;
}

T Stack ::  pop()
{
    T ch;
    if(isEmpty())
    {
        cout<<"\nStack_Underflow.";
        return -1;
    }

    else
    {
        ch = A[top];
        top--;
    }
        return ch;
}

int Stack :: isEmpty()
{
    if(top == -1)
        return 1;

    return 0;
}

int Stack :: isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='(' || x==')')
        return 0;

    else
        return 1;
}

int Stack :: InPre(char x)
{
    if(x=='+' || x=='-')
        return 2;
    
    else if(x=='*' || x=='/')
        return 4;

    else if(x=='^')
        return 5;

    else if(x=='(')
        return 0;

    else
        return -1;
}

int Stack :: OutPre(char x)
{
    if(x=='+' || x=='-')
        return 1;
    
    else if(x=='*' || x=='/')
        return 3;

    else if(x=='^')
        return 6;
    
    else if(x=='(')
        return 7;

    else if(x==')')
        return 0;

    else
        return -1;
}


char* Stack :: convert(char *infix, int len)
{
    postfix = new char[len];
    int i=0,j=0;

    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];

        else
        {
            if(OutPre(infix[i]) > InPre(A[top]))
                push(infix[i++]);

            else if(OutPre(infix[i]) < InPre(A[top]))
                postfix[j++] = pop();

            else
            {
                pop();
                i++;
            }
   
        }
    }

    while(!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    return postfix;
}

int main()
{
    // char *exp = "{([a+b]*[c-d])/e}";
    
    char *post, *infix = "((a+b)*c)-(d^e)^f";
    // char *post, *infix = "a+b*c-d/e";
    int len = strlen(infix);
    Stack s(len);

    post = s.convert(infix,len);

    for(int i=0; post[i]!='\0'; i++) 
    {
        cout<<post[i];
    }

    // s.Ex(infix);
    return 0;
}