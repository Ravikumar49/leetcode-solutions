class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp = grid;
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                if(r == 0 && c == 0) continue;
                if(r == 0) dp[r][c] = grid[r][c] + dp[r][c-1];
                else if(c == 0) dp[r][c] = grid[r][c] + dp[r-1][c];
                else dp[r][c] = grid[r][c] + min(dp[r-1][c], dp[r][c-1]);
            }
        }
        return dp[m-1][n-1];
    }
};