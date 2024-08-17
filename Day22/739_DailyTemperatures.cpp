class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size(),0);
        stack<int> st;

        for(int i=0;i<temp.size();i++)
        {
            while(!st.empty() && temp[st.top()]<temp[i])
            {
                int index = st.top();
                st.pop();
                ans[index] = i-index;
            }

            st.push(i);
        }
        return ans;
    }
};