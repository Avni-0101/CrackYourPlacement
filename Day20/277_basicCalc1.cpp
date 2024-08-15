class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char oper = '+';
        int num = 0;

        s+='#';
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')   continue;
            else if(isdigit(s[i]))
            {
                num = num*10 + (s[i]-'0');
            }
            else
            {
                if(oper == '+') st.push(num);
                else if(oper == '-') st.push(-num);
                else if(oper == '*')
                {
                    int prev = st.top();
                    st.pop();
                    st.push(prev*num);
                }
                else if(oper == '/')
                {
                    int prev = st.top();
                    st.pop();
                    st.push(prev/num);
                }

                num = 0; oper = s[i];
            }
        }

        int ans = 0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }

        return ans;
    }
};