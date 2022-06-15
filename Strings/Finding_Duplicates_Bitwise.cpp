#include<iostream>
using namespace std;
//? '&'(Anding) is known as masking, which is performed to check whether the bit is ON or OFF.
//? "|"(Or) is known as merging, it is used to set a bit ON or OFF.
int main()
{
    char A[] = "innings";
    int H1=0,H2=0,x=0;

    for(int i=0; A[i]!='\0'; i++) 
    {
        x=1;
        x=x<<(A[i]-97);
        if( (x&H1) > 0)
            H2 = (H1&x) | H2;
        else
            H1 = x|H1;
    }
    //! The code below is to print the duplicates for 1 time.
    x=1;
    int count=0;
    while(count>=0 && count<=25)
    {
        if((H2&x) > 0)
        {
            cout<<(char)(count+97)<<" is duplicate.\n";
        }
        x = x<<1;
        count++;
    }
    return 0;
}