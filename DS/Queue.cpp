#include<iostream>
using namespace std;
class Queue
{
    public:
    int *arr;
    int f, r,n;

    Queue(int N)
    {
        arr=new int[N];
        n=N;
        f=-1;
        r=-1;
    }

    bool isFull()
    {
        return (r==(n-1));
    }

    bool isEmpty()
    {
        return (f==-1 || f>r);
    }

    void push(int x)
    {
        if(isFull())
        {
            cout<<"Queue Full"<<endl;
            return;
        }
        
        if(f==-1)
        f++;

        r++;
        arr[r]=x;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Nothing to pop"<<endl;
            return;
        }

        f++;
    }

    int front()
    {
        if(isEmpty())
        {
            cout<<"Queue Empty"<<endl;
            return -1;
        }

        return arr[f];
    }

    void Display()
    {
        for(int i=f;i<=r;i++)
        cout<<arr[i]<<"\t";
        
        cout<<endl;
    }
};

int main()
{
    Queue Q(5);
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);

    Q.Display();
    cout<<Q.front()<<endl;
    Q.pop();
    Q.pop();
    Q.Display();
}