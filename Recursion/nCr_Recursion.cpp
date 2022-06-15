#include<iostream>
using namespace std;

int nCr(int n, int r)
{
    if(r==0 || n==r)
        return 1;
    if(r==1)
        return  n;

    else
    {
        return nCr(n-1,r) + nCr(n-1,r-1);
    }
    
}

int main()
{
    cout<<"nCr:- "<<nCr(5,2);
    return 0;
}