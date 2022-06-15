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

    int IsSorted()
    {
        for(int i=0; i<length-1; i++) 
            if(A[i]>A[i+1])
                return false;

            return 1;
    }

    void InsertSort(int x)
    {
        int i = length-1;
        if(length == size)
            return;

        while(i>=0 && A[i]>x)
        {
            A[i+1] = A[i];
            i--;
        }

        A[i+1] = x;
        length++;    
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
    int B[]= {2,3,5,10,15};
    Array arr(B,10,5);

    arr.InsertSort(7);
    //cout<<arr.IsSorted();
    arr.display();
}