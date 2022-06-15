#include<iostream>
using namespace std;

class Array
{
    int *A;
    int size;
    int length;

public:
    Array(int *A, int size, int lenght)
    {
        this->A = A;
        this->size = size;
        this->length = lenght;
    }
    
    void display()
    {
        //cout<<"Entered elements:- ";
        for (int i=0; i<length; i++)  
            cout<<A[i]<<" ";
    }

    void Lshift()
    {
        for(int i=0; i<length; i++) 
            A[i] = A[i+1];
        A[length-1] = 0;
    }

    void LRotate()
    {
        int temp;
        temp = A[0];
        for(int i=0; i<length; i++) 
            A[i] = A[i+1];
        A[length-1] = temp;
    }
    
    void Rshift()
    {
        for(int i=length; i>=0; i--) 
        {
            A[i] = A[i-1];
        }
        A[0] = 0;
    }

    void RRotate()
    {
        int temp;
        temp = A[length-1];
        for(int i=length; i>=0; i--) 
            A[i] = A[i-1];
        A[0] = temp;
    }
};

int main()
{
    int B[] = {1,2,3,4,5};
    Array arr(B,10,5);

    arr.RRotate();
    arr.display();
}