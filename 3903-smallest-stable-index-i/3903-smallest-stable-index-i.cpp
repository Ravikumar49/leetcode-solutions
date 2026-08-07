class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minArray(n);
        vector<int> maxArray(n);
        int maxVal = nums[0];
        for(int i=0;i<n;i++) {
            maxArray[i] = max(maxVal, nums[i]);
            maxVal = max(maxVal, maxArray[i]);
        }
        int minVal = nums[n-1];
        for(int i=n-1;i>=0;i--) {
            minArray[i] = min(minVal, nums[i]);
            minVal = min(minVal, minArray[i]);
        }
        for(int i=0;i<n;i++) {
            if(maxArray[i] - minArray[i] <= k) return i;
        }
        return -1;
    }
};