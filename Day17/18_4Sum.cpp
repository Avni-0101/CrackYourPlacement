class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        if(nums.size()<4)   return ans;

        for(int i=0;i<nums.size()-3;i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j=i+1;j<nums.size()-2;j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int k=j+1,l=nums.size()-1;
                while(k<l)
                {
                    long long sum = nums[i]+nums[j];
                    sum += nums[k]+nums[l];
                    if(sum==target)
                    {
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while (k < l && nums[k] == nums[k + 1]) k++;
                        while (k < l && nums[l] == nums[l - 1]) l--;
                        k++;l--;
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};