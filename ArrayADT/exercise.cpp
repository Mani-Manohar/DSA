#include<iostream>
using namespace std;

int main()
{
    int a[7] = {25,15,10,78,89,45,67};
    int temp;
    for(int i=0; i<7; i++) 
    {
        for(int j=i-1; j<7 && j>=0; j--) 
        {
            if(a[j+1]<a[j])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }

            else
                break;
        }
    }
    

    for(int i=0; i<7; i++) 
    {
        cout<<a[i]<<" ";
    }
    return 0;
}