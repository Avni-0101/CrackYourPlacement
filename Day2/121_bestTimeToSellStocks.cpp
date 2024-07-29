class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit = 0;
        vector<int> minPrices(n,0);
        minPrices[0]=prices[0];

        for(int i=1;i<n;i++)
        {
            minPrices[i] = min(minPrices[i-1],prices[i]);
        }

        for(int i=0;i<n;i++)
        {
            maxProfit = max(maxProfit, prices[i]-minPrices[i]);
        }
        
        return maxProfit;
    }
};