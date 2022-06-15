#include<iostream>
using namespace std;

int main()
{
    char A[] = "nitin";
    int i,j,len;
    for(len=0; A[len]!='\0';len++)
    {}
    len = len-1;
  
    for(i=0,j=len; i<=len,j>=0; i++,j--) 
    {
        if(A[i] != A[j])
            break;
    }
    if(i-1 == len)
        cout<<"String is Palindrome.";
    else   
        cout<<"String is not a Palindrome.";

    return 0;
}