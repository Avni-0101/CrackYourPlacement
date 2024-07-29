class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n =nums.size()-1;
        sort(nums.begin(),nums.end());
        int posProd = nums[n]*nums[n-1]*nums[n-2];
        int negProd = nums[n]*nums[0]*nums[1];
        return max(posProd,negProd);
    }
};