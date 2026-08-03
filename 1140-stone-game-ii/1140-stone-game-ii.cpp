class Solution {
public:
    int solve(int i, int m, vector<int>& piles, vector<vector<int>>& dp) {
        int n = piles.size();
        if(i >= n) {
            return 0;
        }
        if(dp[i][m] != -1) {
            return dp[i][m];
        }
        int take = 0;
        int ans = INT_MIN;
        for(int x=1;x<= 2 * m && i + x - 1 < n;x++) {
            take += piles[i + x -1];
            ans = max(ans, take - solve(i+x, max(m, x), piles, dp));
        }
        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int m = 1;
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        int diff = solve(0, m, piles, dp);
        int total = accumulate(piles.begin(), piles.end(), 0);
        return (total + diff)/2;
    }
};