class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(k, 0));
        int rem = nums[0] % k;
        dp[0][rem] = 1;
        for(int i=1;i<n;i++) {
            for(int r=0;r<k;r++) {
                long long newRemainder = (1LL * r * nums[i]) % k;
                dp[i][newRemainder] += dp[i-1][r];
            }
            dp[i][nums[i] % k] += 1;
        }
        vector<long long> result(k, 0);
        for(int r=0;r<k;r++) {
            for(int i=0;i<n;i++) {
                result[r] += dp[i][r];
            }
        }
        return result;
    }
};