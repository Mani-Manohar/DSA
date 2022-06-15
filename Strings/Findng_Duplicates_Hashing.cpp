#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    char A[] = "innings";

    int hash[26] = {};//By leaving curly braces blank it initialises all elements to 0.

    for(int i=0; A[i]!='\0'; i++) 
    {
        hash[A[i]-97]++;
    }

    // for(int i=0; i<26; i++) 
    // {
    //     cout.width(2);
    //     cout<<i;
    //     cout.width(3);
    //     cout<<"- "<<hash[i]<<endl;
    // } (For Printing Hash)

    for(int i=0; i<26; i++) 
    {
        if(hash[i] >= 2)
            cout<<(char)(97+i)<<" has occured "<<hash[i]<<" times.\n";
    }
    return 0;
}