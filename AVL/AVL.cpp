#include<iostream>
using namespace std;

class Node{
    public:
    Node *lchild=NULL;
    int data;
    Node *rchild=NULL;
    int height=1;
};

class AVL{
    public:
    Node *root=NULL;

    Node *RInsert(Node *p,int key);
    Node* Delete(Node *p,int key);

    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* FindMin(Node *p);

    void LLRotation(Node* p);
    void LRRotation(Node* p);
    void RRRotation(Node* p);
    Node* RLRotation(Node* p);
};

int AVL::NodeHeight(Node *p) {
    int hl;
    int hr;
 
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
 
    return hl > hr ? hl + 1 : hr + 1;
}
 
int AVL::BalanceFactor(Node *p) {
    int hl;
    int hr;
 
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
 
    return hl - hr;
}
 
void AVL::LLRotation(Node *p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
 
    pl->rchild = p;
    p->lchild = plr;
 
    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
 
    // Update root
    if (root == p){
        root = pl;
    }
    // return pl;
}

void AVL::RRRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    //Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if(root == p)
        root = pr;
}

void AVL::LRRotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    //Update height
    plr->height = NodeHeight(plr);
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);

    if(root == p)
        root = plr;
}

Node* AVL::RLRotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->rchild = pr;
    prl->lchild = p;

    //Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);

    if(root == p)
        root = prl;

        cout<<"\nroot in RL fn:- "<<root->data;
        return root;
}

Node* AVL :: RInsert(Node *p, int key)
{
    Node *temp=NULL;
    if(p == NULL)
    {
        temp = new Node;
        temp->data = key;
        return temp;
    }

    if(p->data < key)
        p->rchild = RInsert(p->rchild,key);

    else if(p->data > key)
        p->lchild = RInsert(p->lchild,key);

    p->height = NodeHeight(p);

    if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
        LLRotation(p);

    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
        RRRotation(p);

    else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
        LRRotation(p);

    else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
        RLRotation(p);

        return p;//if the data to be inserted is already present then just return p;
}

Node* AVL :: Delete(Node *p, int key)
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
    
    //Updating height
    if(p)
    p->height = NodeHeight(p);

    if(p)
    {
        if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==1)
            LLRotation(p);

        else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==-1)
            RRRotation(p);

        else if(BalanceFactor(p)==2 && BalanceFactor(p->lchild)==-1)
            LRRotation(p);

        else if(BalanceFactor(p)==-2 && BalanceFactor(p->rchild)==1)
            return RLRotation(p);
    }
    return p;
}

Node* AVL :: FindMin(Node *p)
{
    while(p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
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
    AVL t;

    t.root = t.RInsert(t.root,30);
    t.RInsert(t.root, 20);
    t.RInsert(t.root, 40);
    t.RInsert(t.root, 15);
    t.RInsert(t.root, 38);
    t.RInsert(t.root, 42);
    t.RInsert(t.root, 37);
    t.RInsert(t.root, 39);
    cout<<"\nroot->data:- "<<t.root->data;

    t.root = t.Delete(t.root,15);
    cout<<"\nroot->data:- "<<t.root->data;

    return 0;
}