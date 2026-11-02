class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int target = nums[n/2];
        int steps = 0;
        for(int i=0;i<n;i++) steps += abs(target - nums[i]);
        return steps;
    }
};