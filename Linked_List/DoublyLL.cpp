#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
} * first, *last;

Node *Create(int A[], int n)
{
    Node *temp;
    first = new Node;

    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        last->next = temp;
        temp->prev = last;
        temp->data = A[i];
        temp->next = NULL;
        last = temp;
    }
    return first;
}

void Disp(Node *p)
{
    int i = 1;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

Node *Insert(int pos, int data)
{
    Node *p = first, *temp = new Node;
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    if (pos == 0)
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }

    else
    {

        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        temp->next = p->next;
        temp->prev = p;

        if (p->next)
            p->next->prev = temp;
        p->next = temp;
    }
    return first;
}

int Delete(int pos)
{
    Node *p = first;
    int x;
    if (pos == 1)
    {
        first = first->next;
        x = p->data;
        delete p;

        if (first->next)
            first->prev = NULL;
    }

    else
    {

        for (int i=0; i<pos-1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;

        x = p->data;
        delete p;
    }
    return x;
}

void Reverse(Node *p)
{
    Node *temp = NULL;
    while (p)
    {
        temp = p->prev;
        p->prev = p->next;
        p->next = temp;

        first = p;
        p = p->prev;
    }
}

int main()
{
    int A[] = {5, 7, 11, 9, 2};
    int n = sizeof(A) / sizeof(A[0]);
    Node *a;
    int pos, data;

    a = Create(A, 5);

    Disp(a);
    // cout<<"\n\nEnter position & data:- ";
    // cin>>pos>>data;

    // a = Insert(pos,data);

    // cout<<"\nEnter the postion:- ";
    // cin>>pos;
    // Delete(pos);

    cout << "\n\n Reversed List:- ";
    Reverse(first);
    Disp(first);

    return 0;
}