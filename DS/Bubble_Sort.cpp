#include<iostream>
using namespace std;
void Bubble_Sort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }
    }
}

int main()
{
    int a[]={88,105,62,58,75,92};
    Bubble_Sort(a,6);
    for(int i=0;i<6;i++)
    cout<<a[i]<<"\t";
}