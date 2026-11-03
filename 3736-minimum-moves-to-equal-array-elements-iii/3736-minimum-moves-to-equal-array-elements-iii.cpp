class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxNum = INT_MIN;
        for(int i=0;i<n;i++) maxNum = max(maxNum, nums[i]);
        int steps = 0;
        for(int i=0;i<n;i++) steps += maxNum - nums[i];
        return steps;
    }
};