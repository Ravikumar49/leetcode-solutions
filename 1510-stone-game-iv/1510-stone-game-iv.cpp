class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        dp[0] = false;
        for(int x=1;x<=n;x++) {
            for(int i=1;i*i<=x;i++) {
                if(!dp[x - i*i]) {
                    dp[x] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};