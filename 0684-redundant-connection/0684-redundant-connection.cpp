class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(parent[x] == x) return x;
        return find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) parent[b] = a;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for(int i=1;i<=n;i++) parent[i] = i;
        for(auto &e : edges) {
            int a = e[0];
            int b = e[1];
            if(find(a) == find(b)) return {a, b};
            unite(a, b);
        }
        return {};
    }
};