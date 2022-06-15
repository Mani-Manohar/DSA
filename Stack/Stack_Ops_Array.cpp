#include<iostream>
using namespace std;
    
class Stack{
    public:
        int size=0;
        int top = -1;
        int *A;

        Stack(int size)
        {
            this->size = size;
            A = new int[size];
        }
        void create();
        void disp();
        void push(int x);
        int pop();
        int peek(int index);
        int isFull();
        int isEmpty();
};
void Stack :: create()
{
    for(int i=0; i< size; i++) 
    {
        int x=0;
        cout<<"Enter element:- ";
        cin>>x;
        push(x);
    }
}
void Stack :: push(int x)
{
    if(isFull())
        cout<<"\n Stack_Overflow";

    else{
        top++;
        A[top] = x;
    }
}

int Stack :: pop()
{
    int x = -1;
    if(isEmpty())
        cout<<"\n Stack_Underflow";
        
    else{
        x = A[top];
        top--;
    }
        return x;
}

int Stack :: peek(int index)
{
    int x = -1;
    if(top-index+1 < 0 || top-index+1 == size)
        cout<<"\nInvalid position.";

    else{
        x = A[top-index+1];
    }
    return x;
}

void Stack :: disp()
{
    cout<<"\nElements in stack:- \n";
    for(int i=0; i<top+1; i++)
    {
        cout<<A[i]<<" ";
    }
}

int Stack :: isFull()
{
    if(top == size-1)
        return 1;
    
    return 0;
}

int Stack :: isEmpty()
{
    if(top == -1)
        return 1;

    return 0;
}

int main()
{
    int n;
    cout<<"Enter the no. of elements to be pushed into stack:- ";
    cin>>n;
    Stack s(n);
    s.create();
    s.disp();
    cout<<"\n";

    cout<<s.top;
    
    cout<<"\n";
    s.pop();
    cout<<s.top;

    cout<<"\n";
    s.pop();
    cout<<s.top;
    return 0;
}