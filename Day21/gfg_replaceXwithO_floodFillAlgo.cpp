#include<bits/stdc++.h>
using namespace std;

    void dfs(int i,int j,int n,int m, vector<vector<char>> &mat)
    {
        if(i<0 || j<0 || i>=n ||j>=m || mat[i][j] != '-')   return;
        
        mat[i][j]='O';
        
        dfs(i-1,j,n,m,mat);
        dfs(i+1,j,n,m,mat);
        dfs(i,j+1,n,m,mat);
        dfs(i,j-1,n,m,mat);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='O')
                {
                    mat[i][j]='-';
                }
            }
        }   
        
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]=='-')
                dfs(i,0,n,m,mat);
            if(mat[i][m-1]=='-')
                dfs(i,m-1,n,m,mat);
        }
        for(int j=0;j<m;j++)
        {
            if(mat[0][j]=='-')
                dfs(0,j,n,m,mat);
            if(mat[n-1][j]=='-')
                dfs(n-1,j,n,m,mat);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='-')
                {
                    mat[i][j]='X';
                }
            }
        }   
        
        return mat;
    }