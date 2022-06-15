#include<iostream>
using namespace std;

//!Reference:- https://www.codingninjas.com/blog/2020/09/09/floyds-cycle-detection-algorithm/

class Node
{
    public:
        int data;
        Node *next;
}*first=NULL,*last=NULL;

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
    last->next = first->next->next->next;//last node(4) is pointing to node 7.
    return first;
}

Node* getStartNodeOfLoopInLinklist(Node *head)
{
    Node *fast,*slow;
    fast=slow=head;

    while(fast && slow && fast->next)
    {
        fast = fast->next;
        slow = slow->next;

        if(fast)
            fast = fast->next;

        if(fast == slow)      
        {
            // cout<<"\nslow==fast:- "<<slow->data<<endl;
            slow = head;
            // cout<<"\nslow=head:- "<<slow->data<<endl;
            while(slow != fast)
            {
                slow = slow->next;
                // cout<<"\nslow:- "<<slow->data<<endl;
                fast = fast->next;
                // cout<<"\nfast:- "<<fast->data<<endl;
            }

            return slow;//or return fast;
        }
    }
    
    return NULL;//if there is no loop return NULL
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

int main()
{
    int A[] = {2,5,8,7,9,3,4};
    int size = sizeof(A[0])/sizeof(A);

    Node *head = create(A,7);

    cout<<"\n"<<getStartNodeOfLoopInLinklist(head)->data;
    //? Now by the above function we get the starting node of the loop & by this we can remove the loop and make it linear.
    return 0;
}