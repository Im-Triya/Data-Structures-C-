#include<iostream>
using namespace std;
void Selection_Sort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            swap(a[i], a[j]);
        }
    }
}

int main()
{
    int a[]={88,105,62,58,75,92};
    Selection_Sort(a,6);
    for(int i=0;i<6;i++)
    cout<<a[i]<<"\t";
}