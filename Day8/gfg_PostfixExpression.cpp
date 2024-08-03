#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        stack<int> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<= '9')
            {
                st.push(s[i]-'0');
            }
            else if(s[i] == '+')
            {
                int a,b;
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                
                st.push(a+b);
            }
            else if(s[i]=='-')
            {
                int a,b;
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                
                st.push(a-b);
            }
            else if(s[i]=='*')
            {
                int a,b;
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                
                st.push(a*b);
            }
            else if(s[i]=='/')
            {
                int a,b;
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                
                st.push(a/b);
            }
        }
        return st.top();
    }
};