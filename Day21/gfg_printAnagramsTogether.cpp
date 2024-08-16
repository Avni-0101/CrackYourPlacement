vector<vector<string> > Anagrams(vector<string>& string_list) {
        vector<vector<string>> ans;
        map<string,vector<string>> grp;
        
        for(auto str:string_list)
        {
            vector<int> count(26,0);
            for(auto c:str)
            {
                count[c-'a']++;
            }
            
            string key="";
            for(int i:count)
            {
                key+= to_string(i) + '#';
            }
            
            grp[key].push_back(str);
        }
        
        for(auto it:grp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }