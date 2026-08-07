class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> copy;
        for(int i=0;i<n;i++) {
            if(!copy.count(nums[i])) copy.insert(nums[i]);
            else return nums[i];
        }
        return 0;
    }
};