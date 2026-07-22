class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        vector<int> component(n);
        int val = 0;
        component[0] = val;
        for(int i=1;i<n;i++) {
            if(abs(nums[i] - nums[i-1]) <= maxDiff) {
                component[i] = val;
            }
            else {
                val++;
                component[i] = val;
            }
        }
        for(int i=0;i<queries.size();i++) {
            ans[i] = component[queries[i][0]] == component[queries[i][1]];
        }
        return ans;
    }
};