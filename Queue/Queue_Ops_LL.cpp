#include<iostream>
using namespace std;

//? While implementing queue via LL insertion is done at REAR side & deletion is done from FRONT side.

class Node{
    public:
        int data;
        Node *next;
}*front=NULL,*rear=NULL;

class Queue{
    private:
        int size=0;
        Node *temp = new Node;
    public:
        Queue(int size)
        {
            this->size = size;
        }

        void Enqueue(int x);
        int Dequeue();
        int isEmpty();
        int isFull();

        void Disp();
};

void Queue :: Enqueue(int x)
{
    if(isFull())
        cout<<"\nQueue is full.";
    
    else{
        temp->data = x;
        temp->next = NULL;
        if(front==NULL)
        {
            front = rear = temp;
        }

        else{
            rear->next = temp;
            rear = temp;
        }
    }
}

int Queue :: Dequeue()
{
    int x=-1;

    if(isEmpty())
        cout<<"\nQueue is Empty.";
    
    else{
        temp = front;
        x = front->data;
        front = front->next;
        delete temp;
    }
    
    return x;
}

int Queue :: isEmpty()
{
    if(front == NULL)
        return 1;
    
    return 0;
}

int Queue :: isFull()
{
    temp = new Node;
    if(temp == NULL)
        return 1;
    
    return 0;
}

void Queue :: Disp()
{
    temp = front;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    Queue q(5);

    q.Enqueue(9);
    q.Enqueue(5);
    q.Enqueue(13);
    q.Enqueue(4);
    q.Enqueue(11);

    q.Disp();

    cout<<"\n"<<q.Dequeue()<<" is deleted."<<endl;
    q.Disp();
    cout<<"\n"<<q.Dequeue()<<" is deleted."<<endl;
    q.Disp();
    cout<<"\n"<<q.Dequeue()<<" is deleted."<<endl;
    q.Disp();
    cout<<"\n"<<q.Dequeue()<<" is deleted."<<endl;
    q.Disp();
    cout<<"\n"<<q.Dequeue()<<" is deleted."<<endl;
    q.Disp();
    cout<<"\n"<<q.Dequeue()<<" is deleted."<<endl;
    q.Disp();
    cout<<"\n"<<q.Dequeue()<<" is deleted."<<endl;
    q.Disp();
    return 0;
}