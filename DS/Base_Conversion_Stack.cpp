#include<iostream>
using namespace std;
class Stack
{
    public:
    int *arr;
    int top;
    int n;

    Stack(int N)
    {
        arr=new int[N];
        top=-1;
        n=N;
    }

    bool isFull()
    {
        return (top==n-1);
    }

    bool isEmpty()
    {
        return (top==-1);
    }

    void push(int x)
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }

        arr[++top]=x;
    }

    int Top()
    {
        if(isEmpty())
        {
            cout<<"Stack Empty"<<endl;
            return -1;
        }

        return arr[top];
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Nothing to pop"<<endl;
            return;
        }

        top--;
        return;
    }

    void Display()
    {
        for(int i=0;i<=top;i++)
        cout<<arr[i]<<"\t";
        cout<<endl;
    }
};

int main()
{
    int n,b;
    cout<<"Enter Decimal number: ";
    cin>>n;
    cout<<"Enter Base: ";
    cin>>b;

    Stack S(10);
    while(n>0)
    {
        int d=n%b;
        n/=b;
        S.push(d);
    }
    while(!S.isEmpty())
    {
        cout<<S.Top();
        S.pop();
    }
}