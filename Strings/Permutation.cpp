#include<iostream>
using namespace std;

void Permute(string s, int k)
{
    static int A[10] = {};//here array elements will be initialised to zero.
    static char res[10];

    if(s[k] == '\0')
    {
        res[k] = '\0';
        cout<<res<<endl;
    }

    else
    {
        for(int i=0; s[i]!='\0'; i++) 
        {
            if(A[i] == 0)
            {
                res[k] = s[i];
                A[i] = 1;
                Permute(s,k+1);
                A[i]=0;
            }
        }
    }
}

int main()
{
    // char a[4] = "abc";
    string a = "abc";
    Permute(a, 0);
    return 0;
}