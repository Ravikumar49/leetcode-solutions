class Solution {
public:
    int solve(int i, vector<int>& stoneValue, vector<int>& dp) {
        int n = stoneValue.size();
        if(i >= n) return 0;
        if(dp[i] != -1) {
            return dp[i];
        }
        int take = 0;
        int ans = INT_MIN;
        for(int j=i;j<min(n, i+3);j++) {
            take += stoneValue[j];
            ans = max(ans, take - solve(j+1, stoneValue, dp));
        }
        return dp[i] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, -1);
        int diff = solve(0, stoneValue, dp);
        if(diff < 0) return "Bob";
        if(diff > 0) return "Alice";
        return "Tie";
    }
};