#include<iostream>
#include<stack>
using namespace std;

void Postfix_to_Infix(string s)
{
    stack<string> st;
    string op1,op2, add;
    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        if(c>='a' && c<='z')
        {
            add=c;
            st.push(add);
        }

        else
        {
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();
            add="( "+op1+c+op2+") ";
            st.push(add);
        }
    }

    cout<<"ANSWER: "<<st.top()<<endl;
}

int main()
{
    Postfix_to_Infix("abc+*d/");
}