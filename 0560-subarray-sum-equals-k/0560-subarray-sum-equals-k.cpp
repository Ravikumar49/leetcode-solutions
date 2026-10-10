class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currSum = 0;
        for(int i=0;i<n;i++) {
            currSum += nums[i];
            int needed = currSum - k;
            if(mp.count(needed)) count += mp[needed];
            mp[currSum]++;
        }
        return count;
    }
};