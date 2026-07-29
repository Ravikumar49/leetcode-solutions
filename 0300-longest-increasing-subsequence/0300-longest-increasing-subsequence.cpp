class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(1 + dp[j], dp[i]);
                }
            }
        }
        int ans = -1;
        for(int x : dp) {
            ans = max(x, ans);
        }
        return ans;
    }
};