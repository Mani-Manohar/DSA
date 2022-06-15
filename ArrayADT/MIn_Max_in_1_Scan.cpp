#include<iostream>
using namespace std;

int main()
{
    int A[] = {5,8,3,9,6,2,10,7,-1,4};
    int n = sizeof(A)/sizeof(A[0]);
    int min = A[0];
    int max = A[0];

    for(int i=1; i<n; i++) 
    {
        if(A[i]<min)
            min = A[i];

        if(A[i]>max)
            max = A[i];
    }

    cout<<"Min:- "<<min;
    cout<<"\nMax:- "<<max;
    return 0;
}