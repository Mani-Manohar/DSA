#include<iostream>
using namespace std;
//! Time Comlexity O(n).

int main()
{
    int j=0,x=0,c=0,k=0;
    string s = "cbaebabacd";
    string p = "abc";

    int hash[3] = {};
    int res[5];
    while(j<=7)
    {
        for(int i=j; i<3; i++)
        {
            for(k=0; k<3; k++)
            {
                if(s[i] == p[k] && hash[k]<=1)
                {
                    hash[k]++;
                    break;
                }
            }
            k=0;
        }
    }

    for(int i=0; i<3; i++) 
    {
        if(hash[i] == 1)
            c++;
        if(c == 3)
        {
            res[x] = j;
            x++;
        }
        hash[i] = 0;
    }

    j++;
    c=0;
    return 0;
}
