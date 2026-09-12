class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        const long long LIMIT = INT_MAX + 1LL;
        vector<long long> dp(n+1, 0);
        dp[0] = 1;
        for(int j=0;j<s.size();j++) {
            for(int i=t.size();i>=1;i--) {
                if(s[j] == t[i - 1]) {
                    if(dp[i - 1] > LIMIT - dp[i]) dp[i] = LIMIT;
                    else dp[i] += dp[i-1];
                }
            }
        }
        return dp[n];
    }
};