class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(k, 0);
        vector<long long> result(k);
        for(int i=0;i<n;i++) {
            vector<long long> newDp(k);
            for(int r=0;r<k;r++) {
                long long newRemainder = (1LL * r * nums[i]) % k;
                newDp[newRemainder] += dp[r];
            }
            long long rem = nums[i] % k;
            newDp[rem] += 1;
            for(int r=0;r<k;r++) result[r] += newDp[r];
            dp = newDp;
        }
        return result;
    }
};