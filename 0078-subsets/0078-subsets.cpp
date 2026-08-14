class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& res) {
        if(i == nums.size()) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        backtrack(nums, i+1, curr, res);
        curr.pop_back();
        backtrack(nums, i+1, curr, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(nums, 0, curr, res);
        return res;
    }
};