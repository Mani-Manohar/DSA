#include<iostream>
using namespace std;

/*Time Complexity of this program is O(log n), because 
at every step n is getting divided by 2 */

int Power(int m ,int n)
{
    if(n == 0)
        return 1;

    if(n%2 == 0)
        return Power(m*m, n/2);

    else
        return m*Power(m*m, (n-1)/2);
}

int main()
{
    int x;
    x = Power(2,9);
    cout<<"Power:- "<<x;
}