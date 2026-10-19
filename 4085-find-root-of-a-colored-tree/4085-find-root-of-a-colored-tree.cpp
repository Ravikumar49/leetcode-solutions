class Solution {
public:
    bool bfs(vector<vector<int>>& adj, int root, string& colors) {
        queue<pair<int, int>> q;
        vector<bool> visited(adj.size(), false);
        q.push({0, root});
        visited[root] = true;
        int colorIndex = (colors[root] == 'R') ? 0 : (colors[root] == 'B') ? 1 : 2;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto [depth, curr] = q.front();
                int expected = (colorIndex + depth) % 3;
                int currColorIndex = (colors[curr] == 'R') ? 0 : (colors[curr] == 'B') ? 1 : 2;
                if(expected != currColorIndex) return false;
                q.pop();
                int neighbor = 0;
                for(auto node : adj[curr]) {
                    if(!visited[node]) {
                        visited[node] = true;
                        q.push({depth+1, node});
                        neighbor++;
                    }
                    if(neighbor > 2) return false;
                }
            }
        }
        return true;
    }
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            if(colors[u] == colors[v]) return -1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> candidate;
        for(int i=0;i<n;i++) {
            int degree = adj[i].size();
            if(degree < 3) candidate.push_back(i);
            if(degree > 3) return -1;
        }
        if(candidate.size() == 0) return -1;
        for(int i=0;i<candidate.size();i++) {
            if(bfs(adj, candidate[i], colors)) return candidate[i];
        }
        return -1;
    }
};