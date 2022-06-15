#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

void create(int A[], int n, Node *p)
{
    static int i=1;
    if(i==n)
        return;
    
    //Node *last;
    Node *temp = new Node;
    p->next = temp;
    temp->data = A[i++];
    temp->next = NULL;
    //last = temp;
    
    create(A, n, temp);
}

void Display(Node *p)
{
    if(p != NULL)
        cout<<p->data<<" ";

    Display(p->next);
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    Node *first,*last;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    //last = first;
    
    create(A,5, first);

    Display(first);
    return 0;
}