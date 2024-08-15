class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        path+='/';

        for(int i=0;i<path.size();i++)
        {            
            string temp="";
            while(i<path.size() && path[i]!='/')
            {
                temp += path[i];
                i++;
            }
            
            if(temp == "..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                if(temp!="." && temp!="")
                    st.push(temp);
            }
        }

        string ans;
        while(!st.empty())
        {
            ans = '/' + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};

///////////////////////////////////////////////////////         CHATGPT AMMENDED APPROACH         ///////////////////////////

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        path+='/';

        string temp = "";
        for(int i=0;i<path.size();i++)
        {            
            if (path[i] == '/') {
                if (temp == "..") 
                {
                    if (!st.empty()) 
                    {
                        st.pop();
                    }
                } 
                else if (!temp.empty() && temp != "." && temp != "..") {
                    st.push(temp);
                }
                temp = "";
            } 
            else 
            {
                temp += path[i];
            }
        }

        string ans;
        while(!st.empty())
        {
            ans = '/' + st.top() + ans;
            st.pop();
        }


        return ans.empty() ? "/" : ans;
    }
};