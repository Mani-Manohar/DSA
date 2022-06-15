#include<iostream>
using namespace std;

/* Time Complexity of this program is O(n) */

int power(int m, int n)
{
    if(n == 0)
        return 1;

    else
        return power(m, n-1) * m;
}

int main()
{
    int x = power(2,9);
    cout<<"power:- "<<x;
}