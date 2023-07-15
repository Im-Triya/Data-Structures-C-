#include<iostream>
using namespace std;

int Partition(int arr[], int l, int r)
{
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}


void Quick_Sort(int arr[], int l, int r)
{
    if(l<r)
    {
        int pi=Partition(arr,l,r);
        Quick_Sort(arr, l,(pi-1));
        Quick_Sort(arr,(pi+1),r);
    }
}

int main()
{
    int arr[7]={6,3,9,5,2,8,7};
    Quick_Sort(arr,0,6);
    cout<<"Printing: "<<endl;
    for(int i=0;i<7;i++)
    cout<<arr[i]<<"\t";
}