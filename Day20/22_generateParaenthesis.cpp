class Solution {
public:

    bool valid(string s)
    {
        stack<char> st;

        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
        }
        return st.empty();
    }

    void rec(int open,int close,string temp,vector<string> &ans)
    {
        if(open==0 && close==0)
        {
            if(valid(temp))                                 //IT MAY NOT BE REQUIRED IF U CHANGE CLOSE>OPEN
                ans.push_back(temp);
            return;
        }

        if(open>0) rec(open-1,close,temp+'(',ans);
        if(close>0)    rec(open,close-1,temp+')',ans);               
        //CLOSE>0 generates all the cases while CLOSE>OPEN generate only valid parenthesis!!!!

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp="";

        rec(n,n,temp,ans);

        return ans;
    }
};