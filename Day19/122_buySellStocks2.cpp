class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> diff;
        int profit=0;

        for(int i=0;i<prices.size()-1;i++)
        {
            diff.push_back(prices[i+1]-prices[i]);
        }
        for(int i:diff)
        {
            if(i>0) profit+=i;
        }
        return profit;
    }
};

////////////////////////    method 2    //////////////////

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;

        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]>prices[i])
            {
                profit+= prices[i+1]-prices[i];
            }
        }
        return profit;
    }
};