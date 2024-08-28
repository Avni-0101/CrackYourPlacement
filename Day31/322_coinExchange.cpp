class Solution {
public:
    int solve(vector<int>& coins,int amount,vector<int>& dp)
    {
        if(amount<0)    return INT_MAX;
        if(amount==0)   return 0;

        if(dp[amount]!=-1)  return dp[amount];

        int minCoins = INT_MAX;
        for(int i=coins.size()-1;i>=0;i--)
        {
            int coin = solve(coins,amount-coins[i],dp);

            if(coin!=INT_MAX)
                minCoins = min(minCoins,coin+1);
        }

        return dp[amount] = minCoins;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int result = solve(coins,amount,dp);
        
        return result==INT_MAX?-1:result;
    }
};