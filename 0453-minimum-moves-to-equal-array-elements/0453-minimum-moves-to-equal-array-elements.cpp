class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int min_num = INT_MAX;
        for(int i=0;i<n;i++) min_num = min(nums[i], min_num);
        int steps = 0;
        for(int i=0;i<n;i++) steps += abs(min_num - nums[i]);
        return steps;
    }
};