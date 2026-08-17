class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0;i<n;i++) dp[i][i] = 0;
        vector<int> prefix(n);
        prefix[0] = stoneValue[0];
        for(int i=1;i<n;i++) {
            prefix[i] = stoneValue[i] + prefix[i-1];
        }
        for(int len=2;len<=n;len++) {
            for(int l=0;l+len<=n;l++) {
                int r = l + len - 1;
                for(int k=l;k<r;k++) {
                    int score;
                    int leftSum = prefix[k] - prefix[l] + stoneValue[l];
                    int rightSum = prefix[r] - prefix[k+1] + stoneValue[k+1];
                    if(leftSum < rightSum) score = leftSum + dp[l][k];
                    else if(leftSum > rightSum) score = rightSum + dp[k+1][r];
                    else score = leftSum + max(dp[l][k], dp[k+1][r]);
                    dp[l][r] = max(dp[l][r], score);
                }
            }
        }
        return dp[0][n-1];
    }
};