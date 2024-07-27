class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int boss = nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            int curr = nums[i];
            if(boss != curr)
            {
                if(count==0)
                {
                    boss=curr;
                }
                else
                {
                    count--;
                }
            }
            else
            {
                count++;
            }
        }
        return boss;
    }
};