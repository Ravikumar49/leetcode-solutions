class Solution {
public:
    void createSubset(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& res) {
        if(index == nums.size()) {
            res.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        createSubset(nums, index+1, current, res);
        current.pop_back();
        createSubset(nums, index+1, current, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        createSubset(nums, 0, current, res);
        return res;
    }
};