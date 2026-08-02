class Solution {
public:
    long long rec(long long n, unordered_map<long long, int>& dp) {
        if(n == 1) return 0;
        if(dp.find(n) != dp.end()) return dp[n];
        int steps;
        if(n%2 == 0) steps = 1 + rec(n/2, dp);
        else {
            steps = 1 + min(rec(n-1, dp), rec(n+1, dp));
        }
        return dp[n] = steps;
    }
    int integerReplacement(int n) {
        unordered_map<long long, int> dp;
        return rec(n, dp);
    }
};