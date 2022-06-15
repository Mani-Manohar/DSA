#include<iostream>
using namespace std;

class Array
{
    private:
    int *A;
    int size;
    int length;

    public:
    int Sum();
    float Avg();
    Array(int *A, int size, int length)
    {
        this->A = A;
        this->size = size;
        this->length = length;
    }

    int Get(int index)
    {
        if(index>=0 && index<length)
            return A[index];
        return -1;
    }

    void Set(int index, int x)
    {
        if(index>=0 && index<length)
            A[index] = x;
    }

    int Max()
    {
        int max,i;
        max = A[0];
        for(i=0; i<length; i++)
        {
            if(A[i]>max)
                max = A[i];
        }
    return max;
    }

    int Min()
    {
        int min,i;
        min = A[0];
        for(i=0; i<length; i++)
        {
            if(A[i]<min)
                min = A[i];
        }
    return min;
    }

   
};

int Array :: Sum()
    {
        int sum=0;
        for(int i=0; i<length; i++) 
            sum = sum+A[i];
        return sum;
    }

float Array :: Avg()
    {
        return (float)Sum()/length;
    }

int main()
{
    int B[]= {2,3,4,5,6,7};
    Array arr(B,10,6);

    cout<<arr.Avg();
}