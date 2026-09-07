class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> last(n, -1);
        vector<int> pos(26, -1);
        for(int i=0;i<n;i++) {
            last[i] = pos[s[i] - 'a'];
            pos[s[i] - 'a'] = i;
        }
        const long long MOD = 1000000007;
        vector<int> dp(n+1, 1);
        for(int i=1;i<=n;i++) {
            if(last[i-1] == -1) dp[i] = (2LL * dp[i-1]) % MOD;
            else {
                int j = last[i-1];
                dp[i] = ((2LL * dp[i-1]) % MOD - dp[j] + MOD) % MOD;
            }
        }
        return (dp[n] - 1 + MOD) % MOD;
    }
};