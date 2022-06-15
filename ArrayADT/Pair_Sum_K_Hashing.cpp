#include<iostream>
using namespace std;

//! Time complexity is O(n)
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
    int max,k=10;
    int A[] = {6,3,8,10,16,7,5,2,9,14};
    int n = sizeof(A)/sizeof(A[0]);

    max = MAX(A,n);
    
    int *hash = (int*)calloc(max+1,sizeof(int));
    
    for(int i=0; i<n; i++)
    {
        hash[A[i]]++;
    }
    // 0 0 1 1 0 1 1 1 1 1 1  0  0  0  1  0  1
   //! 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
    
    // 0 0 1 2 0 2 1 1 2 1 1  0  0  0  1  0  1
    for(int i=0; i<n; i++) 
    {
        if(hash[k-A[i]]==1 && A[i]<=k)
        {
            cout<<A[i]<<" + "<<k-A[i]<<" = "<<k<<endl;
            hash[A[i]]=0;
        }   
           
    }
    cout<<endl;
    for(int i=0; i<max+1; i++) 
    {
        cout<<hash[i]<<" ";
    }
    return 0;
}