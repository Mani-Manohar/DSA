#include<iostream>
using namespace std;

//!Arrays entered must be sorted  

class Array
{
    private:
    int *A;
    int size;
    int length;

    public:
    Array()
    {

    }
    Array(int *A, int size, int length)
    {
        this->A = A;
        this->size = size;
        this->length = length;
    }

    void create()
    {
        cout<<"enter length of array:- ";
        cin>>length;
        A = new int[length];

        for(int i=0; i<length; i++) 
            cin>>A[i];
    }


    Array* Union(Array arr2)
    {
        int i,j,k;
        i=j=k=0;

        Array *arr3 = new Array[length+arr2.length];

        while(i<length && j<arr2.length)
        {
            if(A[i]<arr2.A[j])
                arr3->A[k++] = A[i++];

            else if(arr2.A[j]<A[i])
                arr3->A[k++] = arr2.A[j++];

            else
            {
                arr3->A[k++] = A[i++];
                j++;
            }
        }

        for(;i<length; i++)
            arr3->A[k++] = A[i];

        for(;j<arr2.length; j++)
            arr3->A[k++] = arr2.A[j];
    
        arr3->length = k;
        return arr3;
    }

    Array* Intersection(Array arr2)
    {
        int i,j,k;
        i=j=k=0;

        Array *arr3 = new Array[length+arr2.length];

        while(i<length && j<arr2.length)
        {
            if(A[i]<arr2.A[j])
                i++;
            else if(arr2.A[j]<A[i])
                j++;
            else 
            {
                arr3->A[k++] = A[i++];
                j++;
            }
        }    
        arr3->length = k;
        return arr3;
    }

    Array* Difference(Array arr2)
    {
        int i,j,k;
        i=j=k=0;

        Array *arr3 = new Array[length+arr2.length];

        while(i<length && j<arr2.length)
        {
            if(A[i]<arr2.A[j])
                arr3->A[k++] = A[i++];

            else if(arr2.A[j]<A[i])
                j++;

            else
            {
                i++;
                j++;
            }
        }

        for(;i<length; i++)
            arr3->A[k++] = A[i];

        arr3->length = k;
        return arr3;
    }

    void display()
    {
        cout<<"\nDiplaying:- ";
        for (int i=0; i<length; i++)  
            cout<<A[i]<<" ";
            cout<<endl;
    }
};

int main()
{
    int z;
    int A[] = {1,2,3,4,5};
    int B[] = {2,4,6,7,8};
    Array arr1(A,10,5);
    Array arr2(B,10,5);
    Array *arr3;
    // arr1.create();
    // arr2.create();

    
    do
    {
         cout<<"\tSet Functions:- \n";
            cout<<"1) Union\n";
            cout<<"2) Intersection\n";
            cout<<"3) Difference\n";
            cout<<"4) Display\n";
            cout<<"5) Exit\n";
        
            
            cout<<"Enter your choice:- ";
            cin>>z;
            switch(z)
            {
                case 1:
                arr3=arr1.Union(arr2);
                arr3->display();
                break;

                case 2:
                arr3=arr1.Intersection(arr2);
                arr3->display();
                break;

                case 3:
                arr3=arr1.Difference(arr2);
                arr3->display();
                break;

                case 4:
                break;


                default:
                cout<<"\nEnter correct choice.";
                break;
            }
    }while(z<4);    
            
            return 0;
}