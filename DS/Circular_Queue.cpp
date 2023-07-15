#include<iostream>
using namespace std;

class C_Queue
{
    public:
    int *arr;
    int f, r,n;

    C_Queue(int N)
    {
        arr=new int [N];
        f=r=-1;
        n=N;
    }

    int size()
    {
        int size=((n-f+r)%n);
        return size;
    }

    bool isFull()
    {
        int s=size();
        return (s==(n-1));
    }

    bool isEmpty()
    {
        return (r==f);
    }

    void Insert(int x)
    {
        if(isFull())
        {
            cout<<"Queue Full"<<endl;
            return;
        }

        int pos=(r+1)%n;
        arr[pos]=x;
        r++;
    }

    int Delete()
    {
        if(isEmpty())
        {
            cout<<"Empty Queue";
            return -1;
        }

        int pos=(f+1)%n;
        f++;
        return arr[pos];
    }

    void Display()
    {
        int s=size();
        for(int i=f+1;i<=r;i++)
        cout<<arr[i]<<"\t";
        cout<<endl;
    }
};

int main()
{
    C_Queue CQ(5);
    cout<<CQ.isEmpty()<<endl;
    CQ.Insert(1);
    CQ.Insert(2);
    CQ.Insert(3);
    CQ.Insert(4);
    CQ.Insert(5);
    CQ.Display();
    cout<<CQ.Delete()<<endl;
    CQ.Display();
    cout<<CQ.Delete()<<endl;
    CQ.Display();

}