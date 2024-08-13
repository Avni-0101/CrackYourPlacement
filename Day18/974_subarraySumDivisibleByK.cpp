class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0,sum=0;
        unordered_map<int,int> modCount;
        modCount[0] = 1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];

            int mod = sum % k;

            if(mod<0)   mod += k;

            if(modCount.find(mod) != modCount.end()) 
            {
                count += modCount[mod];
            }
            modCount[mod]++;
        }

        return count;
    }
};