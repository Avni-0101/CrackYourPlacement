class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<int>> group;

        for(int i=0;i<strs.size();i++)
        {
            string sorted = strs[i];
            sort(sorted.begin(),sorted.end());
            group[sorted].push_back(i);
        }

        for(auto it:group){
            vector<string> temp;
            for(auto iter:it.second)
            {
                temp.push_back(strs[iter]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};