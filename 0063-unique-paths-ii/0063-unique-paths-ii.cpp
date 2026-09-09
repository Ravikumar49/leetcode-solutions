class Solution {
public:
    int solve(int r, int c, int m, int n, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[r][c] == 1) return 0;
        if(r == m-1 && c == n-1) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        int ways = 0;
        if(r+1 < m) ways += solve(r+1, c, m, n, dp, obstacleGrid);
        if(c+1 < n) ways += solve(r, c+1, m, n, dp, obstacleGrid);
        return dp[r][c] = ways;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, dp, obstacleGrid);
    }
};