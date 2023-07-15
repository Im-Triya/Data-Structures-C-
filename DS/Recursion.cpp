#include<iostream>
using namespace std;

int Sum(int n)
{
    if(n==1)
    return n;

    else 
    return (Sum(n-1)+n);
}

int Factorial(int n)
{
    if(n<=1)
    return 1;

    else
    return (n*(Factorial(n-1)));
}

int Fibonacci(int n)
{
    if(n<=1)
    return n;

    else
    return (Fibonacci(n-1)+Fibonacci(n-2));
}

int Tribonacci(int n)
{
    if(n<=1)
    return n;

    else
    return (Tribonacci(n-1)+Tribonacci(n-2)+ Tribonacci(n-3));
}

int GCD(int m, int n)
{
    if(m==0 || n==0)
    return 0;

    else if(m==n)
    return m;

    else if(m>n)
    return (GCD(m-n,n));

    else
    return (GCD(n-m,m));
}

int Reverse(int num, int rev)
{
    if(num==0)
    return rev;

    else
    return (Reverse((num/10), ((rev*10)+(num%10))));
}

void Bubble_Sort(int a[], int n)
{
    if(n==1)
    return;

    else
    {
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            swap(a[j], a[j+1]);
        }
        Bubble_Sort(a, n-1);
    }
}
int main()
{
    cout<<"SUM: "<<Sum(5)<<endl;
    cout<<"FACTORIAL: "<<Factorial(5)<<endl;
    cout<<"FIBONACCI: "<<Fibonacci(5)<<endl;
    cout<<"TRIBONACCI: "<<Tribonacci(5)<<endl;
    cout<<"GCD: "<<GCD(24,42)<<endl;
    cout<<"REVERSE: "<<Reverse(123,0)<<endl;

    int a[]={88,105,62,58,75,92};
    Bubble_Sort(a,6);
    for(int i=0;i<6;i++)
    cout<<a[i]<<"\t";
}