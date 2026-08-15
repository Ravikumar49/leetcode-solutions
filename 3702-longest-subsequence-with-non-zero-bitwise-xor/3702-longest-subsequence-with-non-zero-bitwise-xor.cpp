class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool nonZero = nums[0] == 0 ? false : true;
        int ans = nums[0];
        for(int i=1;i<n;i++) {
            ans ^= nums[i];
            if(!nonZero && nums[i] != 0) nonZero = true;
        }
        if(ans == 0 && !nonZero) return 0;
        else if(ans == 0) return n-1;
        return n;
    }
};