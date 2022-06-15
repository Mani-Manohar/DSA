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

    void RevMethod_1()
    {
        int *B = new int[length];

        for(int i=length-1,j=0; i>=0; i--,j++) 
            B[j] = A[i];

        for(int i=0; i<length; i++) 
            A[i] = B[i];
    }

    void RevMethod_2()
    {
        int temp;
        for(int i=0,j=length-1; i<j; i++,j--)
        {
            temp = A[j];//6
            A[j] = A[i];//2
            A[i] = temp;//6
            
        }
    }
};

int main()
{
    int B[] = {2,3,4,5,6};
    Array arr(B,10,5);

    arr.RevMethod_2();

    for(int i=0; i<5; i++) 
        cout<<B[i]<<" ";
}