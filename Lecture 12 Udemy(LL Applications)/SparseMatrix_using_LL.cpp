#include<iostream>
using namespace std;

class Node
{
    public:
        int col;
        int data;
        Node* next;
}*last;

class Sparse
{
    private:
        int m;
        int n;
        Node **A;
    public:
        Sparse(int r, int c)
        {
            this->m = r;
            this->n = c;
            A = new Node*[m];
            int nz=0,data=0,cn;

            for(int i=0; i<m; i++)
            {
                cout<<"Enter the no. of non-zero elements of row-"<<i;
                cin>>nz;

                A[i] = NULL;

                for(int k=0; k<nz; k++) 
                {
                    cout<<"Enter the non-zero col no. & data:- ";
                    cin>>cn>>data;

                    if(k==0)
                    {
                        Node *p = new Node;
                        A[i] = p;
                        p->col = cn;
                        p->data = data;
                        p->next = NULL;
                        last = p;
                    }
                    
                    else{
                        Node *p = new Node;
                        p->col = cn;
                        p->data = data;
                        p->next = NULL;
                        last->next = p;
                        last = p;
                    }
                }
            }
        }     

        void Disp()
        {
            cout<<"\n\t Sparse Matrix\n\n";
            
            for(int i=0; i<m; i++) 
            {
                Node *p = A[i];
                for(int j=0; j<n; j++) 
                {   
                    if(p!=NULL && p->col == j)
                    {
                        cout<<p->data<<" ";
                        p = p->next;
                    }

                    else{
                        cout<<"0 ";
                    }
                }
                cout<<endl;
            }
        }

        void Add(Sparse s)
        {
            if(m!=s.m)
            {
                cout<<"Matrix Size Mismatch, Cannot add";
                return;
            }
            else{
                for(int i=0; i<m; i++) 
                {
                    Node *p = A[i];
                    Node *q = s.A[i];
                    for(int j=0; j<n; j++) 
                    {
                        if(p!=NULL && q!=NULL && p->col==j && q->col==j)
                        {
                            cout<<p->data+q->data<<" ";
                            p = p->next;
                            q = q->next;
                        }

                        else if(q!=NULL && q->col==j)
                        {
                            cout<<q->data<<" ";
                            q = q->next;
                        }

                        else if(p!=NULL && p->col==j)
                        {
                            cout<<p->data<<" ";
                            p = p->next;
                        }

                        else{
                            cout<<"0 ";
                        }
                    }

                    cout<<endl;
                }
            }
        }
};



int main()
{
    Sparse s1(3,3);
    cout<<endl;
    Sparse s2(3,3);
    s1.Disp();
    cout<<endl;
    s2.Disp();
    cout<<"\n\tAdded Matrix\n\n";
    s1.Add(s2);
    return 0;
}