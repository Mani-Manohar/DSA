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

    void swap(int *x, int *y)
    {
        int temp;

        temp = *x;
        *x = *y;
        *y = temp;
    }

    int LinearSearch(int key)
    {
        for(int i=0; i<length; i++)
            if(key == A[i])
            {
                swap(&A[i], &A[i-1]); //!Transposition:- Moving 'key' 1 location backward by swapping.
                    //?OR
                //swap(&A[i], &A[0]); //!Move to Head:- Swapping the 'key' with first element.
                return i;
            }

        return -1;
    }

    void display()
    {
        for(int i=0; i<length; i++)
            cout<<A[i]<<" ";
    }
};

int main()
{
    int B[] = {2,3,4,5,6};
             //0,1,2,3,4(index)

    int key,result;
    Array arr(B,10,5); 
    
    cout<<"Enter the element to be searched:- ";
    cin>>key;
    
    result = arr.LinearSearch(key);
    if(result != -1)
        cout<<"\nElement found at location "<<result<<endl;
    else
        cout<<"Element not found"<<endl;
    //arr.swap(&B[3], &B[2]);
    
    arr.display();
    return 0;
}