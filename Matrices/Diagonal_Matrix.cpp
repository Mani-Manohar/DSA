#include<iostream>
using namespace std;

class Diagonal{
    private:
        int *A;
        int n;
    public:
        Diagonal(int n)
        {
            this->n = n;
            A = new int[n];
        }

        void Set(int i, int j, int x)
        {
            if(i==j)
                A[i-1]=x;
        }

        int Get(int i,int j)
        {
            if(i==j)
                return A[i];
            else
                return 0;
        }

        void Display()
        {
            for(int i=0; i<n; i++) 
            {
                for(int j=0; j<n; j++) 
                {
                    if(i==j)
                        cout<<A[i]<<" ";
                    else
                        cout<<"0 ";
                }
                cout<<"\n";
            }
        }
};

int main()
{
    Diagonal D(4);
    D.Set(1,1,5);
    D.Set(2,2,3);
    D.Set(3,3,8);
    D.Set(4,4,6);

    D.Display();
    cout<<"\n";
    cout<<D.Get(0,0);
    cout<<"\n";
    cout<<D.Get(1,1);
    cout<<"\n";
    cout<<D.Get(2,2);
    cout<<"\n";
    cout<<D.Get(3,3);
    

    return 0;
}