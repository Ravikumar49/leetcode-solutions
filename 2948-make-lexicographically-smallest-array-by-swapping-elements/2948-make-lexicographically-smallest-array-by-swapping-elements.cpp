class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) parent[b] = a;
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;
        vector<pair<int, int>> values;
        for(int i=0;i<n;i++) {
            values.push_back({nums[i], i});
        }
        sort(values.begin(), values.end());
        for(int i=1;i<n;i++) {
            if(values[i].first - values[i-1].first <= limit) unite(values[i].second, values[i-1].second);
        }
        unordered_map<int, vector<int>> groups;
        for(int i=0;i<n;i++) groups[find(i)].push_back(i);
        for(auto group : groups) {
            vector<int>& indices = group.second;
            vector<int> vals;
            for(int index : indices) {
                vals.push_back(nums[index]);
            }
            sort(indices.begin(), indices.end());
            sort(vals.begin(), vals.end());
            for(int i=0;i<indices.size();i++) nums[indices[i]] = vals[i];
        }
        return nums;
    }
};