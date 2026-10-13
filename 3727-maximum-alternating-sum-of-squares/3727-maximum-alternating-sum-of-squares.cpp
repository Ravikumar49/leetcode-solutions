class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) nums[i] = nums[i] * nums[i];
        sort(nums.begin(), nums.end());
        long long neg = 0;
        int index = 0;
        while(index < n/2) {
            neg += nums[index];
            index++;
        }
        long long pos = 0;
        while(index < n) {
            pos += nums[index];
            index++;
        }
        return pos - neg;
    }
};