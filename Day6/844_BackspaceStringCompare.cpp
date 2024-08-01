class Solution {
public:
    string operation(stack<char> s)
    {
        string str;
        int backspace=0;
            
        while(!s.empty())
        {    
            if(s.top()=='#')
            {
                backspace++;
                s.pop();
            }
            else
            {
                if(backspace)
                {
                    s.pop();
                    backspace--;
                }
                else
                {
                    str.push_back(s.top());
                    s.pop();
                }
            }
        }
        return str;
    }

    bool backspaceCompare(string s, string t) {
        stack<char> ss,tt;

        for(char &it:s)
        {
            ss.push(it);
        }

        for(char &it:t)
        {
            tt.push(it);
        }

        string newS = operation(ss);
        string newT = operation(tt);

        return newS==newT;
    }
};