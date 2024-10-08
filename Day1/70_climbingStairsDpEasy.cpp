class Solution {
public:
    int count(int i,vector<int> &memo)
    {
        if(i<=1)return 1;
        if(memo[i] != -1)return memo[i];
        int one = count(i-1,memo);
        int two = count(i-2,memo);

        return memo[i] = one+two;
    }

    int climbStairs(int n) {
        vector<int> memo(n+1,-1);
        memo[0]=1;
        memo[1]=1;

        for(int i=2;i<=n;i++){
            memo[i]=memo[i-1]+memo[i-2];
        }
        return memo[n];
    }
};