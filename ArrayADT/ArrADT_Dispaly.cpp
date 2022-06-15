#include <iostream>
using namespace std;
 
class Array
{
    private:
    int *A;
    int size;
    int length;

    public:
    Array(int size)
    {
        this->size = size;
        A = new int[size];
    }

    void create()
    {
        cout<<"Enter the no. of elements to be inserted in array:- ";
        cin>>length;
        cout<<"Enter the elements:- "<<endl;
        for(int i=0; i<length; i++)
        {
            cout<<"Element "<<i<<":- ";
            cin>>A[i];
        }
    }

    void display()
    {
        cout<<"Entered elements:- ";
        for (int i=0; i<length; i++)  
            cout<<A[i]<<" ";
    }

    ~Array()
    {
        cout<<"\nObject Destroyed";
    }
};

int main()
{
    Array arr(10);
    arr.create();
    arr.display();
    return 0;
}