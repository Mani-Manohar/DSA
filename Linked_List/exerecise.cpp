#include<iostream>
using namespace std;

int main()
{
    int *p = new int [10] ();

for(int i=0; i<10; i++) 
{
    cout<<i<<" - "<<p[i]<<endl;
}
    return 0;
}