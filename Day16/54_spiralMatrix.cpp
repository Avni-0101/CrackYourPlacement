class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int first_row = 0, first_col = 0;
        int last_row = matrix.size()-1, last_col = matrix[0].size()-1;
                
        while(first_row <= last_row && first_col <= last_col)
        {
            for(int i=first_col;i<=last_col;i++)         //first row traverse
            {
                ans.push_back(matrix[first_row][i]); 
            }
            first_row++;

            for(int i=first_row;i<=last_row;i++)            // last col traverse
            {
                ans.push_back(matrix[i][last_col]);
            }
            last_col--;

            if(first_row<=last_row)
            {
                for(int i=last_col;i>=first_col;i--)        // last row traverse
                {
                    ans.push_back(matrix[last_row][i]);
                }
                last_row--;
            }
            
            
            if(first_col<=last_col)
            {
                for(int i=last_row;i>=first_row;i--)        //first col traverse
                {
                    ans.push_back(matrix[i][first_col]);
                }            
                first_col++;
            }
            
        }

        return ans;
    }
};