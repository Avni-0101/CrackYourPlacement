class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> freq(n,0);

        for(int i:nums)
        {
            freq[i]++;
        }
        for(int i=0;i<n;i++)
        {
            if(freq[i]>=2)    return i;
        }
        return -1;
    }
};