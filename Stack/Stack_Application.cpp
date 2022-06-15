#include<iostream>
#include<cstring>
using namespace std;

class Stack
{
    public:
        int size=0;
        int top = -1;
        int *A;
        char *postfix;

        Stack(int size)
        {
            this->size = size;
            A = new int[size];
        }

        int isBalanced(char *e);

        int Evaluate(char *post);
        char* convert(char *infix, int len);
        int isOperand(char x);
        // int Pre(char x);
        int InPre(char x);
        int OutPre(char x);
        void push(char e);
        char pop();
        int isEmpty();
};

void Stack :: push(char e)
{
    if(top == size-1)
        cout<<"\nStack_Overflow.";

    else
    {
        top++;
        A[top] = e;
    }
}

char Stack ::  pop()
{
    char ch;
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

// int Stack :: Pre(char x)
// {
//     if(x=='+' || x=='-')
//         return 1;
    
//     else if(x=='*' || x=='/')
//         return 2;

//     else
//         return 0;
// }

int Stack :: isBalanced(char *e)
{
    for(int i=0; e[i]!='\0'; i++) 
    {
        if(e[i] == '(' || e[i] == '{' || e[i] == '[')
            push(e[i]);

        else if(e[i] == ')' || e[i] == '}' || e[i] == ']')
        {   
            if(top<0)    
                return false;

            pop();
        }
    }

    if(isEmpty())
        return true;
    else
        return false;
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

int Stack :: Evaluate(char *post)
{
    A = new int[size];
    int a=0,b=0,res=0;
    for(int i=0; post[i]!='\0'; i++) 
    {
        if(isOperand(post[i]))
            push(post[i] - '0');//? we've done post[i]-'0' bcoz nos. in post are stored as character not as int so while storing it gets converted into ASCII, by doing this subtraction we can store the correct value in STACK.

        else{
            a = pop();
            b = pop();

            switch(post[i])
            {
                case '+': res = a+b;
                        push(res);
                        break;
                case '-': res = b-a;
                        push(res);
                        break;
                case '*': res = b*a;
                        push(res);
                        break;
                case '/': res = b/a;
                        push(res);
                        break;
            }
        }
    }
    return res;
}

int main()
{
    // char *exp = "{([a+b]*[c-d])/e}";
    // int len = strlen(exp);
    // Stack s(len);
    
    // if(s.isBalanced(exp))
    //     cout<<"Yes, Eq. is balanced.";
    // else
    //     cout<<"No, Eq. is not balanaced.";
    
    // char *post, *infix = "a+b*c-d/e";

    
    // *infix = "((a+b)*c)-(d^e)^f";
    //*infix = "5+3*4-8/2";
    char *post, *infix = "a+b*c-d/e";
    int len = strlen(infix);
    Stack s(len);

    post = s.convert(infix,len);
    cout<<"\nPostfix value:- ";
    for(int i=0; post[i]!='\0'; i++) 
    {
        cout<<post[i];
    }
    cout<<"\nEvaluation:- \n";
    cout<<s.Evaluate(post);

    return 0;
}