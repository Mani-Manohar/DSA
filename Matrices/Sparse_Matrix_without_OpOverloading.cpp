#include<iostream>
using namespace std;

class Element
{
    public:
    int i;
    int j;
    int x;
};

class Sparse
{
    private:
        int m;
        int n;
        int num;
        Element *A;
    
    public:
        void create();
        void Display(Sparse *s1);
        void Add(Sparse *s1, Sparse *s2);
};

void Sparse :: create()
{
    cout<<"Enter the dimensions(m,n):- ";
    cin>>m>>n;

    cout<<"Enter no. of non-zero elements:- ";
    cin>>num;
    A = new Element[num];

    cout<<"Enter non-zero elements in the format-(row,col,element):- \n";
    for(int i=0; i<num; i++) 
    {
        cin>>A[i].i>>A[i].j>>A[i].x;
    }
}

void Sparse :: Display(Sparse *s1)
{
    int k=0;
    for(int i=0; i<s1->m; i++) 
    {
        for(int j=0; j<s1->n; j++) 
        {
            if(A[k].i==i && A[k].j==j)
                cout<<A[k++].x<<" ";

            else
                cout<<"0 ";
        }
        cout<<"\n";
    }
    cout<<endl;
}

void Sparse :: Add(Sparse *s1, Sparse *s2)
{

    if(s1->m!=s2->m || s1->n!=s2->n)
        cout<<"\nCannot add as dimensions of both of the arrays are not equal.\n";
    
    else
    {
        int c=0,d=0,z=0;        
        A = new Element[s1->num + s2->num];

            while(c<s1->num && d<s2->num)
            {
                if(s1->A[c].i < s2->A[d].i)
                    A[z++] = s1->A[c++];


                else if(s1->A[c].i > s2->A[d].i)
                    A[z++] = s2->A[d++];


                else
                {
                    if(s1->A[c].j < s2->A[d].j)
                    {
                        A[z++] = s1->A[c++];
                    }
                    else if(s1->A[c].j > s2->A[d].j)
                    {
                        A[z++] = s2->A[d++];
                    }
                    else
                    {
                        A[z] = s1->A[c];
                        A[z++].x = s1->A[c++].x + s2->A[d++].x;
                    }
                }
            }

            for( ;c<s1->num; c++)   
                A[z++] = s1->A[c];
            for( ;d<s2->num; d++)
                A[z++] = s2->A[d];
    }
}

int main()
{
    Sparse s1,s2,s3;
    s1.create();
    cout<<"\nFirst Array\n";
    s1.Display(&s1);
    s2.create();
    cout<<"\nSecond Array";
    s2.Display(&s2);

    s3.Add(&s1,&s2);

    cout<<"\nAdded Array\n";
    s3.Display(&s1);// passing s1 as argument bcoz we need value m & n.
    return 0;
}

    // s2.Display();
    // s1.Display();
    // cout<<"\n";
/*  0 0 3 0 0   0 0 0 0 2
    4 0 0 0 7   0 5 0 0 6
    0 0 5 0 8   4 0 8 0 0
    0 6 0 0 0   0 0 0 0 9*/
    