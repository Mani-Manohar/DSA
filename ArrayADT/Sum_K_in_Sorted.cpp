#include<iostream>
using namespace std;

int main()
{
    int A[] = {1,3,4,5,6,8,9,10,12,14};
    int n = sizeof(A)/sizeof(A[0]);
    int i=0,j=n-1,k=10;

    while(i<j)
    {
        if(A[i]+A[j]==k)
        {
            cout<<A[i]<<" + "<<A[j]<<" = "<<k<<endl;
            i++;
            j--;
        }
        else if(A[i]+A[j]<k)
            i++;
        else
            j--;
    }
    return 0;
}