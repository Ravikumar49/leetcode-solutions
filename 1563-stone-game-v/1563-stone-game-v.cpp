class Solution {
public:
    vector<vector<int>> dp;
    int dfs(const vector<int>& nums, int l, int r) {
        if(l == r) return 0;
        if(dp[l][r]) return dp[l][r];
        int sum = accumulate(nums.begin() + l, nums.begin() + r + 1, 0);
        int suml = 0;
        for(int i=l;i<r;i++) {
            suml += nums[i];
            int sumr = sum - suml;
            if(suml < sumr) {
                dp[l][r] = max(dp[l][r], dfs(nums, l, i) + suml);
            }
            else if(suml > sumr) {
                dp[l][r] = max(dp[l][r], dfs(nums, i+1, r) + sumr);
            }
            else {
                dp[l][r] = max(dp[l][r], max(dfs(nums, l, i), dfs(nums, i+1, r)) + suml);
            }
        }
        return dp[l][r];
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, vector<int>(n));
        return dfs(stoneValue, 0, n-1);
    }
};