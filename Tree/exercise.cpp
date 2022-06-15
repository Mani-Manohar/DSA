#include<iostream>
#include<math.h>
using namespace std;
#include "queue.h"
#include<vector>

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void swap(vector<long long>&arr,int i,int j)
    {
      if(i<j)
      {
        long long temp=0;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        swap(arr,i+1,j-1);
      }
    }
    
    void reverseInGroups(vector<long long>& arr, int n, int k)
    {
        int j=k-1;
        
        for(int i=0; i<n; i+=k)
        {
            if(j>=n)
                j=n-1;

            swap(arr,i,j);
            j = j+k;
        }
    }
};

int main()
{
  Solution s;
  vector<long long> v = {5,6,8,9};
  s.reverseInGroups(v,4,2);
  cout<<"Hi\n";
  for(int i=0; i<4; i++) 
  {
    cout<<v[i]<<" ";
  }
  // int *a = new int[n] ();
  
  // vector<int> a(n,0);
  return 0;
}