#include<iostream>
using namespace std;

//! Time Comlexity O(n).

int main()
{
    char A[] = "decimal";
    char B[] = "medical";

    int h1=0,h2=0,h3=0;
    int i,x;

    for(i=0; A[i]!='\0'; i++)
    {
        x=1;
        x = x<<(A[i]-97);
        h1 = h1|x;
    }
    
    for(i=0; B[i]!='\0'; i++)
    {
        x=1;
        x = x<<(B[i]-97);
        h2 = h2|x;
    }
    
    if(h1 == h2)
        cout<<"Strings are ANAGRAM.";

    else
        cout<<"Strings are not ANAGRAM.";
        
    return 0;
}