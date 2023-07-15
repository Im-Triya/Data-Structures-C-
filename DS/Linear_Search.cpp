#include<iostream>
using namespace std;
void LinearSearch(int a[], int n, int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            cout<<"Key found at position: "<<i<<endl;
            break;
        }
    }
}
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9};
    LinearSearch(a,9,9);
}