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
            if(i > index && nums[i] == nums[i-1]) continue;
            if(sum + nums[i] <= target) {
                curr.push_back(nums[i]);
                backtrack(nums, i+1, sum + nums[i], target, curr, res);
                curr.pop_back();
            }
            else {
                return;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(candidates, 0, 0, target, curr, res);
        return res;
    }
};