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
            //cout<<"Stack Empty"<<endl;
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
    string exp;
    cout<<"Enter Expression: ";
    cin>>exp;
    int l=exp.length();
    Stack S(l);

    for(int i=0;i<l;i++)
    {
        char c=exp[i];
        char top=S.Top();
        if(c=='(' || c=='[' || c=='{')
        S.push(c);

        if(c==')' && top=='(')
        S.pop();

        if(c=='}' && top=='{')
        S.pop();

        if(c==']' && top=='[')
        S.pop();
    }

    if(S.isEmpty())
    {
        cout<<"Balanced Parenthesis"<<endl;
    }

    else
    cout<<"Unbalanced Parenthesis"<<endl;
}