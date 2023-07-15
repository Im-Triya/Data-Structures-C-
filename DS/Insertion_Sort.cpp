#include<iostream>
using namespace std;

void Insertion_Sort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int current=a[i];
        int j=i-1;
        while(a[j]>current && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=current;
    }
}

int main()
{
    int a[]={88,105,62,58,75,92};
    Insertion_Sort(a,6);
    for(int i=0;i<6;i++)
    cout<<a[i]<<"\t";
}