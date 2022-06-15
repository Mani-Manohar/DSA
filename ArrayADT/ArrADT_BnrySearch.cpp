#include<iostream>
using namespace std;

//! For BnrySearch the list must be sorted

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
       
    //* While loop method
    int BnrySearch(int key)
    {
        int l=0;
        int mid;
        int h=length;

        while(l<=h)
        {
            mid = (l+h)/2;

            if(key == A[mid])
                return mid;
            else if(key<A[mid])
                h = mid-1;
            else
                l = mid+1;
        }
        return -1;
    }

    //* Recursion method(Tail Recursion)
    int RBS(int l, int h, int key)
    {
        int mid = (l+h)/2;
        if(l<=h)
        {
            if(key == A[mid])
                return mid;
            else if(key<A[mid])
                RBS(l,mid-1,key);
            else
                RBS(mid+1,h,key);
        }
        
        return -1;
    }
};

int main()
{            //0,1,2,3,4
    int B[] = {2,3,4,5,6};
    Array arr(B,10,5);

     cout<<arr.RBS(0,4,6); //Recusive call
            //Or
    //cout<<arr.BnrySearch(5); //! loop call
}