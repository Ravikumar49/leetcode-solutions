class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n-1;i++) {
            while(nums[i+1] - nums[i] > 1) {
                ans.push_back(nums[i] + 1);
                nums[i]++;
            }
        }
        return ans;
    }
};