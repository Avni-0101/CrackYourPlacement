class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            int diff = target-nums[i];
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j && nums[j]==diff)
                {
                    return {i,j};
                }
            }
        }
        return {};
    }
};