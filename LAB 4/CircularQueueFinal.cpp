#include<iostream>
using namespace std;
#define max_size 100
class CQueue
{
public:
    int *CQ;
    int r,f,N;
public:
    CQueue(int n)
    {
        N=n;
        CQ=new int(N);
        f=r=-1;
    }

    bool isEmpty()
    {
        bool retval=false;
        if(r==f)
            retval=true;
        return retval;
    }

    bool isFull()
    {
        bool retval=false;
        if((N-f+r)%N==(N-1))
            retval=true;
        return retval;
    }
    void Insert(int element)
    {
        if(!isFull())
        {
            r=(r+1)%N;
            CQ[r]=element;
        }
    }

    int Delete()
    {
        int retval=-1;
        if(!isEmpty())
        {
            f=(f+1)%N;
            retval=CQ[f];
        }
        return retval;
    }

    void Display()
    {

        for(int i=f+1;i<=r;i=(i+1)%N)
            cout<<CQ[i]<<"\t";
        cout<<endl;
    }
};
int main()
{
    int n;
    cout<<"Enter the number of elements in the Circular Queue:";
    cin>>n;
    CQueue CQ(n);
    int a[n];
    cout<<"Enter the elements of the Circular Queue: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        CQ.Insert(a[i]);

    }
    cout<<"Printing the elements of the Circular Queue:"<<endl;
    CQ.Display();
    cout<<"Deleting an elements of the Circular Queue:"<<endl;
    CQ.Delete();
    CQ.Display();
}
