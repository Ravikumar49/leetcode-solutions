class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        vector<int> component(n);
        int val = 0;
        component[0] = 0;
        for(int i=1;i<n;i++) {
            if(abs(nums[i-1] - nums[i]) <= maxDiff) {
                component[i] = val;
            }
            else {
                val++;
                component[i] = val;
            }
        }
        for(int i=0;i<queries.size();i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i] = (component[u] == component[v]);
        }
        return ans;
    }
};