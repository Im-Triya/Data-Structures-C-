#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int Evaluate(int op1, int op2, char c)
{
    int retval;
    switch(c)
            {
                case '+':
                {
                    retval=(op1+op2);
                    break;
                }

                case '-':
                {
                    retval=(op1-op2);
                    break;
                }

                case '*':
                {
                    retval=(op1*op2);
                    break;
                }

                case '/':
                {
                    retval=(op1/op2);
                    break;
                }

                case '%':
                {
                    retval=(op1%op2);
                    break;
                }

                case '^':
                {
                    retval=(pow(op1,op2));
                    break;
                }
            }
    return retval;
}

int postfix_Expression_Evaluation(string s)
{
    stack<int> st;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }

        else
        {
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();

            int x=Evaluate(op1,op2,s[i]);
            st.push(x);
        }
    }
    return st.top();
}

int main()
{
    cout<<postfix_Expression_Evaluation("46+2/5*7+");
}