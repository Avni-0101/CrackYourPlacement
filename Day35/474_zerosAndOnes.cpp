class Solution {
public:

    int solve(vector<vector<int>> &count, int m,int n,int ind,vector<vector<vector<int>>>&memo)
    {
        if(m<0 || n<0)  return -1;
        if(ind>=count.size())   return 0;

        if(memo[ind][m][n]!=-1)   return memo[ind][m][n];

        int notpick = solve(count,m,n,ind+1,memo);
        int pick = solve(count,m-count[ind][0],n-count[ind][1],ind+1,memo);
        if (pick != -1) 
        {
            pick += 1;
        }
        else
        {
            pick = 0;
        }
        return memo[ind][m][n] = max(pick,notpick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> count;
        for(int i=0;i<strs.size();i++)
        {
            int ones=0,zeros=0;
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='1')
                ones++;
                else
                zeros++;
            }
            count.push_back({zeros,ones});
        }

        vector<vector<vector<int>>>memo(count.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(count,m,n,0,memo);
    }
};