#include<iostream>
using namespace std;

class Queue{
    public:
        int f=0,r=0; //! front & rear is '0' here not '-1'
        int size=0;
        int *Q=NULL;

        Queue(int size)
        {
            this->size = size;
            Q = new int[size];
        }

        int Enqueue(int x); //Insertion
        int Dequeue(); //Deletion
        void Disp();
};

int Queue :: Enqueue(int x)
{
    if((r+1)%size == f)
    {
        cout<<"\nQueue is full, hence "<<x<<" cannot be inserted.";
        return 0;
    }

    else{
        r = (r+1)%size;
        Q[r] = x;
        return 1;
    }
}

int Queue :: Dequeue()
{
    int x=-1;

    if(r==f)
        cout<<"\nQueue is Empty";

    else{
        f = (f+1)%size;
        x = Q[f];
    }
    return x;
}

void Queue :: Disp()
{
    int i=f+1;

    do
    {
        cout<<Q[i]<<" ";        
        i = (i+1)%size;

    } while(i!=(r+1)%size);

}

int main()
{
    int n,f=1;
    Queue q(7);

    while(f)
    {
        cout<<"Enter the value:- ";
        cin>>n;
        f = q.Enqueue(n);
    }

    cout<<endl;
    q.Disp();

    cout<<"\nDeleted element:- "<<q.Dequeue()<<endl;

    q.Disp();
    cout<<endl;
    f = q.Enqueue(8);
    q.Disp();
    return 0;
}