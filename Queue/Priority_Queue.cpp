#include<iostream>
using namespace std;

class Node{
    public:
        char ch;
        int p;
        Node *next;
}*first=NULL,*last=NULL;

class Queue
{
    public:
        int  f=-1,r=-1;
        int size=6;
        char *Q = new char [size] ();

        void Enqueue(char x); //Insertion
        char Dequeue(); //Deletion
        void Disp();
        int isEmpty();
        int isFull();
}Q1,Q2,Q3;//? just to implement priority queue took only 3 queues, Q1 with highest priority & Q3 with the least.

void Queue :: Disp()
{
    for(int i=f+1; i<size; i++) 
    {
        cout<<Q[i]<<" ";
    }
}

void Queue :: Enqueue(char x)
{
    if(r==size-1)
        cout<<"\nQueue is full.";
    else{
        r++;
        Q[r] = x;
    }
}

char Queue :: Dequeue()
{
    char x=-1;
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
    if(r==size-1)
        return 1;

    return 0;
}

int main()
{
    char ch;
    int p;
    int flag=1,choice=0;

    for(int i=0; i<10; i++) 
    {
        cout<<"Enter char & priority:- ";
        cin>>ch>>p;
            
            Node *temp = new Node;
            temp->ch = ch;
            temp->p = p;
            temp->next = NULL;
        if(i == 0)
        { 
            first = temp;
            last  = temp;
        }
        
        else{
            last->next = temp;
            last = temp;
        }
    }

    Node *t = first;
    // while(t!=NULL)
    // {
    //     cout<<t->ch<<"-"<<t->p<<endl;
    //     t=t->next;
    // }

    for(int i=0; i<10; i++)
    {
        if(t->p == 1)
        {
            Q1.Enqueue(t->ch);
        }

        else if(t->p == 2)
        {
            Q2.Enqueue(t->ch);
        }

        else{
            Q3.Enqueue(t->ch);
        }
        t=t->next;
    }

    cout<<"\nDisplaying Queue1:- ";
    Q1.Disp();

    cout<<"\nDisplaying Queue2:- ";
    Q2.Disp();

    cout<<"\nDisplaying Queue3:- ";
    Q3.Disp();


    cout<<"\n\nTo Enqueue  press 2\nTo delete press 1\nTo stop press 0\n";


    while(flag)
    {
        cin>>choice;
        if(choice==1)
        {
            if(Q1.r != Q1.f)
            {
                Q1.Dequeue();
            }

            else if(Q2.r != Q2.f)
            {
                Q2.Dequeue();
            }

            else if(Q3.r != Q3.f)
            {
                Q3.Dequeue();
            }

            else{
                cout<<"\nThere's nothing to delete, Enter '0' & exit.\n";
            }
        }

        else if(choice==2)
        {
            cout<<"\nEnter the char & priority:- ";
            cin>>ch>>p;
            if(Q1.r!=Q1.size-1 && p==1)
            {                
                Q1.Enqueue(ch);
            }

            else if(Q2.r!=Q2.size-1 && p==2)
            {
                Q2.Enqueue(ch);
            }

            else if(Q3.r!=Q3.size-1 && p==3)
            {
                Q3.Enqueue(ch);
            }
        }
        

        else{
            flag=0;
        }
        
        cout<<"\n";
        Q1.Disp();
        cout<<"\n";
        Q2.Disp();
        cout<<"\n";
        Q3.Disp();
        cout<<"\n";
    }
    return 0;
}