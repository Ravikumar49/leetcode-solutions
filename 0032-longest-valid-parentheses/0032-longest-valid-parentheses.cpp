class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return 0;
        vector<int> dp(n+1, 0);
        //if(s[0] == '(' && s[1] == ')') dp[2] = 2;
        for(int i=2;i<=n;i++) {
            if(s[i-1] == ')' && s[i-2] == '(') {
                dp[i] = dp[i-2] + 2;
            }
            else if (s[i-1] == ')' && s[i-2] == ')'){
                int match = i - dp[i-1] - 2;
                if(match >= 0 && s[match] == '(') {
                    dp[i] = dp[i-1] + 2;
                    if(match > 0) {
                        dp[i] += dp[match];
                    }
                }
            }
        }
        int ans = 0;
        for(int x : dp) {
            ans = max(x, ans);
        }
        return ans;
    }
};