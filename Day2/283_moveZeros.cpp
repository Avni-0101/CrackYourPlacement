class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count0=0;
        int index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {  
                count0++;
            }
            else
            {
                nums[index]=nums[i];
                index++;
            }
        }
        for(int i=nums.size()-count0;i<nums.size();i++)
        {
            nums[i]=0;
        }
    }
};