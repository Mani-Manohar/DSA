#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class Stack{
    private:
        Node *top = NULL;
        int size = 0;
        int x = -1;
        Node *temp = NULL;
    public:
        Stack(int size)
        {
            this->size = size;
        }
        void push(int x);
        int pop();
        int isFull();
        int isEmpty();
        int peek(int index);
        void Disp();
};

void Stack :: push(int x)
{
    if(isFull())
    {
        cout<<"\nStack_Overflow";
    }
    
    else
    {
        temp->next = NULL;
        temp->data = x;
        temp->next = top;
        top = temp;
    }
}

int Stack :: pop()
{
    if(isEmpty())
    {
        cout<<"\nStack_Underflow";
    }

    else
    {
        x = top->data;
        temp = top;
        top = top->next;
        delete temp;
    }
    return x;
}

int Stack :: isFull()
{
    temp = new Node;
    if(temp == NULL)
        return 1;
    
    return 0;
}

int Stack :: isEmpty()
{
    if(top == NULL)
        return 1;
    
    return 0;
}

int Stack :: peek(int index)
{
    if(index<=0)
        cout<<"\nInvalid_Index.";

    for(int i=0; i<index-1 && temp; i++) 
    {
        temp = top;
        temp = temp->next;
    }
    
    if(temp!=NULL)
        return temp->data;
    
    else
            return -1;
}

void Stack :: Disp()
{
    temp = top;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    Stack s(4);
    int x=0;
    for(int i=0; i<4; i++) 
    {
        cout<<"Enter Element:- ";
        cin>>x;
        s.push(x);
    }
    s.Disp();
    
    cout<<"\n"<<s.pop()<<" is popped.";
    cout<<"\n Updated stack elements:- ";
    s.Disp();
    return 0;
}