class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>m;
        int n = s.size();
        int left = 0;
        int maxi = 0;
        int i=0;
        int maxFreq=0;
        for(int right=0;right<n;right++){
            m[s[right]]++;
            maxFreq = max(maxFreq, m[s[right]]);
            if((right-left+1 - maxFreq)>k){
                m[s[left]]--;
                left++;
                i++;
            }
            maxi = max(maxi,right-left+1);
        }
        return maxi;
    }
};