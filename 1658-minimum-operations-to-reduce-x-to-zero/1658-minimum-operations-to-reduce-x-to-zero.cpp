class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0, target;
        for(auto x:nums) {
            total += x;
        }
        target = total - x;
        int j=0, len = -1;
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            sum += nums[i];
            while(sum > target && j <= i) {
                sum -= nums[j];
                j++;
            }
            if(sum == target) {
                len = max(len, i - j + 1);
            }
        }
        if(len == -1) {
            return len;
        }
        return n - len;
    }
};