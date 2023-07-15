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

void Infix_to_Postfix(string s)
{
    stack<char> st;
    string res;

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
            while( ( !st.empty() ) && ( prec(st.top()) >= prec(c) ) )
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

    cout<<"\nANSWER: "<<res<<endl;
}

int main()
{
    Infix_to_Postfix("a*(b+c)/d");
}