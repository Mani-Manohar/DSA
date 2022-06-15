#include<iostream>
#include<cmath>
using namespace std;

class Node{
    public:
        int coef;
        int exp;
        Node *next;
};

class Poly{
    private:
        int n;
        Node *first=NULL,*last=NULL;
    public:
        Poly()
        {
            cout<<"Enter no. of terms:- ";
            cin>>n;
        }

        Node* Create();
        void Disp();
        Poly operator+(Poly &p);
};

Node* Poly :: Create(){
    for(int i=0; i<n; i++) 
    {
        Node *temp = new Node;
        temp->next = NULL;

        if(i==0)
        {
            last = first = temp;
        }

        else
        {
            last->next = temp;
        }

        cout<<"Enter coeff. & exp.:- ";
        cin>>temp->coef>>temp->exp;
        
        last = temp;
    }
    return first;
}

void Poly :: Disp(){
    Node *p = first;

    for(int i=0; i<n; i++ && p!=NULL) 
    {
        if(p->exp == 0)
        {
            cout<<p->coef;
        }
        else
        cout<<p->coef<<"x^"<<p->exp;

        if(i<n-1)
        {
            cout<<" + ";
        }
        p = p->next;
    }
}

Poly Poly :: operator+(Poly &p){
    Node *a=first, *b=p.first,*f,*l;//? Here '*f' & '*l' represents first and last node of resultant LL.
    int x=0,sum=0;

    while(a && b)
    {
       Node *temp=new Node;
        if(a == first && b==p.first)//! This part of code is wrote to make the *f pointer to point first node of resultant LL & this will be executed only once in the whole while_loop iteration.
        {
            f=l=temp;
        }

        if(a->exp == b->exp)
        {
            temp->coef = a->coef+b->coef;
            temp->exp = a->exp;       
            a=a->next;
            b=b->next;
        }

        else{
            if(a->exp > b->exp)
            {
                temp->coef = a->coef;
                temp->exp = a->exp;               
                a=a->next;
            }

            else{
                temp->coef = b->coef;
                temp->exp = b->exp;
                b=b->next;
            }
        }
        temp->next = NULL;
        l->next=temp;
        l=l->next; 
    }
    
    if(a){
        l->next = a;
    }

    else{
        l->next=b;
    }

    //For Printing resultant Polynomial
        Node *k = f;
        while(k)
        {
            if(k->exp == 0)
            {
                cout<<k->coef;
            }
            else
                cout<<k->coef<<"x^"<<k->exp;
            if(k->next!=NULL)
                cout<<" + ";

            k = k->next;
        }
}

int main()
{
    
    Poly p1;
    cout<<"Enter 1st Polynomial:- \n";
    p1.Create();
    cout<<"\n";

    Poly p2;
    cout<<"Enter 2nd Polynomial:- \n";    
    p2.Create();
    cout<<"\n";

    cout<<"Polynomial-1:- ";p1.Disp();
    cout<<"\n\n";
    cout<<"Polynomial-2:- ";p2.Disp();

    cout<<"\n\np1 + p2 = ";
    p1 + p2;
    // p3.Disp();
    return 0;
}