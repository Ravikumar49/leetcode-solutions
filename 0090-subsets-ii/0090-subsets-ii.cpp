class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& res) {
        if(index == nums.size()) {
            res.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        backtrack(nums, index+1, current, res);
        current.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index+1]) {
            index++;
        }
        backtrack(nums, index+1, current, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, current, res);
        return res;
    }
};