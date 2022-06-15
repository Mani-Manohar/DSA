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

    void Append(int x)
    {
        if(length<size)
            A[length++] = x;// x is assigned to length first & then length is incremented 
    }

    void insert(int index, int x)
    {
        if(index>=0 && index<=length)
        {
            for(int i=length; i>index; i--)
                A[i] = A[i-1];

            A[index] = x;
            length++; //length incremented bcoz new element inserted
        }
    }

    void Dispaly()
    {
        for(int i=0; i<length; i++)
            cout<<A[i]<<" ";
    }

};

int main()
{
    int B[] = {2,3,4,5,6};
    Array arr(B,10,5);
    arr.Append(99);
    arr.insert(3,10);
    arr.Dispaly();


    return 0;
}