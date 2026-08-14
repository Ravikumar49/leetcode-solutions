class Solution {
public:
    void backtrack(vector<int>& nums, int index, int sum, int target, vector<bool>& visited, vector<int>& curr, vector<vector<int>>& res) {
        if(sum > target) {
            return;
        }
        if(sum == target) {
            res.push_back(curr);
            return;
        }
        for(int i=index;i<nums.size();i++) {
            if(i > index && nums[i] == nums[i-1]) continue;
            if(sum + nums[i] <= target && !visited[i]) {
                curr.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, i+1, sum + nums[i], target, visited, curr, res);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> visited(candidates.size(), false);
        backtrack(candidates, 0, 0, target, visited, curr, res);
        return res;
    }
};