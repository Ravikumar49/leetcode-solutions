class Solution {
public:
    void backtrack(vector<int>& nums, int index, int sum, int target, vector<int>& curr, vector<vector<int>>& res) {
        if(sum > target) {
            return;
        }
        if(sum == target) {
            res.push_back(curr);
            return;
        }
        for(int i=index;i<nums.size();i++) {
            if(sum + nums[i] <= target) {
                curr.push_back(nums[i]);
                backtrack(nums, i, sum + nums[i], target, curr, res);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(candidates, 0, 0, target, curr, res);
        return res;
    }
};