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
int prefix_Expression_Evaluation(string s)
{
    stack<int> st;
    
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]<='9' && s[i]>='0')
        {
            st.push(s[i]-'0');
        }
        
        else
        {
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            int x=Evaluate(op1,op2,s[i]);
            st.push(x);
        }
    }
    return st.top();
}

int main()
{
    cout<<prefix_Expression_Evaluation("-+7*45+20")<<endl;
}