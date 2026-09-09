class Solution {
public:
    int solve(vector<vector<int>>& dp, int r, int c, int m, int n) {
        if(r == m - 1 && c == n - 1) return 1;
        if(dp[r][c] != -1) return dp[r][c];
        int ways = 0;
        if(r+1 < m) ways += solve(dp, r+1, c, m, n);
        if(c+1 < n) ways += solve(dp, r, c+1, m, n);
        return dp[r][c] = ways;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(dp, 0, 0, m, n);
    }
};