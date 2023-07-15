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

string Change_Brackets(string s)
{
    string retval="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        retval+=')';

        else if(s[i]==')')
        retval+='(';

        else
        retval+=s[i];
    }
    return retval;
}
int prec(char c)
{
    if(c=='^')
    return 3;

    else if(c=='*' || c=='/')
    return 2;

    else if(c=='+' || c=='-')
    return 1;

    else 
    return -1;
}

string Infix_to_Prefix(string str)
{
    string s=Reverse(str);
    s=Change_Brackets(s);
    stack<char> st;
    string res;

    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
        res+=s[i];

        else if(s[i]=='(')
        st.push(s[i]);

        else if(s[i]==')')
        {
            while((!st.empty()) && (st.top()!='('))
            {
                res+=st.top();
                st.pop();
            }
            
            if(!st.empty())
            {
                st.pop();
            }
        }

        else
        {
            while((!st.empty()) && (prec(st.top())>prec(s[i])))
            {
                res+=st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }

    res=Reverse(res);
    return res;
}

int main()
{
    cout<<Infix_to_Prefix("(a-b/c)*(a/k-l)")<<endl;
}