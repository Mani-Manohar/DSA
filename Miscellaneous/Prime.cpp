#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
//! Time Complexity is o(sqrt(n)).
int Prime_2(int n)//? This code currently cheks only if "n" is prime or not
{
    for(int i=2;i*i<=n;i++)
        if(n%i == 0)
            return 0;
            
        return 1;
}

//! Time Complexity is N*log(log(n)).
void Prime_1()//? Sieve of Eratosthenes
{
    int *a = new int [1000000] ();
    // int p=1;
    for(int i=2; i*i<=40; i++) //? If a number N has a prime factor larger than √N , then it surely has a prime factor smaller than √N.
    {
        if(a[i]==0)
        {
            for(int j=i*i; j<=40; j+=i) 
            {
                a[j] = 1;
            }
        }
    }

    for(int i=2; i<=40; i++)
    {
        if(a[i] == 0)
        {
             cout<<i<<" ";
        }
    }

}

int main()
{
    Prime_1();
    // OR
    cout<<Prime_2(3);
    return 0;
}