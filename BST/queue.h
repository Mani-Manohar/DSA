#include<iostream>
using namespace std;

class Node{
    public:
        Node *lchild=NULL;
        int data;
        Node *rchild=NULL;
};

class Queue{
    public:
        int f=-1,r=-1;
        int size=0;
        Node **Q=NULL;

        Queue(int size)
        {
            this->size = size;
            Q = new Node* [size];
        }

        void Enqueue(Node *x); //Insertion
        Node* Dequeue(); //Deletion
        int isEmpty();
        int isFull();
        void Disp();
};

void Queue :: Disp()
{
    for(int i=f+1; i<size; i++) 
    {
        cout<<Q[i]<<" ";
    }
}

void Queue :: Enqueue(Node *x)
{
    if(r==size-1)
        cout<<"\nQueue is full.";
    else{
        r++;
        Q[r] = x;
    }
}

Node* Queue :: Dequeue()
{
    Node *x=NULL;
    if(f==r)
        cout<<"\nQueue is Empty.";

    else{
        f++;
        x = Q[f];
    }
    return x;
}

int Queue :: isEmpty()
{
    if(f==r)
        return 1;

    return 0;
}

int Queue :: isFull()
{
    if(r == size-1)
        return 1;

    return 0;

}