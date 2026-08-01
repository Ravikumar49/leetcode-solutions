class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthestReachable = 0;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(i > farthestReachable) return false;
            farthestReachable = max(farthestReachable, i + nums[i]);
            if(farthestReachable >= n-1) return true;
        }
        return true;
    }
};