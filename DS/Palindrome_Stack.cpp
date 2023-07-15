#include<iostream>
#include<cstring>
using namespace std;
class Stack
{
    public:
    char *arr;
    int top;
    int n;

    Stack(int N)
    {
        arr=new char[N];
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

    void push(char x)
    {
        if(isFull())
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }

        arr[++top]=x;
    }

    char Top()
    {
        if(isEmpty())
        {
            cout<<"Stack Empty"<<endl;
            return '#';
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
    string input, rev;
    cout<<"Enter Word: ";
    cin>>input;

    int l=input.length();
    Stack S(l);

    for(int i=0;i<l;i++)
    {
        char c=input[i];
        S.push(c);
    }

    for(int i=0;i<l;i++)
    {
        rev+=S.Top();
        S.pop();
    }

    if(input==rev)
    {
        cout<<"Palindrome"<<endl;
    }

    else
    cout<<"Not Palindrome"<<endl;
}