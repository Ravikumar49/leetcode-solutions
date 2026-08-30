class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;
        int minElement = INT_MAX, maxElement = INT_MIN;
        int minIndex, maxIndex;
        for(int i=0;i<n;i++) {
            if(nums[i] < minElement) {
                minElement = nums[i];
                minIndex = i;
            }
            if(nums[i] > maxElement) {
                maxElement = nums[i];
                maxIndex = i;
            }
        }
        int i = min(minIndex, maxIndex);
        int j = max(minIndex, maxIndex);
        return min({j+1, n-i, i + 1 + n - j});
    }
};