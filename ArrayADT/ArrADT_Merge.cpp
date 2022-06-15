#include<iostream>
using namespace std;

//! The 2 arrays which are to be MERGED must be already SORTED.

class Array
{
    private:
    int *A;
    int size;
    int length; 

    public:
    static int count;
    Array() //This constuctor has nothing to do here
    {
        size = 10;
        length = 0;
    }
    
    void create()
    {
        cout<<"enter length of array"<<count<<":- ";
        cin>>length;
        A = new int[length];

        for(int i=0; i<length; i++) 
            cin>>A[i];

        count++;
    }

    Array* Merge(Array arr2)
    {
        int i,j,k;
        i=j=k=0;

        Array *arr3 = new Array[length + arr2.length];
        while(i<length && j<arr2.length)
        {
            if(A[i]<arr2.A[j])
                arr3->A[k++]=A[i++];
            else
                arr3->A[k++]=arr2.A[j++];
        }
        for(;i<length;i++)
            arr3->A[k++]=A[i];

        for(;j<arr2.length;j++)
            arr3->A[k++]=arr2.A[j];

        arr3->length=length+arr2.length;

        return arr3;
    }

    void display()
    {
        cout<<"Entered elements:- ";
        for (int i=0; i<length; i++)  
            cout<<A[i]<<" ";
    }
};

int Array :: count=1; //? count variable is declared just for array nos. i.e 'array1','array2'.

int main()
{
    Array arr1;
    Array arr2;
    Array *arr3;
    arr1.create();
    arr2.create();
    arr3 = arr1.Merge(arr2);
    arr3->display();
}