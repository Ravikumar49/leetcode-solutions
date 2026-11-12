class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for(int i=0;i<n;i++) {
            int j = i;
            while(j + 1 < n && nums[j + 1] > nums[j]) j++;
            len = max(len, j - i + 1);
        }
        for(int i=0;i<n;i++) {
            int j = i;
            while(j + 1 < n && nums[j + 1] < nums[j]) j++;
            len = max(len, j - i + 1);
        }
        return len;
    }
};