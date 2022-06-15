#include<iostream>
using namespace std;

class LowerTriangle
{
    private:
        int n;
        int index;
        int non_zero;
        int *A;
    public:
        LowerTriangle(int n)
        {
            this->n = n;
            non_zero = n*(n+1)/2;
            A = new int[non_zero];
        }

        void Set(int i, int j, int x)
        {
            if(j<=i)
            {
                index = (i*(i-1))/2 + (j-1);
                A[index] = x;
            }
        }

        int Get(int i, int j)
        {
            if(j<=i)
            {
                index = (i*(i-1))/2 + (j-1);
                return A[index];
            }

            else
                return 0;
        }

        void Display()
        {           
            for(int i=1; i<=n; i++) 
            {
                for(int j=1; j<=n; j++) 
                {
                    if(j<=i)
                    {
                        index = (i*(i-1))/2 + (j-1);
                        cout<<A[index]<<" ";
                    }
                    else
                        cout<<"0 ";
                }
                cout<<"\n";
            }
        }
};

int main()
{
    LowerTriangle Lt(5);

    Lt.Set(1,1,1);
    Lt.Set(2,1,2);
    Lt.Set(2,2,3);
    Lt.Set(3,1,4);
    Lt.Set(3,2,5);
    Lt.Set(3,3,6);
    Lt.Set(4,1,7);
    Lt.Set(4,2,8);
    Lt.Set(4,3,9);
    Lt.Set(4,4,10);
    Lt.Set(5,1,11);
    Lt.Set(5,2,12);
    Lt.Set(5,3,13);
    Lt.Set(5,4,14);
    Lt.Set(5,5,15);

    Lt.Display();
    return 0;
}