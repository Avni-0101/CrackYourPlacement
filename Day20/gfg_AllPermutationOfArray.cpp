class Solution {
  public:
    
    void permute(vector<int> &arr, int index, set<vector<int>>& s)
    {
        if(index == arr.size())
        {
            s.insert(arr);
            return;
        }
        
        for(int i=index;i<arr.size();i++)
        {
            swap(arr[i],arr[index]);
            permute(arr,index+1,s);
            swap(arr[i],arr[index]);
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> s;
        
        permute(arr,0,s);
        
        return vector<vector<int>>(s.begin(), s.end());
    }
};