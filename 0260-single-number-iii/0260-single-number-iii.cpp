class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for(int i=1;i<nums.size();i++) ans ^= nums[i];
        uint32_t x = ans;
        uint32_t separator = x & (-x);
        vector<int> groupA;
        vector<int> groupB;
        for(int i=0;i<nums.size();i++) {
            if((nums[i] & separator) == 0) groupA.push_back(nums[i]);
            else groupB.push_back(nums[i]);
        }
        int first = 0, second = 0;
        for(int x : groupA) first ^= x;
        for(int x : groupB) second ^= x;
        return {first, second};
    }
};