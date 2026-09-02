class Solution {
public:
    int robRec(vector<int>& nums, int i, vector<int>& dp) {
        int n = nums.size();
        if(i >= n) return 0;
        if(i == n-1) return nums[n-1];
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(robRec(nums, i+1, dp), nums[i] + robRec(nums, i+2, dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return robRec(nums, 0, dp);
    }
};