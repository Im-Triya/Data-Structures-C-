#include<iostream>
#include<stack>
using namespace std;

int prec(char c)
{
    if(c=='^')
    return 3;

    else if(c=='/' || c=='*')
    return 2;

    else if(c=='+' || c=='-')
    return 1;

    else
    return -1;

}

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

void Infix_to_Prefix(string s)
{
    stack<char> st;
    string res;

    s=Reverse(s);

    for(int i=0;i<s.length();i++)
    {
        char c=s[i];
        cout<<c<<endl;
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        res+=c;

        else if(c=='(')
        st.push(c);

        else if(c==')')
        {
            while((st.top())!='(' && (!st.empty()))
            {
                res+=st.top();
                st.pop();
            }

            if(!st.empty())
            st.pop();
        }

        else
        {
            while( ( !st.empty() ) && ( prec(st.top()) > prec(c) ) )
            {
                res+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }

    res=Reverse(res);

    cout<<"\nANSWER: "<<res<<endl;
}

int main()
{
    Infix_to_Prefix("a*(b+c)/d");
}