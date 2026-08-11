class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int sum = nums[0];
        while(r + 1 < n && nums[r+1] == nums[r] + 1) {
            sum += nums[r + 1];
            r++;
        }
        unordered_set<int> values(nums.begin(), nums.end());
        while(values.count(sum)) sum++;
        return sum;
    }
};