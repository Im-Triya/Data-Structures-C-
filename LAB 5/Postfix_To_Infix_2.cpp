#include<iostream>
#include<stack>
using namespace std;

string Postfix_to_Infix(string s)
{
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

            str=" (" + op1 + s[i] + op2 + ") ";
            st.push(str);
        }
    }
    return st.top();
}
int main()
{
    cout<<Postfix_to_Infix("ab+")<<endl;
}
