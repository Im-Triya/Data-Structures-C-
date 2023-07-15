#include<iostream>
#include<stack>
using namespace std;

string Reverse(string s)
{
    string res;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='(')
        res+=')';

        else if(s[i]==')')
        res+='(';

        else
        res+=s[i];
    }

    return res;
}

void Prefix_to_Infix(string s)
{
    stack<string> st;
    s=Reverse(s);
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

    string ans=Reverse(st.top());

    cout<<"ANSWER: "<<ans<<endl;
}

int main()
{
    Prefix_to_Infix("/*a+bcd");
}