#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<bool>> &vis, vector<vector<char>> &grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        if(i<0 || j<0 || i>=n || j>=m)  return ;
        if(vis[i][j] || grid[i][j]=='0')   return;
        
        vis[i][j]=1;
        
        dfs(vis,grid,i-1,j-1);
        dfs(vis,grid,i,j-1);
        dfs(vis,grid,i+1,j-1);
        dfs(vis,grid,i-1,j);
        dfs(vis,grid,i+1,j);
        dfs(vis,grid,i-1,j+1);
        dfs(vis,grid,i,j+1);
        dfs(vis,grid,i+1,j+1);
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    dfs(vis,grid,i,j);
                    count++;
                }
            }
        }
        
        return count;
    }