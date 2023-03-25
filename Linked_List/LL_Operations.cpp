#include<iostream>
using namespace std;
//! **** Contents ****
//? Create
//? Diaplay
//? Sum
//? Rsum
//? Max
//? Rmax
//? Search
//? Rsearch
//? Improvised Search
//? Insert
//? SortedInsertion    
//? Delete
//? Reversing_by_Elements
//? Reversing_by_Links
//? R_Reversing_by_links
//? reverseBySwap
//? Concatenate
//? Merge
//? Is_Loop
//? Display_Circular_LL
//? RDisplay_Circular_LL


class Node
{
    public:
        int data;
        Node *next=NULL;
}*first,*last;

Node* create(int A[], int n)
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
    // last->next = first->next->next;
    // last->next = first;
    return first;
}

void Display(Node *x)
{
    Node *temp = x;
    // cout<<"Elements in the Linked-List:-\n";
    while(temp!=0) 
    {
        // cout<<temp->data<<" - "<<temp<<endl;
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void sum()
{
    Node *temp = first;
    int sum=0;
    while(temp!=0)
    {
        sum = sum + temp->data;
        temp = temp->next;
    }
    cout<<"\nSum:- "<<sum;
}

int Rsum(Node *temp)
{
    if(temp == 0)
    {
        return 0;
    }
    return Rsum(temp->next)+temp->data;    
}

int max()
{
    Node *temp = first;
    int max=0;
    while(temp != 0)
    {
        if(temp->data > max)
            max = temp->data;
        temp = temp->next;
    }
    return max;
}

int Rmax(Node *temp)
{
    static int max=0;
    if(temp == 0)
        return INT32_MIN;

    else{
        if(temp->data > max)
            max = temp->data;

        Rmax(temp->next);        
    }
    return max;
}

Node* Search(int key)
{
    Node* temp = first;
    while(temp)
    {
        if(temp->data == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

Node* Rsearch(Node *temp, int key)
{
    if(temp == 0)
        return NULL;
    
    if(key == temp->data)
        return temp;
        
    Rsearch(temp->next, key);
}

Node* Improvised_Search(int key)
{
    Node* q = NULL;
    Node* temp = first;
    while(temp)
    {
        if(key == temp->data)
        {
            q->next = temp->next;
            temp->next = first;
            first = temp;
            return temp;
        }
        q=temp;
        temp = temp->next;
    }
}

void Insert(int x, int pos)
{
    Node *temp = new Node;

    if(pos == 0)
    {
        temp->data = x;
        temp->next = first;
        first = temp;   
    }

    else if(pos > 0)
    {
        temp = first;
        Node *p = new Node;
        for(int i=0; i<pos-1 && temp; i++) 
        {
            temp = temp->next;
        }

        if(temp)
        {
            p->data = x;
            p->next = temp->next;
            temp->next = p;
        }
    }
}

void SortedInsertion(int x)
{
    Node *q , *p = first;
    Node *n = new Node;
    n->data = x;
    n->next = NULL;
    if(first == NULL)
        first = n;

    else
    {
        while(p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if(p == first)
        {
            n->next = first;
            first = n;
        }
        else{
            n->next = q->next;
            q->next = n;
        }
    }
}

int Delete(int pos)
{
    Node *p,*q = NULL;
    int x=-1;

    if(pos == 1)
    {
        p = first;
        x = first->data;
        first = first->next;
        delete p;
    }

    else{
        p = first;
        for(int i=0; i<pos-1 && p; i++) 
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}

bool Is_Sorted()
{
    Node *p = first;
    int x = INT32_MIN;
    while(p)
    {
        if(p->data < x)
            return false;

        x = p->data;
        p = p->next;
    }
    return true;
}

void Reversing_by_Elements(int length)
{
    Node *p = first;
    int *A = new int[length];
    int i=0;
    while(p)
    {
        A[i++] = p->data;
        p = p->next;
    }
    
    p = first;
    while(p)
    {
        p->data = A[--i];
        p = p->next;
    }
}

void Reversing_by_Links(int length)//? Sliding Pointer Method
{
    Node *p = first;
    Node *q = NULL, *r = NULL;
    while(p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void R_Reversing_by_links(Node *p, Node*q)
{
    if(p != NULL)
    {
        R_Reversing_by_links(p->next, p);
        p->next = q;
    }

    else{
        first = q;
    }
}

Node* reverseBySwap(Node* head) {
        Node* curr = head, *prev=NULL;

        while(curr != NULL)
        {
            swap(curr->next, prev);
            swap(prev, curr);
        }

        return prev;
    }

void Concatenate(Node *p, Node *q)
{
    while(p->next)
    {
        p = p->next;
    }
    p->next = q;
}

void Merge(Node *a, Node *b)
{
    Node *c,*last;
    if(a->data < b->data)
    {
        c = last = a;
        a = a->next;
        last->next = NULL;
    }

    else{
        c = last = b;
        b = b->next;
        last->next = NULL;
    }

    while(a && b)
    {
        if(a->data < b->data)
        {
            last->next = a;
            last = a;
            a = a->next;
            last->next = NULL;
        }

        else{
            last->next = b;
            last = b;
            b = b->next;
            last->next = NULL;
        }
    }
    if(a!=NULL)
    {
        last->next = a;
    }
    else{
        last->next = b;
    }
}

bool detectLoop(Node* head)
{
    Node* p = head;
    Node*q = head;
    
    while(q!=NULL && q->next!=NULL)
    {
        p = p->next;
        
        q = q->next->next;
        if(p == q)
            return true;
    }
    
    return false;
}

void Find_Middle()
{
    Node *p = first, *q = first;
    
     while(q!=NULL && q->next!=NULL)
    {
        p = p->next;
        q = q->next->next;
    }
    cout<<"Middle Element is:- "<<p->data;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int B[] = {9, 30, 71, 82};
    Node *a, *b;
    a = create(A,5);
    //cout<<isLoop(a);
    //b = create(B,4);
    // Find_Middle();
    // Display(a);
    cout<<detectLoop(first);
    return 0;
}
