class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return false;
        sort(nums.begin(), nums.end());
        if(nums[0] != 1) return false;
        if(nums[n-1] != nums[n-2]) return false;
        int duplicate = 0;
        for(int i=1;i<n;i++) {
            if(nums[i] == nums[i-1]) duplicate += 2;
            if(i <= n-2 && nums[i] != nums[i-1] + 1) return false;
        }
        return duplicate == 2;
    }
};