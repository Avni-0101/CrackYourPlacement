class Solution {
public:
    bool check(vector<vector<char>>& board,string word,int i,int j,int k)
    {
        if(k==word.size())  return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || k>=word.size())  return false;
        if(board[i][j] != word[k]) return false;
        
        char temp = board[i][j];
        board[i][j] = '#';

        bool found = check(board,word,i,j+1,k+1) || check(board,word,i+1,j,k+1) 
        || check(board,word,i,j-1,k+1) || check(board,word,i-1,j,k+1);
    
        board[i][j] = temp;

        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size(),k=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(check(board,word,i,j,k))
                {
                    return true;
                }
            }
        }
        return false;
    }
};