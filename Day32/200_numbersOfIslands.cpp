class Solution {
public:
    bool count(vector<vector<char>>& grid, vector<vector<int>> &visited,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();

        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]=='0' || visited[i][j] == 1)  
            return false;

        visited[i][j]=1;

        count(grid,visited,i+1,j);
        count(grid,visited,i-1,j);
        count(grid,visited,i,j-1);
        count(grid,visited,i,j+1);

        return true;
    } 

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int islands=0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 && grid[i][j] == '1')
                {
                    if(count(grid,visited,i,j))
                        islands++;
                }
            }
        }
        return islands;
    }
};