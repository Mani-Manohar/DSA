#include <iostream>
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
        this->length = length;
        this->size = size;
    }

    void del(int index)
    {
        int x = A[index];
        if(index>=0 && index<length)
        {
            for(int i=index; i<length-1; i++)
            {
                A[i] = A[i+1];
            }
        }
        length--;
        
       
        cout<<x<<" is deleted\n";

        for(int i=0; i<length; i++)
            cout<<A[i]<<" ";
    }
};

int main()
{
    int B[] = {2,3,4,5,6};
    Array arr(B,10,5);
    
    arr.del(3);
}