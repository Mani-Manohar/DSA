#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
} *first, *last;

Node* Create(int A[], int n)
{
    first = new Node;
    Node *temp;

    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++) 
    {
        temp = new Node;

        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    last->next = first;
    return first;
}

void Display(Node *disp)
{
    do
    {
        cout<<disp->data<<" ";
        disp = disp->next;
    }
    while(disp != first);
}


void R_Display(Node *disp)
{
    cout<<disp->data<<" ";
    disp = disp->next;
    
    if(disp != first)
        R_Display(disp);
}

int Length(Node *a)
{
    int len=0;
    do{
        a = a->next;
        len++;
    }
    while(a != first);
    return len;
}

void Insert(int pos, int x)
{
    Node *p = first;
    Node *temp = new Node;
    
    temp->data = x;
    temp->next = NULL;

    if(pos == 0)
    {
        if(first == NULL) //?This is situation where the new node is the first node
        {
            first = temp;
            first->next = first;
        }

        else
        {
            while(p->next != first)
                p = p->next;

            p->next = temp;
            temp->next = first;
            first = temp;
        }
    }

    else
    {
        for(int i=0; i<pos-1; i++) 
            p = p->next;

        temp->next = p->next;
        p->next = temp;
    }
}

int Delete(int index)
{
    int x = 0;
    Node *q, *p = first;

    if(index == 1)
    {
        while(p->next != first)
                p = p->next;
        x = first->data;

        if(first == p)//?This is a situation where there is only one node in the LL
        {
            free(first);
            first=NULL;
        }

        else{
            p->next = first->next;
            free(first);
            first = p->next;
        }
    }

    else{
        for(int i=0; i<index-2; i++) 
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }

    return x;
}
int main()
{
    int index=0;
    int pos=0,x=-1,w=1;
    int A[] = {10,2,44,32,67,4};
    int n = sizeof(A)/sizeof(A[0]);
    Node *a;
    a = Create(A,n);
    R_Display(a);

    // cout<<"\n\nEnter the position and data:- "<<endl;
    // cin>>pos>>x;
    // cout<<"Length:- "<<Length(first)<<endl;

    // while(w)
    // {
    //     if(pos<=Length(first)){
    //         Insert(pos, x);
    //         w=0;
    //     }

    //     else{
    //         cout<<"\n\tInvalid Position\nRe-Enter the position and data:-"<<endl;
    //         cin>>pos>>x;
    //     }
    // }

    // cout<<"\n\nUpdated Circular_LL:- ";
    // Display(first);

    cout<<"\nEnter the index of the node to be deleted:- ";
    cin>>index;

    cout<<Delete(index)<<" has been deleted\n";

    cout<<"\nUpdated List:- ";
    Display(first);
    return 0;
}