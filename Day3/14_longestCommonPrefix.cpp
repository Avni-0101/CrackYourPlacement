class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string common = "";
        for(int i=0;i<strs[0].size();i++)
        {
            if(strs[0][i]==strs.back()[i])
            {
                common.push_back(strs[0][i]);
            }
            else
            {
                break;
            }
        }
        return common;
    }
};