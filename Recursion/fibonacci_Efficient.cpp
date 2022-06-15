#include<iostream>
using namespace std;

int f[10];

int fib(int n)
{
    if(n<=1)
    {
        f[n] = n;
        return n;
    }

    else
    {
        if(f[n-2] == -1)
            f[n-2] = fib(n-2);

        if(f[n-1] == -1)
            f[n-1] = fib(n-1);
            
        return f[n-2] + f[n-1];
    } 
}

int main()
{
    int n;
    //Initialising array elements with -1
    for(int i=0; i<10; i++)
        f[i] = -1;
    

    cout<<"Enter n:- ";
    cin>>n;
    

    f[n] = fib(n);
    cout<<"Fibonacci sequence number of "<<n<<" is:- "<<f[n]<<endl;

    //Printing Fibonacci Sequnece
    for(int i=0; i<=n; i++)
        cout<<" "<<f[i];

}