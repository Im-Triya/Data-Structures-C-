#include<iostream>
using namespace std;
#define max_size 100
class stack
{
    char S[max_size];
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
    void Push(char element)
    {
        if(isFull())
            cout<<"Stack Overflow!!"<<endl;
        else
            S[++top]=element;
    }
    char Pop()
    {
        char retval='#';
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
    cout<<"Enter the string to be checked for palindrome: ";
    char input[100];
    cin>>input;
    int N;
    for(N=0;input[N]!='\0';N++);
    //cout<<N;
    char reverse[N];

    int i;

    for(i=0;input[i]!='\0';i++)
    s.Push(input[i]);

    i=0;
    while(!s.isEmpty())
    reverse[i++]=s.Pop();

    reverse[i]='\0';
    //cout<<reverse<<endl;

    bool flag=true;

    for(int j=0;j<N;j++)
    {
        cout<<input[j]<<"\t"<<reverse[j]<<endl;
        if(input[j]!=reverse[j])
        flag=false;
    }

    if(flag==true)
    cout<<"Palindrome";

    else 
    cout<<"not Palindrome";

    
   
}