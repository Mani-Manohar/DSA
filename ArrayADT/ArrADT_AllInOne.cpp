#include<iostream>
using namespace std;

class Array
{
    private:
    int *A;
    int size;
    int length;

    public:
    Array()
    {
        size = 5;
        length=0;
        A = new int[size];
    }
    Array(int sz)
    {
        size = sz;
        length=0;
        A = new int[size];
    }
    void create();
    void display();
    void insert(int x,int index);
    void del(int index);
    int IsSorted();
    void InsertSort(int x);   
    void swap(int *x, int *y);
    //*ArrFunctions   
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    //*ArrFunctions
    void RevMethod_1();
    void RevMethod_2();
    int LinearSearch(int key);
    int BnrySearch(int key);
    int RBS(int l, int h, int key);
    //*SetOps
    Array* Union(Array arr2);
    Array* Intersection(Array arr2);
    Array* Difference(Array arr2);
    Array* Merge(Array arr2);
    //*SetOps
    //?ShiftRotate
    void LShift();
    void LRotate();
    void RShift();
    void RRotate();
    //?ShiftRotate
};

int Array :: Get(int index)
{
    if(index>=0 && index<length)
        return A[index];
    return -1;
}

void Array :: Set(int index, int x)
{
    if(index>=0 && index<length)
        A[index] = x;
}

int Array :: Max()
{
    int max,i;
    max = A[0];
    for(i=0; i<length; i++)
    {
        if(A[i]>max)
            max = A[i];
    }
return max;
}

int Array :: Min()
{
    int min,i;
    min = A[0];
    for(i=0; i<length; i++)
    {
        if(A[i]<min)
            min = A[i];
    }
return min;
}

int Array :: Sum()
{
    int sum=0;
    for(int i=0; i<length; i++) 
        sum = sum+A[i];
    return sum;
}

float Array :: Avg()
{
    return (float)Sum()/length;
}

