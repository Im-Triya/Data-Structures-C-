#include<iostream>
using namespace std;
class heap
{
    public:
    int arr[100];
    int size;

    heap()
    {
        arr[0]=-1;
        size=0;
    }
    void Insert(int x)
    {
        size++;
        int index=size;
        arr[index]=x;

        while(index>1)
        {
            int parent=index/2;
            if(arr[parent]<arr[index])
            {
                swap(arr[parent], arr[index]);
                index=parent;
            }

            else
            return;
        }
    }

    void Delete()
    {
        if(size==0)
        {
            cout<<"Nothing to delete."<<endl;
            return;
        }

        arr[1]=arr[size];
        size--;
        int i=1;
        while(i<size)
        {
            int left=(2*i);
            int right=left+1;

            if(left<size && arr[left]>arr[i])
            {
                swap(arr[left], arr[i]);
                i=left;
            }

            else if(right<size && arr[right]>arr[i])
            {
                swap(arr[right], arr[i]);
                i=right;
            }

            else 
            return;
        }
    }

    
    void Display()
    {
        for(int i=1;i<=size;i++)
        cout<<arr[i]<<"\t";
        cout<<endl;
    }

};

void Heapify(int arr[], int n, int i)
{
    int largest=i;
    int left=2*i;
    int right=left+1;

    if(left<=n && arr[largest]<arr[left])
    largest=left;
    
    if(right<=n && arr[largest]<arr[right])
    largest=right;

    if(largest!=i)
    {
        swap(arr[i], arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[1],arr[size]);
        size--;
        Heapify(arr, size, 1);
    }
}

int main()
{
    heap h;

    h.Insert(10);
    h.Insert(15);
    h.Insert(21);
    h.Insert(30);
    h.Insert(18);
    h.Insert(19);

    h.Display();
    h.Delete();
    h.Display();

    int arr[6]={-1, 54, 53, 55, 52, 50};

    int n=5;
    for(int i=n/2;i>0;i--)
    {
        Heapify(arr,n,i);
    }

    cout<<"printing: "<<endl;
    for(int i=1;i<=n;i++)
    cout<<arr[i]<<"\t";
    
    cout<<"\nprinting sorted: "<<endl;
    HeapSort(arr, n);
    for(int i=1;i<=n;i++)
    cout<<arr[i]<<"\t";
}