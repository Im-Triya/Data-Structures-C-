#include<iostream>
using namespace std;
void Binary_Search(int a[], int n, int key)
{
    int l=0,h=n-1,m;
    while(l<=h)
    {
        m=(l+h)/2;
        if(a[m]==key)
        {
            cout<<"Key found at: "<<m<<endl;
            return;
        }
        else if(a[m]<key)
        {
            l=m+1;
        }
        else
        {
            h=m-1;
        }
    }
    cout<<"Key not found"<<endl;
}

int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    Binary_Search(a,9,0);
}