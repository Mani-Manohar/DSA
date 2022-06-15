#include<iostream>
using namespace std;

int main()
{
    char A[] = "Painting";
    char B[] = "Painterman";
    int i,j;

    for(i=0,j=0; A[i]!='\0' || B[j]!='\0'; i++,j++)
    {
        if(A[i]!=B[j])
            break;
    }

    if(A[i] == B[j])
        cout<<"Strings are EQUAL.\n";
    else if(A[i]<B[j])
        cout<<"String A is SMALLER the String B.\n";
    else
        cout<<"Stirng A is LARGER than String B.\n";
    return 0;
}