class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLength = 1;
        for(int i=0;i<n;i++) {
            dp[i][i] = true;
            start = i;
        }
        for(int i=1;i<n;i++) {
            if(s[i] == s[i-1]) {
                dp[i-1][i] = true;
                maxLength = 2;
                start = i-1;
            }
        }
        for(int len=3;len<=n;len++) {
            for(int left=0;left+len-1<=n;left++) {
                int right = left + len - 1;
                if(s[left] == s[right] && dp[left+1][right-1]) {
                    dp[left][right] = true;
                    if(len > maxLength) {
                        maxLength = len;
                        start = left;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};