//* While loop method
int Array :: BnrySearch(int key)
{
    int l=0;
    int mid;
    int h=length;

    while(l<=h)
    {
        mid = (l+h)/2;

        if(key == A[mid])
            return mid;
        else if(key<A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

//* Recursion method
int Array :: RBS(int l, int h, int key)
{
    int mid = (l+h)/2;
    if(l<=h)
    {
        if(key == A[mid])
            return mid;
        else if(key<A[mid])
            RBS(l,mid-1,key);
        else
            RBS(mid+1,h,key);
    }
        return -1;
}

void Array :: del(int index)
{
    
    int x = A[index];
    if(index>=0 && index<length)
    {
        for(int i=index; i<length-1; i++)
        {
            A[i] = A[i+1];
        }
    }
    length--;   
}

void Array::display()
{
    cout<<"Displaying:- ";
    for (int i=0; i<length; i++)  
        cout<<A[i]<<" ";
}

void Array :: insert(int x,int index)
{   
    if(index>=0 && index<=length)
    {
        for(int i=length; i>index; i--)
            A[i] = A[i-1];

        A[index] = x;
        length++; //length incremented bcoz new element inserted
    }
}

int Array :: IsSorted()
{
    for(int i=0; i<length-1; i++) 
        if(A[i]>A[i+1])
            return false;

        return 1;
}

void Array :: InsertSort(int x)
{
    int i = length-1;
    if(length == size)
        return;

    while(i>=0 && A[i]>x)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
    length++;    
}

void Array :: swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Array :: LinearSearch(int key)
{
    for(int i=0; i<length; i++)
        if(key == A[i])
        {
            //swap(&A[i], &A[i-1]); //!Transposition:- Moving 'key' 1 location backward by swapping.
                //?OR
            swap(&A[i], &A[0]); //!Move to Head:- Swapping the 'key' with first element.
            return i;
        }
    return -1;
}

Array* Array :: Merge(Array arr2)
{
    int i,j,k;
    i=j=k=0;

    Array *arr3 = new Array[length + arr2.length];
    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
            arr3->A[k++]=A[i++];
        else
            arr3->A[k++]=arr2.A[j++];
    }
    for(;i<length;i++)
        arr3->A[k++]=A[i];

    for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j];

    arr3->length=length+arr2.length;
    return arr3;
}

//* Reversing by copying 
void Array :: RevMethod_1()
{
    int *B = new int[length];

    for(int i=length-1,j=0; i>=0; i--,j++) 
        B[j] = A[i];

    for(int i=0; i<length; i++) 
        A[i] = B[i];
}

//* Reversing by modified swapping 
void Array :: RevMethod_2()
{
    int temp;
    for(int i=0,j=length-1; i<=j; i++,j--)
    {
        temp = A[j];
        A[j] = A[i];
        A[i] = temp;     
    }
}

Array* Array :: Union(Array arr2)
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

Array* Array :: Intersection(Array arr2)
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

Array* Array :: Difference(Array arr2)
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

void Array :: LShift()
{
    for(int i=0; i<length; i++) 
        A[i] = A[i+1];
    A[length-1] = 0;
}

void Array :: LRotate()
{
    int temp;
    temp = A[0];
    for(int i=0; i<length; i++) 
        A[i] = A[i+1];
    A[length-1] = temp;
}

void Array :: RShift()
{
    for(int i=length; i>=0; i--) 
    {
        A[i] = A[i-1];
    }
    A[0] = 0;
}

void Array :: RRotate()
{
    int temp;
    temp = A[length-1];
    for(int i=length; i>=0; i--) 
        A[i] = A[i-1];
    A[0] = temp;
}

void Array :: create()
{
    cout<<"Enter length of array:- ";
    cin>>length;

    cout<<"Enter the elements:-\n";
    for(int i=0; i<length; i++) 
        cin>>A[i];
}

int main()
{
    int ch;
    int size;
    int index,key,x;
    cout<<"Enter the size of the array:- ";
    cin>>size;
    Array arr1(size);
    Array arr2(size);
    Array* arr3;

    do
    {
        cout<<"\n\tMenu\n";
        cout<<"1) Create\n";
        cout<<"2) Insert\n";
        cout<<"3) Delete\n";
        cout<<"4) Display\n";
        cout<<"5) Array Functions\n";
        cout<<"6) Set Operations\n";
        cout<<"7) Shift-Rotate\n";
        cout<<"8) Exit\n";

    cout<<"Enter your choice:- ";
    cin>>ch;

        switch (ch)
        {
        case 1:
        arr1.create();
        break;

        case 2:
        cout<<"Enter element & where it must be inserted:- ";
        cin>>x>>index;
        arr1.insert(x,index);
        break;

        case 3:
        cout<<"Enter index of the element to be deleted:- ";
        cin>>index;
        arr1.del(index);
        break;

        case 4:
        arr1.display();
        break;

        case 5:
        while(1){
            cout<<"\n\tArray Functions:- \n";
            cout<<"a) Get\n";
            cout<<"b) Set\n";
            cout<<"c) Max\n";
            cout<<"d) Min\n";
            cout<<"e) Sum\n";
            cout<<"f) Avg\n";
            cout<<"g) Exit\n";
            
            char h;
            cout<<"Enter your choice:- ";
            cin>>h;
            switch(h)
            {
                case 'a':
                cout<<"Enter index to Get Element at that index:- ";
                cin>>index;
                cout<<"\nElement at "<<index<<" :- "<<arr1.Get(index);
                break;

                case 'b':
                cout<<"\nEnter index & element to Set element at that index:- ";
                cin>>index>>x;
                arr1.Set(index,x);
                break;

                case 'c':
                cout<<"\nMax element:- "<<arr1.Max();
                break;

                case 'd':
                cout<<"\nMin element:- "<<arr1.Min();
                break;

                case 'e':
                cout<<"\nSum :- "<<arr1.Sum();
                break;

                case 'f':
                cout<<"\nAverage :- "<<arr1.Avg();
                break;

                case 'g':
                break;

                default:
                cout<<"\nEnter correct choice.";
                break;
            }
            if(h == 'g')
            break;
        }
        break;

        case 6:
        
        arr1.create();
        arr2.create();
        while(1){
         cout<<"\n\tSet Functions:- \n";
            cout<<"a) Union\n";
            cout<<"b) Intersection\n";
            cout<<"c) Difference\n";
            cout<<"d) Exit\n";
            
            char z;
            cout<<"Enter your choice:- ";
            cin>>z;
            switch(z)
            {
                case 'a':
                arr3=arr1.Union(arr2);
                arr3->display();
                break;

                case 'b':
                arr3=arr1.Intersection(arr2);
                arr3->display();
                break;

                case 'c':
                arr3=arr1.Difference(arr2);
                arr3->display();
                break;

                case 'd':
                break;

                default:
                cout<<"\nEnter correct choice.";
                break;
            }
            if(z == 'd')
            break;
        }
        break;

        case 7:
        char y;
        while(1){
            cout<<"\n\tShift-Rotate Functions:- \n";
            cout<<"a) Left_Shift\n";
            cout<<"b) Left_Rotate\n";
            cout<<"c) Right_Shift\n";
            cout<<"d) Right_Rotate\n";
            cout<<"e) Exit\n";

            
            cout<<"Enter your choice:- ";
            cin>>y;

            switch(y)
            {
                case 'a':
                arr1.LShift();
                arr1.display();
                break;

                case 'b':
                arr1.LRotate();
                arr1.display();
                break;
                
                case 'c':
                arr1.RShift();
                arr1.display();
                break;

                case 'd':
                arr1.RRotate();
                arr1.display();
                break;

                case 'e':
                break;

                default:
                cout<<"\n Enter correct chioce.";
                break;
            }
            if(y == 'e')
            break;
        }
        break;

        case 8:
        break; 
        
        default:
        cout<<"\n Enter correct chioce.";
        break;
        }

    }while(ch<8);
    
    return 0;
}
