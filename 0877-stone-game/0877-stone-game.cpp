class Solution {
public:
    int solve(int left, int right, vector<int>& piles, vector<vector<int>>& dp) {
        if(left == right) return piles[left];
        if(dp[left][right] != INT_MIN) return dp[left][right];
        int takeLeft = piles[left] - solve(left+1, right, piles, dp);
        int takeRight = piles[right] - solve(left, right-1, piles, dp);
        return dp[left][right] = max(takeLeft, takeRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return solve(0, piles.size()-1, piles, dp) > 0;
    }
};