class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<bool>& visited, vector<int>& curr, vector<vector<int>>& res) {
        if(index == nums.size()) {
            res.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++) {
            if(!visited[i]) {
                curr.push_back(nums[i]);
                visited[i] = true;
                backtrack(nums, index+1, visited, curr, res);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, 0, visited, curr, res);
        return res;
    }
};