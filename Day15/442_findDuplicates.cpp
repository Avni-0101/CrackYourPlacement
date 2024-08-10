class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1,0);
        vector<int> ans;

        for(int i=0;i<n;i++)
        {
            freq[nums[i]]++;
        }

        for(int i=0;i<n+1;i++)
        {
            if(freq[i]>1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

/////////////////////////////////////// METHOD 2 ///////////////////////////////////
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int j = abs(nums[i]);

            if(nums[j-1]<0)
                ans.push_back(j);
            nums[j-1] = - nums[j-1];
        }
        return ans;
    }
};