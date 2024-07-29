class Solution {
public:
    string convertToTitle(int columnNumber) {
        int col = columnNumber;
        
        string title = "";

        while(col>0)
        {
            col--;
            int alphabet = col%26;
            col = col/26;
            char c = 'A' + alphabet;
            title = c + title;
        }

        return title;
    }
};