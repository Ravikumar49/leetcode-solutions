class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return min(nums[0], nums[1]);
        vector<int> newArray(n/2);
        for(int i=0;i<n/2;i++) {
            if(i%2 == 0) newArray[i] = min(nums[2 * i], nums[2 * i + 1]);
            else newArray[i] = max(nums[2 * i], nums[2 * i + 1]);
        }
        return minMaxGame(newArray);
    }
};