class Solution {
public:
    int rec(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
        if (i >= grid.size() || j >= grid[0].size()) {
            return INT_MAX;
        }

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = rec(grid, i, j + 1, dp);
        int down = rec(grid, i + 1, j, dp);

        if (right == INT_MAX && down == INT_MAX) {
            dp[i][j] = grid[i][j];
        }
        else {
            dp[i][j] = grid[i][j] + min(right, down);
        }

        return dp[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return rec(grid, 0, 0, dp);
    }
};
