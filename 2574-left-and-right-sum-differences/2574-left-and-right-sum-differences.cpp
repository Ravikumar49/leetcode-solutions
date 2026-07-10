class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto &x : nums) {
            sum += x;
        }
        vector<int> ans(n);
        int val = 0;
        for(int i=0;i<n;i++) {
            val += nums[i];
            ans[i] = abs(sum - val);
            sum -= nums[i];
        }
        return ans;
    }
};