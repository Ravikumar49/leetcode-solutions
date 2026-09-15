class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        for(int i=0;i<n;i++) dp[i][i] = 1;
        for(int i=1;i<n;i++) {
            if(s[i] == s[i-1]) {
                dp[i-1][i] = 2;
            }
        }
        for(int len=3;len<=n;len++) {
            for(int left=0;left+len-1<n;left++) {
                int right = left+len-1;
                if(s[left] == s[right]) dp[left][right] = dp[left+1][right-1] + 2;
                else {
                    dp[left][right] = max(dp[left+1][right], dp[left][right-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};