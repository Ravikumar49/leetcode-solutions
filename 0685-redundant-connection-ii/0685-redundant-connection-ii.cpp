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
    bool DSU(vector<vector<int>>& edges, vector<int>& candidate2) {
        for(int i=1;i<=edges.size();i++) parent[i] = i;
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            if(u == candidate2[0] && v == candidate2[1]) continue;
            if(find(u) == find(v)) return false;
            unite(u, v);
        }
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> directParent(n + 1, 0);
        vector<int> candidate1;
        vector<int> candidate2;
        parent.resize(n+1);
        for(int i=1;i<=n;i++) directParent[i] = 0;
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            if(directParent[v] != 0) {
                candidate1 = {directParent[v], v};
                candidate2 = {u, v};
                if(DSU(edges, candidate2)) return candidate2;
                return candidate1;
            }
            else {
                directParent[v] = u;
            }
        }
        for(int i=1;i<=n;i++) parent[i] = i;
        for(auto e : edges) {
            int u = e[0];
            int v = e[1];
            if(find(u) == find(v)) return e;
            unite(u, v);
        }
        return {};
    }
};