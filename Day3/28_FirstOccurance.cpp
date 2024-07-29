class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0,k=0;

        if(haystack==needle)    return 0;

        while(i<haystack.size())
        {
            if(k==needle.size())
            {
                return i;
            }
            if(haystack[j]==needle[k])
            {
                j++; k++;
            }
            else
            {
                i++;
                j=i;
                k=0;
            }
        }
        return -1;
    }
};