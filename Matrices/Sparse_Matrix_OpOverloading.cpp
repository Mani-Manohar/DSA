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
        Element *ele;

    public:
    Sparse()
    {
        
    }
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element[this->num];
    }
        Sparse operator+(Sparse &s);

        friend istream& operator>>(istream &in, Sparse &s);
        friend ostream& operator<<(ostream &out, Sparse &s);
};

istream& operator>>(istream &in, Sparse &s)
{
    cout<<"Enter the dimensions(m,n):- ";
    in>>s.m>>s.n;

    cout<<"Enter no. of non-zero elements:- ";
    in>>s.num;
    s.ele = new Element[s.num];

    cout<<"Enter non-zero elements in the format-(row,col,element):- \n";
    for(int i=0; i<s.num; i++) 
    {
        in>> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }

    return in;
}

ostream& operator<<(ostream &out, Sparse &s)
{
    int k=0;
    for(int i=0; i<s.m; i++) 
    {      
        for(int j=0; j<s.n; j++) 
        {
            if(s.ele[k].i==i && s.ele[k].j==j)
                out<<s.ele[k++].x<<" ";

            else
                out<<"0 "; 
        }
        out<<"\n";
    }
    return out;
}

Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    if(m != s.m || n != s.n){
        cout<<"\nCannot add as dimensions of both of the arrays are not equal.\n";
        return Sparse(0,0,0);
    }
    
        Sparse *sum = new Sparse(m,n, num + s.num);
        i = j = k = 0;
        while (i < num && j < s.num)
        {
            if (ele[i].i < s.ele[j].i)
                sum->ele[k++] = ele[i++];
            else if (ele[i].i > s.ele[j].i)
                sum->ele[k++] = s.ele[j++];
            else
            {
                if (ele[i].j < s.ele[j].j)
                    sum->ele[k++] = ele[i++];
                else if (ele[i].j > s.ele[j].j)
                    sum->ele[k++] = s.ele[j++];
                else
                {
                    sum->ele[k] = ele[i];
                    sum->ele[k++].x = ele[i++].x + s.ele[j++].x;
                }
            }
        }
        for (; i < num; i++)
            sum->ele[k++] = ele[i];
        for (; j < s.num; j++)
            sum->ele[k++] = s.ele[j];
            sum->num=k;

        return *sum;
}

int main()
{
    Sparse s1,s2;
    cin>>s1;
    cin>>s2;

    Sparse sum = s1+s2;

    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<sum;
    return 0;
}