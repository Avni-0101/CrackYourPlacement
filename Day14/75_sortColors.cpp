class Solution {
public:
    void sortColors(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        int mid=0;
        while(mid<=end)
        {
            if(nums[mid]==0)
            {
                swap(nums[start], nums[mid]);
                start++; mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[end],nums[mid]);
                end--;
            }
            else
            {
                mid++;
            }
        }

        for(int i:nums)cout<<i<<" ";
    }
};