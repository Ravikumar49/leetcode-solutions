class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        if(nums[start] == target) return 0;
        int diff = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == target) diff = min(diff, abs(start - i));
        }
        return diff;
    }
};