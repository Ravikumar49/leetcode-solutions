class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        vector<int> gains;
        for(int i=0;i<n;i++) {
            string num = to_string(nums[i]);
            sort(num.rbegin(), num.rend());
            int best = stoi(num);

            ans += nums[i];
            gains.push_back(best - nums[i]);
        }
        sort(gains.rbegin(), gains.rend());
        for(int i=0;i<k;i++) ans += gains[i];

        return ans;
    }
};