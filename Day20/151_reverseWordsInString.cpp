class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        s+=' ';
        bool flag=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(flag && temp!="")
                {
                    ans = temp + " " + ans;
                    temp="";
                }                
                flag=0;
            }
            else
            {
                flag=1;
                temp+=s[i];
            }
        }
        ans.pop_back();
        return ans;
    }
};


//////////////////////////////////////            METHOD 2      /////////////////////////////////////

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string temp="";

        s+=' ';

        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(!temp.empty())
                words.push_back(temp);
                temp="";
            }
            else
            {
                temp+=s[i];
            }
        }

        string ans = "";
        for(int i=words.size()-1;i>=0;i--)
        {
            ans = ans + words[i];
            if(i!=0)    ans+=' ';
        }

        return ans;
    }
};