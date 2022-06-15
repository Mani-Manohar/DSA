#include<iostream>
using namespace std;

int c=0;

void TOH(int n, int A, int B, int C)
{
    
    if(n>0)
    {
        TOH(n-1,A,C,B);
        cout<<c<<"-Shift a disk from "<<A<<" to "<<C<<endl;
        c++;   
        TOH(n-1,B,A,C);
    }
   
    
}

int main()
{
    int n;
    cout<<"Enter the number of disks:- ";
    cin>> n;
    TOH(n, 1,2,3);
    cout<<"\nMoves:- "<<c<<endl;
    return 0;
}