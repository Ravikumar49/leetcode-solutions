class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;
        vector<int> dp(n);
        vector<int> prefixSum(n+1);
        for(int i=0;i<n;i++) {
            dp[i] = 1;
            prefixSum[i+1] = (prefixSum[i] + dp[i]) % MOD;
        }
        for(int i=1;i<=k;i++) {
            dp[0] = 0;
            for(int j=1;j<n;j++) {
                dp[j] = (dp[j-1] + prefixSum[j]) % MOD;
            }
            for(int j=0;j<n;j++) {
                prefixSum[j+1] = (prefixSum[j] + dp[j]) % MOD;
            }
        }
        return dp[n-1];
    }
};