#include<iostream>
#include<stdlib.h>
using namespace std;

//? This method uses HASHING
//!Time Complexity is O(n)
int MAX(int A[], int n)
{
    int max = A[0];
    for(int i=0; i<n; i++) 
    {
        if(max < A[i])
            max = A[i];
    }
    return max;
}

int main()
{
    
    int A[] = {8,3,6,4,20,6,5,20,10,8,2,7,10};//3,6,8,8,10,12,15,15,15,20
    int n = sizeof(A)/sizeof(A[0]);
    
    int max = MAX(A,n);
    //cout<<"max "<<max<<endl;
    //int *hash = new int[max];

    int *hash = (int*)calloc(max+1,sizeof(int));//Used Calloc() bcoz it initialises hash to '0' by default.

    for(int i=0; i<n; i++) 
    {
        hash[A[i]]++;
    }

    for(int i=0; i<max+1; i++) 
    {
        if(hash[i]>1)
            cout<<i<<" count:- "<<hash[i]<<endl;
    }
    return 0;
}