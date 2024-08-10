class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeros;

        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    zeros.push_back({i,j});
                }
            }
        }

        for(auto i:zeros)
        {
            int row = i.first, col = i.second;

            for(int k=0;k<matrix.size();k++)        //all rows
            {
                matrix[k][col]=0;
            }
            
            for(int k=0;k<matrix[0].size();k++)        //all cols
            {
                matrix[row][k]=0;
            }
        }
    }
};