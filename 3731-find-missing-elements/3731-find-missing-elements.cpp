class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int min = ranges::min(nums);
        int max = ranges::max(nums);
        vector<int> ans;
        for(int i=min+1;i<max;i++) {
            if(!st.contains(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};