#include<iostream>
using namespace std;

class Array
{
    private:
    int *A;
    int size;
    int length;

    public:
    Array(int *A, int size, int length)
    {
        this->A = A;
        this->size = size;
        this->length = length;
    }
    void NegOnLeft()
    {
        int i=0;
        int j=length-1;
        while(i<j)
        {
            while(A[i]<0)
                i++;

            while(A[j]>=0)
                j--;
            //&& A[i]>0 && A[j]<=0
            if(i<j)
                swap(&A[i],&A[j]);
        }
    }

    void swap(int *x, int *y)
    {
        int temp;
        temp=*x;
        *x=*y;
        *y=temp;
    }

    void display()
    {
        cout<<"Entered elements:- ";
        for (int i=0; i<length; i++)  
            cout<<A[i]<<" ";
    }
};

int main()
{
    int B[]= {-1,7,3,-2,-9,0,6,-4};
            // 0 1 2  3  4 5 6  7
    Array arr(B,10,8);
    arr.NegOnLeft();
    arr.display();
}