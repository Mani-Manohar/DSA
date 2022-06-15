#include<iostream>
using namespace std;

int main()
{

    char A[] = "How are   u";
    int count=1;

    for(int i=0; A[i]!='\0'; i++) 
    {
        if(A[i]==' ' && A[i-1]!=' ')
            count++;
    }

    cout<<"no. of words:- "<<count;
    return 0;
}