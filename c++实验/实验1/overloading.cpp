#include <iostream>
using namespace std;
double max(double a,double b);
double max(double a,double  b,double c);

int main(void)
{
    double x ,y;
    x = max(3,4.3);
    y = max(42,44.4,56);
    cout << "Two parameters Max: " << x <<endl;
    cout << "Three parameters Max: " << y <<endl;
}

double max(double a,double b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
double max(double a,double b,double c)
{
    if(a>b && a>c)
    {
        return a;
    }
    if(b>a>c)
    {
        return b;
    }
    else
    {
        return c;
    }
}