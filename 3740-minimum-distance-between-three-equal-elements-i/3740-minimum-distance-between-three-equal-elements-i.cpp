class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i=0;i<n-2;i++) {
            int j = i+1;
            int k = n-1;
            while(j < n && nums[i] != nums[j]) j++;
            if(j == n) continue;
            while(j < k) {
                if(nums[j] == nums[k]) {
                    int curr = abs(i - j) + abs(j - k) + abs(k - i);
                    ans = min(ans, curr);
                }
                k--;
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};