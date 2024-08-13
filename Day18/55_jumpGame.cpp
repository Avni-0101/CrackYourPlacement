class Solution {
public:
    bool check(vector<int>& nums, int ind, vector<int> &memo)
    {
        if(ind>=nums.size()-1) return true;
        
        if(memo[ind] != -1) return memo[ind];

        int jump = nums[ind];
        if(jump==0) return memo[ind] = 0;

        for(int i=1;i<=jump;i++)
        {
            if(check(nums,ind+i,memo))    return memo[ind] = 1;
        }
        return memo[ind] = 0;
    }
    bool canJump(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return check(nums,0,memo);
    }
};