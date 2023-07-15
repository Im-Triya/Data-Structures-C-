#include<iostream>
#include<stack>
using namespace std;

string Reverse(string s)
{
    string retval="";
    for(int i=s.length()-1;i>=0;i--)
    {
        retval+=s[i];
    }

    return retval;
}

string Prefix_to_Infix(string s)
{
    s=Reverse(s);
    stack<string> st;
    string str;
    string op1,op2;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            string x;
            x=+s[i];
            st.push(x);
        }

        else
        {
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();

            str=" (" + op2 + s[i] + op1 + ") ";
            st.push(str);
        }
    }
    return st.top();
}
int main()
{
    cout<<Prefix_to_Infix("*c+ab")<<endl;
}