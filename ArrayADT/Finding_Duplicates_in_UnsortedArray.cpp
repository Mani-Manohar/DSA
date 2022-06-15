#include<iostream>
using namespace std;

//! Time complexity is O(n^2)
int main()
{
    int i,j;
    int count=1;

    int A[] = {3,6,8,8,10,12,15,15,15,20};
    int n = sizeof(A)/sizeof(A[0]);
    //cout<<n<<endl;
    for(int i=0; i<n-1; i++) 
    {
        count=1;
        if(A[i] != -1)
        {
            for(j=i+1; j<n; j++)
            {
                if(A[i] == A[j])
                {
                    count++;
                    A[j] = -1; //? We insert (-1) at A[j] bcoz to avoid counting same element once again if it appears so. In this eg. 6 is appearing at posn. 2, then again at posn. 4 & again at posn. 6.
                }
            }
            if(count>1)
                cout<<"Element:- "<<A[i]<<" Count:- "<<count<<endl;
        }
    }
    return 0;
}