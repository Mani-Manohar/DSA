#include <iostream>
#include <cmath>
using namespace std;

class Element
{
public:
    int coef;
    int exp;
};

class Poly
{
private:
    int n;
    Element *ele;

public:
    Poly()
    {

    }
    Poly(int n)
    {
        this->n = n;
        ele = new Element[n];
    }
    friend istream &operator>>(istream &in, Poly &p);//? Operator Overloading must be done using friend fn. only
    friend ostream &operator<<(ostream &out, Poly &p);
    int result(int x, Poly &p);
    Poly operator+(Poly &p);
};

istream &operator>>(istream &in, Poly &p)
{

    cout <<"\nEnter the no. of terms in polynomial:- ";
    in >> p.n;

    p.ele = new Element[p.n];

    cout << "Enter coeff & exponent:- \n";
    for (int i = 0; i < p.n; i++)
    {
        in >> p.ele[i].coef >> p.ele[i].exp;
    }

    return in;
}

ostream &operator<<(ostream &out, Poly &p)
{
    int i, x;

    for (i = 0; i < p.n; i++)
    {
        if (p.ele[i].exp == 0)
            out << p.ele[i].coef;
        else
            out << p.ele[i].coef << "x^" << p.ele[i].exp;

        if (i < p.n - 1)
            out << " + ";
    }
    out << "\nEnter x:- ";
    cin >> x;
    out << "\nResult:- " << p.result(x, p);
    return out;
}

int Poly ::result(int x, Poly &p)
{
    int sum = 0;
    for (int i = 0; i < p.n; i++)
    {
        sum = sum + p.ele[i].coef*(pow(x, p.ele[i].exp));
    }
    return sum;
}

Poly Poly :: operator+(Poly &p)
{
    int k=0,i=0,j=0;
    Poly *sum = new Poly(n+p.n);
    while(i<n && j<p.n)
    {
        if(ele[i].exp == p.ele[j].exp)
        {
            sum->ele[k].coef = ele[i].coef + p.ele[j].coef;
            sum->ele[k++].exp = ele[i++].exp;
            j++;
        }

        else if(ele[i].exp < p.ele[j].exp)
        {
            //sum->ele[k] = p.ele[j];
            sum->ele[k++] = p.ele[j++];
        }

        else
        {
            //sum->ele[k] = ele[i];
            sum->ele[k++] = ele[i++];
        }
    }
    for(; j<p.n; j++) 
    {
        sum->ele[k] = p.ele[j];
        sum->ele[k++] = p.ele[j++];
    }
    for(; i<n; i++) 
    {
        sum->ele[k] = ele[i];
        sum->ele[k++] = ele[i++];
    }
    sum->n = k;
    return *sum;
}

int main()
{
    Poly p1, p2;

    cin >> p1; //? This will call:- istream &operator>>(istream &in, Poly &p)
    cout <<"Polynomial 1:- "<< p1<<endl; //? This will call:- ostream &operator<<(ostream &out, Poly &p) Poly &p)

    cin >> p2;
    cout << "Polynomial 2:- "<< p2<<endl;

    Poly sum = p1 + p2; //? This will call:- Poly Poly :: operator+(Poly &p)

    cout<<"\np1+p2 = "<<sum<<endl; //? This will call:- ostream &operator<<(ostream &out, Poly &p) Poly &p)
    
    return 0;
}
