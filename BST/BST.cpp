#include<iostream>
using namespace std;
#include "queue.h"
#include<stack>

class BST
{
    public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    void Insert(int key);
    Node*  R_Insert(Node *p, int key);
    Node* Search(int key);
    Node* R_Search(Node *p, int key);
    Node* Delete(Node *p, int key);
    Node* FindMin(Node *p);
    void Generate_Tree_From_PreOrder(int P[],int n);

};

void BST :: Insert(int key)
{
    Node *p = root;

    Node *r,*temp; //? Here *r is tail pointer of p.

    if(root==NULL)//If Tree has Nothing(NULL), we simply create a new node, which is first node of the Tree.
    {
        temp = new Node;
        temp->data = key;
        root=temp;
        return;
    }

    while(p!=NULL)//Searching Part
    {
        r=p;//For the purpose of Tailing Pointer ==> 'r' follows 'p'
        if(p->data<key)
            p = p->rchild;

        else if(p->data>key)
            p = p->lchild;

        else //If element 'key' is already there in TREE, then simply return.
        return;
    }
    temp = new Node;
    temp->data = key;

    if(r->data < key)
        r->rchild = temp;
    else
        r->lchild = temp;
}

Node* BST :: R_Insert(Node *p, int key)
{
    Node *temp=NULL;
    if(p == NULL)
    {
        temp = new Node;
        temp->data = key;
        return temp;
    }

    if(p->data < key)
        p->rchild = R_Insert(p->rchild,key);

    else if(p->data > key)
        p->lchild = R_Insert(p->lchild,key);

        return p;//if the data to be inserted is already present then just return p;
}

Node* BST :: Search(int key)
{   Node *p=root;
       
    while(p!=NULL)
    {
        if(p->data == key)
            return p;

        if(p->data < key)
            p = p->rchild;

        else
            p = p->lchild;
    }

    return NULL; //if found nothing return NULL
}

Node* BST :: R_Search(Node *p, int key)
{
    if(p == NULL)
        return NULL;

    if(p->data == key)
        return p;

    else if(p->data < key)
        return R_Search(p->rchild,key);

    else
       return R_Search(p->lchild,key);
}

Node* BST :: Delete(Node *p, int key)//! refer MyCodeSchool YT to understand this better
{

    if(p==NULL)
        return NULL;

    else if(p->data > key)
        p->lchild = Delete(p->lchild,key);

    else if(p->data < key)
        p->rchild = Delete(p->rchild,key);

    else{
        //Case 1: No Child
        if(p->lchild==NULL && p->rchild==NULL)
        {
            delete p;
            p = NULL;
        }
        
        //Case 2: Only 1 Child(Either Left or Right)
        else if(p->lchild == NULL)
        {
            Node *temp = p;
            p = p->rchild;
            delete temp;
        }
        else if(p->rchild == NULL)
        {
            Node *temp = p;
            p = p->lchild;
            delete temp;
        }

        //Case 3: 2 Children
        else
        {
            Node *temp = FindMin(p->rchild);
            p->data = temp->data;
            p->rchild = Delete(p->rchild,temp->data);
        }
    }
    
    return p;
}

Node* BST :: FindMin(Node *p)
{
    while(p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

void BST :: Generate_Tree_From_PreOrder(int P[],int n)
{
    int i=0;
    Node *p,*t;

    stack<Node*> stk;//!This code is a part of STL for creating STACK

    while(i<n)
    {
        if(i == 0)//For Creating Root Node
        {
            t = new Node;
            t->data = P[i++];
            root = t;
            p = t;
        }

        if(p->data > P[i])
        {
            t = new Node;
            t->data = P[i++];
            p->lchild = t;
            stk.push(p);
            p = t;
        }

        else{
            if(P[i] > p->data && P[i]<stk.empty()?INT16_MAX:stk.top()->data)//!To understand this part must watch Udemy lecture-309 (here INT16_MAX is assumed as infinity).
            {
                t = new Node;
                t->data = P[i++];
                p->rchild = t;
                p=t;
            }

            else
            {
                p = stk.top();
                stk.pop();
            }
        }            
    }
}

void Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

int main()
{
    BST t;
    t.root = t.R_Insert(t.root,10);
    t.R_Insert(t.root,20);
    t.R_Insert(t.root,12);
    t.R_Insert(t.root,16);
    t.R_Insert(t.root,13);  
    // t.R_Insert(t.root,35);  
    // t.R_Insert(t.root,50);  
    // t.R_Insert(t.root,8); 
    // t.R_Insert(t.root,41);  
    // t.R_Insert(t.root,44);  
    // t.R_Insert(t.root,42);
    // t.R_Insert(t.root,45);

    cout<<endl;
    Inorder(t.root);

    // t.Delete(t.root,12);

    // cout<<endl;
    // Inorder(t.root);
    // if(t.R_Search(t.root,30)!=NULL)
    // cout<<"\nElement Found.";

    // else
    // cout<<"\nElement not found.";
    return 0;
}