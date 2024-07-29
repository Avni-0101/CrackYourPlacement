
class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        if(n==1)    return {1};
        vector<long long int> prefix(n,1);
        vector<long long int> suffix(n,1);
        vector<long long int> ans(n,1);      
        
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]*nums[i];
        }
        
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=suffix[i+1]*nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            if(i==0)    ans[i] = suffix[i+1];
            else if(i==n-1) ans[i] = prefix[i-1];
            else ans[i] = prefix[i-1] * suffix[i+1];
        }
        
        return ans;
    }
};