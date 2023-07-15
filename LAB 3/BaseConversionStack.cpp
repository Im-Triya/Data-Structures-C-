#include<iostream>
using namespace std;
#define max_size 10
class stack
{
    int S[max_size];
    int top;
public:
    stack()
    {
        top=-1;
    }
    bool isEmpty()
    {
        bool retval=false;
        if(top==-1)
            retval=true;
        return retval;
    }
    bool isFull()
    {
        bool retval=false;
        if(top==max_size)
            retval==true;
        return retval;
    }
    void Push(int element)
    {
        if(isFull())
            cout<<"Stack Overflow!!"<<endl;
        else
            S[++top]=element;
    }
    int Pop()
    {
        int retval=-1;
        if(isEmpty())
            cout<<"Stack is Empty!!"<<endl;
        else
        {
            retval=S[top];
            top--;
        }
        return retval;
    }
    void Display()
    {
        cout<<"Displaying the elements of the stack"<<endl;
        for(int i=top;i>=0;i--)
        cout<<S[i]<<endl;
    }
};
int main()
{
    stack s;
    int N;
    cout<<"Enter the decimal number: ";
    cin>>N;

    int x;
    cout<<"Enter the base to which it is to be converted: ";
    cin>>x;

    while(N>0)
    {
        s.Push(N%x);
        N/=x;
    }
    s.Display();
}