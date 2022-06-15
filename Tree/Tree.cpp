#include<iostream>
using namespace std;
#include "queue.h"


class Tree{
    public:
        Node *root;
        
        Tree()
        {
            root=NULL;
        }

        void create();
        void Preorder(Node *p);
        void Inorder(Node *p);
        void Postorder(Node *p);
        void LevelOrder(Node *p);

        void Iterative_Pre(Node *p);
        void Iterative_In(Node *p);

        Node* Generate_Tree_From_Traversal(int In[], int Pre[], int m, int n);
        int Search(int I[], int start, int end, int x);//This fn. is used inside "Generate_Tree_From_Traversal" fn.
        
        int Count(Node *p);
        int Height(Node *p);

};

void Tree :: create()
{
    Node *p,*t;
    int x;
    Queue Q(10); //? creating Queue of size 10

    cout<<"\nEnter the root value:- ";
    cin>>x;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    Q.Enqueue(root);

    while(Q.isEmpty()!=1)
    {
        p = Q.Dequeue();

        cout<<"\nEnter Left child of "<< p->data<<" :- ";
        cin>>x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            Q.Enqueue(t);
            p->lchild = t;
        }

        cout<<"\nEnter right child of "<< p->data<<" :- ";
        cin>>x;
        if(x != -1)
        {
            t= new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            Q.Enqueue(t);
            p->rchild = t;
        }
    }
}

void Tree :: Preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree ::  Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

void Tree ::  Postorder(Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void Tree :: Iterative_Pre(Node *p)
{
    Node *t = p;
    Node **S = new Node*[10];
    int top=-1;


    while(t!=NULL || top!=-1)
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";

            top++;      //? PUSH Operation
            S[top] = t; //? PUSH Operation

            t = t->lchild;
        }
        
        else
        {
            t = S[top]; //? POP Operation
            top--;      //? POP Operation

            t = t->rchild;
        }
    }
}

void Tree :: Iterative_In(Node *p)
{
    Node *t = p;
    Node **S = new Node*[10];
    int top=-1;

    while(t!=NULL || top!=-1)
    {
        if(t!=NULL)
        {
            top++;
            S[top] = t;

            t = t->lchild;
        }

        else{
            t = S[top];
            top--;

            cout<<t->data<<" ";

            t=t->rchild;
        }
    }
}

Node* Tree :: Generate_Tree_From_Traversal(int In[], int Pre[], int start, int end)
{
    //? Refer notes for explanation diagram.
    //'start' & 'end' points on InOrder Array
    static int i=0; //'i' iterates on PreOrder Arrray

    if(start>end)
        return NULL;

    Node *t = new Node;//Creating Node
    t->data =Pre[i++];//Storing data from PreOrder Array

    if(start==end)
        return t;

    int k = Search(In,start,end,t->data);

    t->lchild = Generate_Tree_From_Traversal(In,Pre,start,k-1);
    t->rchild = Generate_Tree_From_Traversal(In,Pre,k+1,end);

    return t;
}

void Tree :: LevelOrder(Node *p)
{
    Node *t=p;
    Node* *Q = new Node*[10];//'*Q' will store address of new Node & the type of data being stored is of 'Node*'.
    int f=-1,r=-1;
    cout<<t->data<<" ";
    r++;
    Q[r] = t;

    while (f!=r)
    {
        f++;
        t = Q[f];

        if(t->lchild!=NULL)
        {
            r++;
            Q[r] = t->lchild;
            cout<<t->lchild->data<<" ";
        }
        
        if(t->rchild!=NULL)
        {
            r++;
            Q[r] = t->rchild;
            cout<<t->rchild->data<<" ";
        }
    }
}

int Tree :: Count(Node *p)
{
    int x=0,y=0;

    if(p==NULL)
        return 0;

    if(p)
    {
        return Count(p->lchild)+Count(p->rchild)+1;
    }

    //!The above fn. can also be written as below
    // if(p)
    // {
    //     x=Count(p->lchild);
    //     y=Count(p->rchild);

    //     return x+y+1;
    // }

}

int Tree ::  Height(Node *p)
{
    int x=0,y=0;

    if(p)
    {
        x=Count(p->lchild);
        y=Count(p->rchild);

        if(x>y)
            return x+1;

        else
            return y+1;
    }
            return -1;//?Here we are returning -1 instead of 0 bcoz in height the egdes are counted rather than nodes.
}


int Tree:: Search(int I[], int start, int end, int x)
{
    while(start<=end)
    {
        if(I[start]==x)
            return start;
        
        start++;
    } 
}

int main()
{
    Tree t; 
    // t.create();
    // cout<<"\nCount:- ";
    // cout<<t.Count(t.root);

    int I[] = {7,6,9,3,4,5,8,2,1};//Inorder array
    int P[] = {4,7,9,6,3,2,5,8,1};//Preorder array

    t.root = t.Generate_Tree_From_Traversal(I,P,0,8);

    cout<<"\n\nInorder :- "<<endl;
    t.Inorder(t.root);
    return 0;
}