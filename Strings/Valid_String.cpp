#include<iostream>
using namespace std;

int valid(char const *name)
{
    for(int i=0; name[i]!='\0'; i++) 
    {
        if(!(name[i]>=65 && name[i]<=90)&&
            !(name[i]>=97 && name[i]<=122)&&
            !(name[i]>=48 && name[i]<=57))
                return 0;
    }
    return 1;
}

int main()
{
    char const *name = "MOneY@006";// used (char const*) bcoz it was thowing a WARNING.

    if(valid(name))
        cout<<"String is VALID.";
    else
        cout<<"String is NOT VALID.";
    return 0;
}