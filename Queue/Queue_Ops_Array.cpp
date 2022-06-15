#include<iostream>
using namespace std;

class Queue{
    public:
        int f=-1,r=-1;
        int size=0;
        int *Q=NULL;

        Queue(int size)
        {
            this->size = size;
            Q = new int[size];
        }

        void Enqueue(int x); //Insertion
        int Dequeue(); //Deletion
        void Disp();
};

void Queue :: Disp()
{
    for(int i=f+1; i<size; i++) 
    {
        cout<<Q[i]<<" ";
    }
}

void Queue :: Enqueue(int x)
{
    if(r==size-1)
        cout<<"\nQueue is full.";
    else{
        r++;
        Q[r] = x;
    }
}

int Queue :: Dequeue()
{
    int x=-1;
    if(f==r)
        cout<<"\nQueue is Empty.";

    else{
        f++;
        x = Q[f];
    }
    return x;
}

int main()
{
    int n;
    Queue q(5);

    for(int i=0; i<5; i++) 
    {
        cin>>n;
        q.Enqueue(n);
    }

    cout<<"\nElements in the Queue:- ";
    q.Disp();

    q.Dequeue();
    cout<<"\nUpdated Queue:- ";
    q.Disp();
    return 0;
}