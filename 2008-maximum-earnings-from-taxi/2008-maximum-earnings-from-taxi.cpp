class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int, long long>>> rideStartingAt(n + 1);
        for(auto &x : rides) {
            int start = x[0];
            int end = x[1];
            int tip = x[2];
            rideStartingAt[start].push_back({end, end - start + tip});
        }
        vector<long long> dp(n + 1, 0);
        dp[1] = 0;
        for(int i=1;i<rideStartingAt.size();i++) {
            dp[i] = max(dp[i], dp[i-1]);
            for(auto [end, profit] : rideStartingAt[i]) {
                dp[end] = max(dp[end], dp[i] + profit);
            }
        }
        return dp[n];
    }
};