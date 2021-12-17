#include<iostream>
using namespace std;

int* connect(int *&p1,int *&p2,int a,int b)
{
    int *p3 = new int[10];
    for(int i = 0;i < a;i++)
    {
        p3[i] = p1[i];
    }
    for(int j = a+b-1;j>=b;j--)
    {
        p3[j] = p2[j];
    }
    return p3;
    //delete []p3;
}
 
int main(void)
{
    int *m,n1,n2;
    int k = 0;//计数
    cout << "Please input the number of first array: ";
    cin >> n1;
    cout << "Please input the number of second array: ";
    cin >> n2;
    int *p = new int[n1]; //动态数组
    int *q = new int[n2]; //动态数组

    for(int i = 0;i<n1;i++) //初始化两个数组
    {
        int num1;
        cout << "enter the " << i+1 << " element for the first array: "; 
        cin >> num1;
        p[i] = num1;
    }
    for(int j = n1;j<(n1+n2);j++)
    {
        int num2;
        cout << "enter the " << k+1 << " element for the second array: ";
        cin >> num2;
        q[j] = num2;
        k+=1;
    }

    m = connect(p,q,n1,n2);
    cout << "new array:";
    for(int k = 0;k<n1+n2;k++)
    {
        cout << m[k] << " ";
    }
    //delete []p;
    //delete []q;//动态数组需要利用完回收空间，否则会导致栈溢出

    return 0;
}