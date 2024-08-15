class Solution {
public:
    void count(vector<vector<int>>& board,int &live,int i,int j,int n,int m)
    {
        if(i!=0 && j!=0)    live += board[i-1][j-1];
        if(i!=0)    live += board[i-1][j];
        if(i!=0 && j!=m-1)    live += board[i-1][j+1];

        if(j!=0)    live += board[i][j-1];
        if(j!=m-1)    live += board[i][j+1];

        if(i!=n-1 && j!=0)    live += board[i+1][j-1];
        if(i!=n-1)    live += board[i+1][j];
        if(i!=n-1 && j!=m-1)    live += board[i+1][j+1];
    }

    void gameOfLife(vector<vector<int>>& b) {
        vector<vector<int>> board=b;
        int n=board.size();
        int m=board[0].size();
    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int live=0;
                count(b,live,i,j,n,m);
                if(b[i][j]==1)
                {
                    if(live < 2 || live > 3)
                    {
                        board[i][j]=0;
                    }
                }
                else
                {
                    if(live==3)
                    {
                        board[i][j]=1;
                    }
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                b[i][j]=board[i][j];
            }
        }
    }
};