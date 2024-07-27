class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = nums[0];
        int index=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=curr)
            {
                if(index!=i)
                {
                    nums[index]=nums[i];
                }
                index++;
            }
            curr = nums[i];
        }
        return index;
    }
};